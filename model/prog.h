// Shared helpers for the C++ reference model and the Verilator testbench.
// .prog format (written by tools/asm.py):
//   I <hex16>              instruction word, in order from address 0
//   D <addr> <v> <v> ...   initial scratchpad data
//   E <addr> <v> <v> ...   expected scratchpad contents after the run
#pragma once
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

static const int NLANES = 2;
static const int IMEM_WORDS = 16;
static const int SCR_BYTES = 32;

struct Prog {
    uint16_t imem[IMEM_WORDS] = {0};
    int nwords = 0;
    std::vector<std::pair<int, std::vector<int>>> data, expect;
};

struct Result {
    uint8_t scr[SCR_BYTES] = {0};
    uint16_t cycles = 0, instr = 0, lane_ops = 0, conflicts = 0;
};

inline bool load_prog(const char* path, Prog& p) {
    std::ifstream f(path);
    if (!f) { std::fprintf(stderr, "cannot open %s\n", path); return false; }
    std::string line;
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string tag;
        if (!(ss >> tag)) continue;
        if (tag == "I") {
            std::string h; ss >> h;
            if (p.nwords >= IMEM_WORDS) { std::fprintf(stderr, "program too long\n"); return false; }
            p.imem[p.nwords++] = (uint16_t)std::strtoul(h.c_str(), nullptr, 16);
        } else if (tag == "D" || tag == "E") {
            int addr; ss >> addr;
            std::vector<int> v; int x;
            while (ss >> x) v.push_back(x);
            (tag == "D" ? p.data : p.expect).push_back({addr, v});
        }
    }
    return true;
}

// Prints the canonical result block; returns 0 when every expected byte matches.
inline int report(const Prog& p, const Result& r) {
    std::printf("SCR");
    for (int i = 0; i < SCR_BYTES; i++) std::printf(" %02x", r.scr[i]);
    std::printf("\nCNT cycles=%u instr=%u lane_ops=%u conflicts=%u\n",
                r.cycles, r.instr, r.lane_ops, r.conflicts);
    int bad = 0;
    for (auto& e : p.expect)
        for (size_t i = 0; i < e.second.size(); i++) {
            int a = e.first + (int)i;
            if (a >= SCR_BYTES || r.scr[a] != (uint8_t)(e.second[i] & 0xFF)) bad++;
        }
    std::printf("CHECK %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
