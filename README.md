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

The original two-lane configuration exceeded the available FPGA logic resources and could not be placed successfully.

A one-lane configuration was therefore used for the initial hardware implementation.

Reported one-lane resource utilization:

| Resource | Used | Available | Utilization |
|---|---:|---:|---:|
| CLB LUT5s | 678 | 1120 | 60.54% |
| CLB FFs | 204 | 1120 | 18.21% |
| IOB FFs | 5 | 736 | 0.68% |
| CLBs | 118 | 140 | 84.29% |
| BRAMs | 2 | 8 | 25% |

Placement and routing completed successfully for this configuration.

The generated bitstream is:

```text
FPGA_bitstream.bin
```

Copy it into the repository and rename it for the board runner:

```text
shrike_simt.bin
```

The board runner expects this exact filename.

## 5. Connect to the Shrike-Lite Board

On Windows PowerShell, check that the RP2040 is detected:

```powershell
py -m mpremote devs
```

Check the MicroPython implementation:

```powershell
py -m mpremote connect COM3 exec "import sys; print(sys.implementation)"
```

Verify that the Shrike board module is available:

```powershell
py -m mpremote connect COM3 exec "import shrike; print('shrike OK')"
```

Replace `COM3` with the detected serial port if necessary.

## 6. Upload the FPGA Bitstream

From the project directory in PowerShell:

```powershell
py -m mpremote connect COM3 fs cp .\shrike_simt.bin :shrike_simt.bin
```

The bitstream is copied to the RP2040 filesystem.

## 7. Upload Test Programs

Upload the assembled programs to the board:

```powershell
py -m mpremote connect COM3 fs cp .\matvec_relu.prog :matvec_relu.prog
py -m mpremote connect COM3 fs cp .\vecadd.prog :vecadd.prog
py -m mpremote connect COM3 fs cp .\conflict.prog :conflict.prog
py -m mpremote connect COM3 fs cp .\diverge.prog :diverge.prog
py -m mpremote connect COM3 fs cp .\dot.prog :dot.prog
py -m mpremote connect COM3 fs cp .\matvec_padded.prog :matvec_padded.prog
```

Check the board filesystem:

```powershell
py -m mpremote connect COM3 fs ls
```

The bitstream and all test programs should be present.

## 8. Run the FPGA on the Board

Execute the MicroPython board runner:

```powershell
py -m mpremote connect COM3 run host/board_run.py
```

The runner performs the following operations:

1. Imports the Shrike board module.
2. Programs the FPGA using `shrike_simt.bin`.
3. Initializes the RP2040 SPI interface.
4. Checks the FPGA identification register.
5. Executes available `.prog` test programs.
6. Reports test outcomes and available performance counters.

### SPI interface

The host runner uses SPI0 with the following RP2040 pin assignments:

| SPI signal | RP2040 GPIO |
|---|---:|
| SCK | GP2 |
| MOSI | GP3 |
| MISO | GP0 |
| Chip Select | GP1 |

The FPGA interface must be mapped to the corresponding physical FPGA pins in ForgeFPGA.

The FPGA identification register is expected to return:

```text
0xA5
```

A successful identification check confirms that the host can communicate with the configured FPGA interface.

## 9. Test Programs

The project includes the following test programs:

| Program | Purpose |
|---|---|
| `vecadd.prog` | Vector addition |
| `dot.prog` | Dot-product computation |
| `matvec_relu.prog` | Matrix-vector operation with ReLU |
| `matvec_padded.prog` | Padded matrix-vector operation |
| `conflict.prog` | Tests involving memory or resource conflicts |
| `diverge.prog` | Tests SIMT control-flow divergence |

These programs are used to exercise different processor execution and data-processing scenarios.

## 10. Troubleshooting

### FPGA does not return ID `0xA5`

If the board runner reports:

```text
FPGA did not answer with ID 0xA5
```

Check:

- Whether the correct bitstream was generated and uploaded.
- Whether the FPGA top-level module is selected correctly.
- Whether the SPI signals are mapped to the correct FPGA GPIOs.
- Whether the MISO output-enable signal is configured.
- Whether the FPGA clock and reset configuration are correct.
- Whether the RP2040 SPI pin configuration matches the board wiring.

A zero response (`0x00`) indicates that the expected ID response has not been received. It should not be treated as a successful hardware test.

### FPGA placement failure

If placement fails, inspect the synthesis report for:

- LUT utilization
- CLB utilization
- Flip-flop utilization
- BRAM utilization

The SLG47910 has limited logic resources, so lane count and hardware resource requirements must be considered.

## Key Engineering Areas Demonstrated

- **RTL Design:** Developing a processor core and FPGA top-level module using Verilog.
- **Parallel Computing:** Implementing SIMT execution concepts and testing vector and matrix operations.
- **FPGA Tool Flow:** Performing synthesis, resource analysis, placement, routing, and bitstream generation.
- **Resource Optimization:** Adapting the design to the LUT and CLB constraints of a small FPGA.
- **Embedded Systems:** Using RP2040 MicroPython to control FPGA programming and execution.
- **Hardware Interfaces:** Integrating an FPGA with a microcontroller using SPI.
- **Assembler and Verification:** Converting programs into machine-readable test files and running regression tests.
- **Hardware Debugging:** Investigating pin mapping, clocking, output enables, and FPGA communication.

## Current Status and Next Steps

| Stage | Status |
|---|---|
| RTL implementation | Completed for initial one-lane configuration |
| Synthesis | Completed |
| Resource analysis | Completed |
| Placement and routing | Completed |
| Bitstream generation | Completed |
| RP2040 MicroPython setup | Verified |
| Bitstream and program upload | Completed |
| FPGA SPI identification | Under debugging |
| Hardware execution tests | Pending |
| Test result validation | Pending |

The immediate next step is to verify the ForgeFPGA GPIO connections for SPI and clock signals, regenerate the bitstream, and rerun the board identification check.

Once the FPGA returns `0xA5`, proceed with the six hardware test programs and record their PASS/FAIL results.

---
