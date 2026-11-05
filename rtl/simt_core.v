// shrike-simt: tiny SIMT compute core.
//  - NL lanes, 8-bit datapath, 8 registers per lane (r0 is cleared at start, never written by kernels)
//  - one instruction per cycle; LD/ST take extra cycles on scratchpad bank conflicts
//  - 2-bank scratchpad, bank = addr[0]; same-address loads in one bank are broadcast (no conflict)
//  - per-lane active mask with 1-deep IF/ELSE/ENDIF stack, 1-deep hardware LOOP
//  - hardware performance counters: cycles, instructions, active lane-ops, bank conflicts
//
// Instruction word (16 bit): op[15:11] rd[10:8] rs1[7:5] low5[4:0]
//   low5 = {rs2[2:0], 2'b00} for register ops, or imm5.
module simt_core #(
    parameter NL = 2,      // lanes
    parameter IA = 4,      // instruction memory address bits (16 words)
    parameter SA = 5       // scratchpad address bits (32 bytes)
) (
    input  wire          clk,
    input  wire          rst,
    input  wire          start,
    output reg           busy,
    output reg           done,
    // host write port for instruction memory: {word index, byte select (0 = low, 1 = high)}
    input  wire          imem_we,
    input  wire [IA:0]   imem_waddr,
    input  wire [7:0]    imem_wdata,
    // host port for scratchpad (writes only honoured while idle)
    input  wire          hs_we,
    input  wire [SA-1:0] hs_addr,
    input  wire [7:0]    hs_wdata,
    output wire [7:0]    hs_rdata,
    // performance counters
    output reg  [15:0]   cnt_cycles,
    output reg  [15:0]   cnt_instr,
    output reg  [15:0]   cnt_lane_ops,
    output reg  [15:0]   cnt_conflicts
);
    localparam [4:0] OP_NOP   = 5'd0,  OP_ADD  = 5'd1,  OP_SUB  = 5'd2,  OP_MUL  = 5'd3,
                     OP_MAC   = 5'd4,  OP_ADDI = 5'd5,  OP_MOVI = 5'd6,  OP_TID  = 5'd7,
                     OP_LD    = 5'd8,  OP_ST   = 5'd9,  OP_SLT  = 5'd10, OP_SEQ  = 5'd11,
                     OP_IF    = 5'd12, OP_ELSE = 5'd13, OP_ENDIF= 5'd14, OP_LOOP = 5'd15,
                     OP_ENDLP = 5'd16, OP_END  = 5'd17, OP_SHRI = 5'd18, OP_RELU = 5'd19;

    reg [7:0] imem_lo [0:(1<<IA)-1];
    reg [7:0] imem_hi [0:(1<<IA)-1];
    reg [7:0] scr     [0:(1<<SA)-1];
    reg [7:0] rf      [0:NL*8-1];

    reg [IA-1:0] pc;
    reg [IA-1:0] loop_pc;
    reg [4:0]    loop_cnt;
    reg [NL-1:0] mask, smask, pred, pend;
    reg          pend_v;

    wire [15:0] ins  = {imem_hi[pc], imem_lo[pc]};
    wire [4:0]  op   = ins[15:11];
    wire [2:0]  rd   = ins[10:8];
    wire [2:0]  rs1  = ins[7:5];
    wire [2:0]  rs2  = ins[4:2];
    wire [4:0]  imm5 = ins[4:0];
    wire [7:0]  simm = {{3{imm5[4]}}, imm5};

    assign hs_rdata = scr[hs_addr];

    integer      l, pop;
    reg [7:0]    a, b, d, res, ad8;
    reg [15:0]   prod;
    reg [SA-1:0] ad, ba0, ba1;
    reg          bt0, bt1, bk, served, complete;
    reg [NL-1:0] req, defer;
    reg [IA-1:0] next_pc;

    always @(posedge clk) begin
        if (imem_we) begin
            if (imem_waddr[0]) imem_hi[imem_waddr[IA:1]] <= imem_wdata;
            else               imem_lo[imem_waddr[IA:1]] <= imem_wdata;
        end
        if (hs_we && !busy) scr[hs_addr] <= hs_wdata;

        if (rst) begin
            busy <= 1'b0;  done <= 1'b0;
            pc <= {IA{1'b0}};  loop_pc <= {IA{1'b0}};  loop_cnt <= 5'd0;
            mask <= {NL{1'b1}};  smask <= {NL{1'b1}};  pred <= {NL{1'b0}};
            pend <= {NL{1'b0}};  pend_v <= 1'b0;
            cnt_cycles <= 16'd0;  cnt_instr <= 16'd0;
            cnt_lane_ops <= 16'd0;  cnt_conflicts <= 16'd0;
        end else if (start && !busy) begin
            busy <= 1'b1;  done <= 1'b0;
            pc <= {IA{1'b0}};  loop_pc <= {IA{1'b0}};  loop_cnt <= 5'd0;
            mask <= {NL{1'b1}};  smask <= {NL{1'b1}};  pred <= {NL{1'b0}};
            pend <= {NL{1'b0}};  pend_v <= 1'b0;
            cnt_cycles <= 16'd0;  cnt_instr <= 16'd0;
            cnt_lane_ops <= 16'd0;  cnt_conflicts <= 16'd0;
            for (l = 0; l < NL*8; l = l + 1) rf[l] <= 8'd0;
        end else if (busy) begin
            cnt_cycles <= cnt_cycles + 16'd1;
            if (cnt_cycles == 16'hFFFE) begin busy <= 1'b0; done <= 1'b1; end  // watchdog

            complete = 1'b1;
            next_pc  = pc + 1'b1;
            req      = pend_v ? pend : mask;
            pop = 0;
            for (l = 0; l < NL; l = l + 1) if (mask[l]) pop = pop + 1;

            case (op)
                OP_ADD, OP_SUB, OP_MUL, OP_MAC, OP_ADDI, OP_MOVI, OP_TID, OP_SHRI, OP_RELU: begin
                    for (l = 0; l < NL; l = l + 1) begin
                        if (mask[l]) begin
                            a = rf[l*8+rs1];
                            b = rf[l*8+rs2];
                            d = rf[l*8+rd];
                            prod = a * b;
                            res = 8'd0;
                            case (op)
                                OP_ADD:  res = a + b;
                                OP_SUB:  res = a - b;
                                OP_MUL:  res = prod[7:0];
                                OP_MAC:  res = d + prod[7:0];
                                OP_ADDI: res = a + simm;
                                OP_MOVI: res = simm;
                                OP_TID:  res = l[7:0];
                                OP_SHRI: res = a >> imm5[2:0];
                                default: res = a[7] ? 8'd0 : a;   // RELU (signed)
                            endcase
                            rf[l*8+rd] <= res;
                        end
                    end
                end

                OP_SLT, OP_SEQ: begin
                    for (l = 0; l < NL; l = l + 1) begin
                        if (mask[l]) begin
                            a = rf[l*8+rs1];
                            b = rf[l*8+rs2];
                            pred[l] <= (op == OP_SLT) ? (a < b) : (a == b);
                        end
                    end
                end

                OP_IF:    begin smask <= mask; mask <= mask & pred; end
                OP_ELSE:  mask <= smask & ~pred;
                OP_ENDIF: mask <= smask;

                OP_LOOP:  begin loop_cnt <= imm5; loop_pc <= pc + 1'b1; end
                OP_ENDLP: begin
                    if (loop_cnt > 5'd1) begin
                        loop_cnt <= loop_cnt - 5'd1;
                        next_pc = loop_pc;
                    end
                end

                OP_LD, OP_ST: begin
                    defer = {NL{1'b0}};
                    bt0 = 1'b0;  bt1 = 1'b0;
                    ba0 = {SA{1'b0}};  ba1 = {SA{1'b0}};
                    for (l = 0; l < NL; l = l + 1) begin
                        if (req[l]) begin
                            ad8 = rf[l*8+rs1] + {3'b000, imm5};
                            ad  = ad8[SA-1:0];
                            bk  = ad[0];
                            if (!bk) begin
                                if (!bt0) begin bt0 = 1'b1; ba0 = ad; served = 1'b1; end
                                else served = (op == OP_LD) && (ba0 == ad);
                            end else begin
                                if (!bt1) begin bt1 = 1'b1; ba1 = ad; served = 1'b1; end
                                else served = (op == OP_LD) && (ba1 == ad);
                            end
                            if (served) begin
                                if (op == OP_LD) rf[l*8+rd] <= scr[ad];
                                else             scr[ad]    <= rf[l*8+rd];
                            end else begin
                                defer[l] = 1'b1;
                            end
                        end
                    end
                    if (|defer) begin
                        pend <= defer;  pend_v <= 1'b1;
                        complete = 1'b0;
                        cnt_conflicts <= cnt_conflicts + 16'd1;
                    end else begin
                        pend_v <= 1'b0;
                    end
                end

                OP_END: begin busy <= 1'b0; done <= 1'b1; end

                default: ;   // NOP / undefined
            endcase

            if (complete) begin
                pc <= next_pc;
                if (op != OP_END) begin
                    cnt_instr    <= cnt_instr + 16'd1;
                    cnt_lane_ops <= cnt_lane_ops + pop[15:0];
                end
            end
        end
    end
endmodule
