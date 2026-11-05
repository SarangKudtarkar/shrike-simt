#!/usr/bin/env bash
# Rough LUT/flip-flop estimate with Yosys (5-input LUTs). Not a substitute for Go Configure's own report.
cd "$(dirname "$0")/.."
Y=$(command -v yosys || command -v yowasp-yosys || true)
[ -n "$Y" ] || { echo "yosys not found (pip install yowasp-yosys)"; exit 1; }
"$Y" -q -p "read_verilog rtl/simt_core.v rtl/shrike_top.v; synth -top shrike_top -flatten -lut 5; stat" \
    | grep -E "LUT|DFF|Number of cells|cells$" || true
echo "Shrike-Lite FPGA budget: 1120 LUTs"
