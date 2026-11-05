// Verilator testbench: drives the whole design through the same SPI protocol the RP2040 uses.
#include "Vshrike_top.h"
#include "verilated.h"
#include "prog.h"
#include <vector>

static Vshrike_top* dut;
static const int H = 12;  // FPGA clocks per SCLK half period

static void tick(int n = 1) {
    while (n--) { dut->clk = 0; dut->eval(); dut->clk = 1; dut->eval(); }
}

static uint8_t spi_byte(uint8_t tx) {
    uint8_t rx = 0;
    for (int i = 7; i >= 0; i--) {
        dut->mosi = (tx >> i) & 1;
        tick(H);
        rx = (uint8_t)((rx << 1) | (dut->miso & 1));
        dut->sclk = 1; tick(H);
        dut->sclk = 0;
    }
    return rx;
}

static void write_burst(uint8_t addr, const std::vector<uint8_t>& v) {
    dut->ss_n = 0; tick(H);
    spi_byte(0x80 | addr);
    for (uint8_t b : v) spi_byte(b);
    tick(H); dut->ss_n = 1; tick(H);
}

static std::vector<uint8_t> read_burst(uint8_t addr, int n) {
    std::vector<uint8_t> out;
    dut->ss_n = 0; tick(H);
    spi_byte(addr & 0x7F);
    for (int i = 0; i < n; i++) out.push_back(spi_byte(0));
    tick(H); dut->ss_n = 1; tick(H);
    return out;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    if (argc < 2) { std::fprintf(stderr, "usage: %s prog\n", argv[0]); return 2; }
    Prog p;
    if (!load_prog(argv[1], p)) return 2;

    dut = new Vshrike_top;
    dut->ss_n = 1; dut->sclk = 0; dut->mosi = 0;
    tick(20);

    auto id = read_burst(0x02, 1);
    if (id[0] != 0xA5) { std::printf("ID mismatch: %02x\n", id[0]); return 3; }

    // instruction memory (little endian words)
    std::vector<uint8_t> code;
    for (int i = 0; i < p.nwords; i++) { code.push_back(p.imem[i] & 0xFF); code.push_back(p.imem[i] >> 8); }
    write_burst(0x20, code);

    // scratchpad: clear, then load data
    write_burst(0x40, std::vector<uint8_t>(SCR_BYTES, 0));
    for (auto& d : p.data) {
        std::vector<uint8_t> v;
        for (int x : d.second) v.push_back((uint8_t)x);
        write_burst(0x40 + d.first, v);
    }

    write_burst(0x00, {0x01});  // start
    bool finished = false;
    for (int i = 0; i < 4000 && !finished; i++) finished = read_burst(0x01, 1)[0] & 1;
    if (!finished) { std::printf("TIMEOUT\n"); return 4; }

    auto c = read_burst(0x08, 8);
    Result r;
    r.cycles    = c[0] | (c[1] << 8);
    r.instr     = c[2] | (c[3] << 8);
    r.lane_ops  = c[4] | (c[5] << 8);
    r.conflicts = c[6] | (c[7] << 8);
    auto s = read_burst(0x40, SCR_BYTES);
    for (int i = 0; i < SCR_BYTES; i++) r.scr[i] = s[i];

    int rc = report(p, r);
    delete dut;
    return rc;
}
