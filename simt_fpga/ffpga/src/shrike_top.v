(* top *)
// shrike-simt top level for the Shrike-Lite (SLG47910 FPGA).
// The RP2040 talks to the core over SPI mode 0 on the FPGA pins that were used for configuration:
//   SCLK <- RP2040 GP2, SS_N <- RP2040 GP1, MOSI <- RP2040 GP3, MISO -> RP2040 GP0
// Port names follow the Go Configure convention: every driven pin has a matching *_en output.
//
// SPI frame:  byte0 = {rw(1=write), addr[6:0]}, then data bytes (address auto-increments).
//   0x00 CTRL    (w)  bit0 = start
//   0x01 STATUS  (r)  bit0 = done, bit1 = busy
//   0x02 ID      (r)  0xA5
//   0x08..0x0F   (r)  counters, little endian: cycles, instr, lane_ops, conflicts
//   0x20..0x3F   (w)  instruction memory bytes (word i = bytes 0x20+2i (lo), 0x21+2i (hi))
//   0x40..0x5F   (rw) scratchpad (write only while idle)
module shrike_top (
    input  wire clk,
    output wire clk_en,
    input  wire sclk,
    input  wire ss_n,
    input  wire mosi,
    output wire miso,
    output wire miso_en,
    output wire led,
    output wire led_en
);
    assign clk_en  = 1'b1;
    assign miso_en = 1'b1;
    assign led_en  = 1'b1;

    // power-on reset
    reg [3:0] rst_sr;
    initial rst_sr = 4'hF;
    always @(posedge clk) rst_sr <= {rst_sr[2:0], 1'b0};
    wire rst = rst_sr[3];

    // input synchronisers
    reg [2:0] sclk_s;
    reg [1:0] ss_s, mosi_s;
    initial begin sclk_s = 3'b000; ss_s = 2'b11; mosi_s = 2'b00; end
    always @(posedge clk) begin
        sclk_s <= {sclk_s[1:0], sclk};
        ss_s   <= {ss_s[0], ss_n};
        mosi_s <= {mosi_s[0], mosi};
    end
    wire sclk_rise  = (sclk_s[2:1] == 2'b01);
    wire sclk_fall  = (sclk_s[2:1] == 2'b10);
    wire ss_active  = ~ss_s[1];
    wire mosi_v     = mosi_s[1];

    // core
    reg        start_q, imem_we, hs_we;
    reg [4:0]  imem_wa, hs_wa;
    reg [7:0]  imem_wd, hs_wd;
    reg [6:0]  addr;
    wire [4:0] hs_addr = hs_we ? hs_wa : addr[4:0];
    wire [7:0] hs_rdata;
    wire       busy, done;
    wire [15:0] cyc, ins_c, lops, conf;

    simt_core #(.NL(1), .IA(4), .SA(5)) core (
        .clk(clk), .rst(rst), .start(start_q), .busy(busy), .done(done),
        .imem_we(imem_we), .imem_waddr(imem_wa), .imem_wdata(imem_wd),
        .hs_we(hs_we), .hs_addr(hs_addr), .hs_wdata(hs_wd), .hs_rdata(hs_rdata),
        .cnt_cycles(cyc), .cnt_instr(ins_c), .cnt_lane_ops(lops), .cnt_conflicts(conf)
    );

    // read mux
    reg [7:0] rdata;
    always @* begin
        rdata = 8'h00;
        case (addr)
            7'h01: rdata = {6'b000000, busy, done};
            7'h02: rdata = 8'hA5;
            7'h08: rdata = cyc[7:0];    7'h09: rdata = cyc[15:8];
            7'h0A: rdata = ins_c[7:0];  7'h0B: rdata = ins_c[15:8];
            7'h0C: rdata = lops[7:0];   7'h0D: rdata = lops[15:8];
            7'h0E: rdata = conf[7:0];   7'h0F: rdata = conf[15:8];
            default: if (addr[6:5] == 2'b10) rdata = hs_rdata;
        endcase
    end

    // SPI slave
    reg [2:0] bitcnt;
    reg [7:0] rxsh, rx_byte, tx;
    reg       byte_done, first, rw_wr, ld_tx;
    initial begin bitcnt = 0; first = 1; tx = 0; byte_done = 0; ld_tx = 0; rw_wr = 0; addr = 0; end

    assign miso = tx[7];
    assign led  = done;

    always @(posedge clk) begin
        byte_done <= 1'b0;
        start_q   <= 1'b0;
        imem_we   <= 1'b0;
        hs_we     <= 1'b0;
        if (!ss_active) begin
            bitcnt <= 3'd0;  first <= 1'b1;  tx <= 8'd0;  ld_tx <= 1'b0;
        end else begin
            if (sclk_rise) begin
                rxsh   <= {rxsh[6:0], mosi_v};
                bitcnt <= bitcnt + 3'd1;
                if (bitcnt == 3'd7) begin
                    byte_done <= 1'b1;
                    rx_byte   <= {rxsh[6:0], mosi_v};
                end
            end
            // shift out on falling edges, except the one that follows the 8th bit
            if (sclk_fall && bitcnt != 3'd0) tx <= {tx[6:0], 1'b0};

            if (byte_done) begin
                if (first) begin
                    first   <= 1'b0;
                    rw_wr   <= rx_byte[7];
                    addr    <= rx_byte[6:0];
                    if (!rx_byte[7]) ld_tx <= 1'b1;
                end else begin
                    if (rw_wr) begin
                        case (addr[6:5])
                            2'b00: if (addr[4:0] == 5'h00 && rx_byte[0]) start_q <= 1'b1;
                            2'b01: begin imem_we <= 1'b1; imem_wa <= addr[4:0]; imem_wd <= rx_byte; end
                            2'b10: begin hs_we   <= 1'b1; hs_wa   <= addr[4:0]; hs_wd   <= rx_byte; end
                            default: ;
                        endcase
                    end else begin
                        ld_tx <= 1'b1;
                    end
                    addr <= addr + 7'd1;
                end
            end
            if (ld_tx) begin tx <= rdata; ld_tx <= 1'b0; end
        end
    end
endmodule