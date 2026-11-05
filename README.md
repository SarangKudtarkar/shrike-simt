# shrike-simt

A toy SIMT compute core (2 lanes, 8-bit, custom 20-op ISA) for the Shrike-Lite (RP2040 + SLG47910 FPGA).
The RP2040 is the host CPU; the FPGA is the accelerator. A cycle-accurate C++ model is the golden reference.

## Layout
- `rtl/`     Verilog: `simt_core.v` (core), `shrike_top.v` (SPI slave + register map, Go Configure top level)
- `model/`   C++ reference model (`simt_model.cpp`) and shared `.prog` parser
- `tb/`      Verilator testbench that drives the design over SPI exactly like the RP2040
- `tools/`   `asm.py` assembler, `regress.sh` (model vs RTL vs expected + perf table), `estimate.sh`
- `kernels/` vecadd, dot, matvec_relu, matvec_padded, diverge, conflict
- `host/`    `board_run.py` (MicroPython, runs on the RP2040)

## Simulate (laptop)
    sudo apt install verilator g++ python3      # or: pip install verilator
    ./tools/regress.sh

## Run on the board
1. Go Configure Software Hub: new project, add `rtl/simt_core.v` and `rtl/shrike_top.v`, top module `shrike_top`.
2. I/O Planner: clk -> internal oscillator, sclk/ss_n/mosi/miso -> FPGA pins 3/4/5/6, led -> FPGA GPIO 16
   (match the port/enable naming of Vicharak's blink example). Synthesize, check LUT/FF report, generate the bitstream.
3. Copy the bitstream to the repo as `shrike_simt.bin`, then:

       python3 tools/asm.py kernels/vecadd.s -o build/vecadd.prog      # repeat per kernel, or use build/ from regress.sh
       pip install mpremote
       mpremote cp shrike_simt.bin :
       mpremote cp build/*.prog :
       mpremote run host/board_run.py

## SPI map
byte0 = {rw, addr[6:0]}, address auto-increments. 0x00 CTRL(start) | 0x01 STATUS | 0x02 ID(0xA5) | 0x08-0x0F counters |
0x20-0x3F instruction memory | 0x40-0x5F scratchpad.
