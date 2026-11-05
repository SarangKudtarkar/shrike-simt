#!/usr/bin/env bash
# Build the C++ model + Verilated RTL, run every kernel on both, diff them, print a perf table.
set -e
cd "$(dirname "$0")/.."
mkdir -p build results

VER=$(command -v verilator || command -v verilator-cli || true)
[ -n "$VER" ] || { echo "verilator not found (sudo apt install verilator, or pip install verilator)"; exit 1; }

g++ -O2 -std=c++17 -Imodel model/simt_model.cpp -o build/simt_model
"$VER" --cc --exe --build -O2 -Wno-fatal --top-module shrike_top -Mdir build/obj \
    -CFLAGS "-I$PWD/model" rtl/simt_core.v rtl/shrike_top.v tb/tb_top.cpp -o tb_top \
    > build/verilator.log 2>&1 || { tail -30 build/verilator.log; exit 1; }

echo "kernel,cycles,instr,lane_ops,conflicts,utilization_pct" > results/perf.csv
printf "%-22s %7s %6s %9s %10s %6s  %s\n" kernel cycles instr lane_ops conflicts util% status
fail=0
for src in kernels/*.s; do
    k=$(basename "$src" .s)
    python3 tools/asm.py "$src" -o "build/$k.prog" > /dev/null
    set +e
    ./build/simt_model "build/$k.prog" > "build/$k.model.txt"; m=$?
    ./build/obj/tb_top "build/$k.prog" > "build/$k.rtl.txt";  r=$?
    set -e
    status=OK
    if ! diff -q "build/$k.model.txt" "build/$k.rtl.txt" > /dev/null; then status="MODEL!=RTL"; fail=1; fi
    if [ $m -ne 0 ] || [ $r -ne 0 ]; then status="$status CHECK-FAIL"; fail=1; fi
    cnt=$(grep '^CNT' "build/$k.rtl.txt")
    cyc=$(echo "$cnt" | sed 's/.*cycles=\([0-9]*\).*/\1/')
    ins=$(echo "$cnt" | sed 's/.*instr=\([0-9]*\).*/\1/')
    ops=$(echo "$cnt" | sed 's/.*lane_ops=\([0-9]*\).*/\1/')
    con=$(echo "$cnt" | sed 's/.*conflicts=\([0-9]*\).*/\1/')
    util=$(awk -v o="$ops" -v i="$ins" 'BEGIN{printf "%.1f", 100*o/(i*2)}')
    printf "%-22s %7s %6s %9s %10s %6s  %s\n" "$k" "$cyc" "$ins" "$ops" "$con" "$util" "$status"
    echo "$k,$cyc,$ins,$ops,$con,$util" >> results/perf.csv
done
[ $fail -eq 0 ] && echo "ALL KERNELS PASS (RTL == model == expected)" || { echo "FAILURES"; exit 1; }
