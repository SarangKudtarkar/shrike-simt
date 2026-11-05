// Cycle-accurate reference model of the shrike-simt core (golden model).
// Mirrors rtl/simt_core.v: one instruction per cycle, extra cycles for scratchpad bank conflicts.
#include "prog.h"

enum { NOP, ADD, SUB, MUL, MAC, ADDI, MOVI, TID, LD, ST, SLT, SEQ,
       IF, ELSE, ENDIF, LOOP, ENDLP, END, SHRI, RELU };

struct Core {
    uint16_t imem[IMEM_WORDS];
    uint8_t scr[SCR_BYTES] = {0};
    uint8_t rf[NLANES][8] = {{0}};
    unsigned pc = 0, loop_pc = 0, loop_cnt = 0;
    unsigned mask = (1u << NLANES) - 1, smask = (1u << NLANES) - 1, pred = 0, pend = 0;
    bool pend_v = false, halted = false;
    Result r;

    bool step() {
        r.cycles++;
        uint16_t ins = imem[pc & (IMEM_WORDS - 1)];
        unsigned op = ins >> 11, rd = (ins >> 8) & 7, rs1 = (ins >> 5) & 7, rs2 = (ins >> 2) & 7;
        unsigned imm5 = ins & 31;
        uint8_t simm = (uint8_t)((imm5 & 16) ? (imm5 | 0xE0) : imm5);
        unsigned next_pc = (pc + 1) & (IMEM_WORDS - 1);
        bool complete = true;
        unsigned req = pend_v ? pend : mask;
        int pop = 0;
        for (int l = 0; l < NLANES; l++) pop += (mask >> l) & 1;

        switch (op) {
        case ADD: case SUB: case MUL: case MAC: case ADDI: case MOVI: case TID: case SHRI: case RELU:
            for (int l = 0; l < NLANES; l++) if ((mask >> l) & 1) {
                uint8_t a = rf[l][rs1], b = rf[l][rs2], d = rf[l][rd], res = 0;
                uint8_t prod = (uint8_t)(a * b);
                switch (op) {
                case ADD:  res = a + b; break;
                case SUB:  res = a - b; break;
                case MUL:  res = prod; break;
                case MAC:  res = d + prod; break;
                case ADDI: res = a + simm; break;
                case MOVI: res = simm; break;
                case TID:  res = (uint8_t)l; break;
                case SHRI: res = a >> (imm5 & 7); break;
                default:   res = (a & 0x80) ? 0 : a; break;
                }
                rf[l][rd] = res;
            }
            break;
        case SLT: case SEQ:
            for (int l = 0; l < NLANES; l++) if ((mask >> l) & 1) {
                uint8_t a = rf[l][rs1], b = rf[l][rs2];
                bool v = (op == SLT) ? (a < b) : (a == b);
                pred = v ? (pred | (1u << l)) : (pred & ~(1u << l));
            }
            break;
        case IF:    smask = mask; mask = mask & pred; break;
        case ELSE:  mask = smask & ~pred; break;
        case ENDIF: mask = smask; break;
        case LOOP:  loop_cnt = imm5; loop_pc = (pc + 1) & (IMEM_WORDS - 1); break;
        case ENDLP:
            if (loop_cnt > 1) { loop_cnt--; next_pc = loop_pc; }
            break;
        case LD: case ST: {
            unsigned defer = 0;
            bool bt[2] = {false, false};
            unsigned ba[2] = {0, 0};
            uint8_t wb[NLANES] = {0};
            unsigned wa[NLANES] = {0};
            bool wr[NLANES] = {false};
            for (int l = 0; l < NLANES; l++) if ((req >> l) & 1) {
                unsigned ad = (uint8_t)(rf[l][rs1] + imm5) & (SCR_BYTES - 1);
                unsigned bk = ad & 1;
                bool served;
                if (!bt[bk]) { bt[bk] = true; ba[bk] = ad; served = true; }
                else served = (op == LD) && (ba[bk] == ad);
                if (served) {
                    if (op == LD) { wb[l] = scr[ad]; wa[l] = rd; wr[l] = true; }
                    else { scr[ad] = rf[l][rd]; }
                } else defer |= (1u << l);
            }
            for (int l = 0; l < NLANES; l++) if (wr[l]) rf[l][wa[l]] = wb[l];
            if (defer) { pend = defer; pend_v = true; complete = false; r.conflicts++; }
            else pend_v = false;
            break;
        }
        case END: halted = true; break;
        default: break;
        }

        if (complete) {
            pc = next_pc;
            if (op != END) { r.instr++; r.lane_ops += pop; }
        }
        return !halted;
    }
};

int main(int argc, char** argv) {
    if (argc < 2) { std::fprintf(stderr, "usage: %s prog\n", argv[0]); return 2; }
    Prog p;
    if (!load_prog(argv[1], p)) return 2;
    Core c;
    for (int i = 0; i < IMEM_WORDS; i++) c.imem[i] = p.imem[i];
    for (auto& d : p.data)
        for (size_t i = 0; i < d.second.size(); i++)
            if (d.first + (int)i < SCR_BYTES) c.scr[d.first + i] = (uint8_t)d.second[i];
    while (c.r.cycles < 65534 && c.step()) {}
    for (int i = 0; i < SCR_BYTES; i++) c.r.scr[i] = c.scr[i];
    return report(p, c.r);
}
