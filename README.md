# Shrike-SIMT: SIMT Processor on Vicharak Shrike-Lite FPGA

## Overview

Shrike-SIMT is a small Single Instruction, Multiple Thread (SIMT) processor implementation targeting the **Vicharak Shrike-Lite FPGA development board**, which combines an RP2040 microcontroller with a Renesas ForgeFPGA SLG47910 FPGA.

The project explores FPGA-based parallel processing, RTL design, hardware-software interfacing, and embedded-system deployment.

The RTL is designed to execute programs assembled into `.prog` files. The RP2040 acts as the host controller, programs the FPGA, communicates with it over SPI, and runs the test suite.

> **Current implementation:** A one-lane configuration is being used to fit the SLG47910 resource constraints. FPGA synthesis, placement and routing, and bitstream generation have completed. SPI communication and hardware-level test execution are still being validated.

## Hardware and Software

### Hardware

- Vicharak Shrike-Lite development board
- Renesas ForgeFPGA SLG47910 (Rev BB)
- Raspberry Pi RP2040 microcontroller
- SPI communication interface

### Software and tools

- Verilog HDL
- Renesas ForgeFPGA Workshop
- Python 3
- MicroPython
- `mpremote` for RP2040 communication
- WSL Ubuntu development environment

## Repository Structure

```text
shrike-simt/
├── rtl/
│   ├── simt_core.v
│   └── shrike_top.v
├── host/
│   └── board_run.py
├── tools/
│   ├── asm.py
│   └── regress.sh
├── *.prog
└── README.md
```

- `simt_core.v`: SIMT processor RTL.
- `shrike_top.v`: FPGA top-level module and hardware interface.
- `asm.py`: Assembler used to convert assembly programs into `.prog` files.
- `regress.sh`: Host-side regression workflow.
- `board_run.py`: MicroPython board runner for FPGA programming, SPI communication, and test execution.
- `.prog` files: Assembled test programs.

## Development Workflow

The project follows this workflow:

1. Develop and modify the Verilog RTL.
2. Assemble test programs into `.prog` files.
3. Run host-side regression checks.
4. Synthesize the RTL in ForgeFPGA Workshop.
5. Perform placement and routing.
6. Generate the FPGA bitstream.
7. Transfer the bitstream and test programs to the RP2040.
8. Program the FPGA and execute the hardware tests.
9. Inspect test results and performance counters.

## 1. Set Up the Development Environment

Open WSL Ubuntu and navigate to the project:

```bash
cd ~/embedded_projects/shrike-simt
```

Check the available project files:

```bash
ls
```

The RTL and development tools are maintained in the `rtl/` and `tools/` directories.

## 2. Assemble SIMT Programs

The assembler is located at:

```text
tools/asm.py
```

Use it to convert supported assembly input into `.prog` files.

To inspect the available assembler arguments:

```bash
python3 tools/asm.py --help
```

The generated `.prog` files are used by the board execution script.

## 3. Run Host-Side Regression Tests

The regression script is:

```bash
tools/regress.sh
```

Run it from the repository root:

```bash
chmod +x tools/regress.sh
./tools/regress.sh
```

This is the host-side validation stage. It should be completed before deploying a new RTL build to the FPGA.

## 4. Synthesize and Generate the FPGA Bitstream

Open the project in **Renesas ForgeFPGA Workshop** and select the SLG47910 device (Rev BB).

The main RTL modules are:

```text
rtl/simt_core.v
rtl/shrike_top.v
```

The build process consists of:

1. Importing or updating the RTL modules.
2. Selecting `shrike_top` as the top-level module.
3. Running synthesis.
4. Checking logic resource utilization.
5. Running placement and routing.
6. Generating the FPGA bitstream.

### Resource optimization

The original
