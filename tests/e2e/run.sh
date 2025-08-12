#!/usr/bin/env bash
set -euo pipefail
ROOT=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." &>/dev/null && pwd)
EX_DIR="$ROOT/examples/systemc_to_sv/counter"
export SYSTEMC_CLANG="$ROOT"
export SYSTEMC_CLANG_BUILD_DIR="$ROOT/build"
export LLVM_INSTALL_DIR=/usr/lib/llvm-15
export SYSTEMC=/usr/local
# 1) Generate SV
bash "$ROOT/scripts/run-cpp-sv.sh" "$EX_DIR/Counter_top.cpp" >/dev/null
SV=$(ls -1 "$EX_DIR"/*.sv | head -n1)
# 2) Format (optional)
command -v verible-verilog-format >/dev/null 2>&1 && verible-verilog-format --inplace "$SV"
# 3) Verilator
cd "$EX_DIR"
rm -rf obj_dir
verilator -sv --top-module tb_counter -Wall -Wno-DECLFILENAME -Wno-TIMESCALEMOD --cc --binary TopWrap_sc_module_0.sv tb_counter.sv >/dev/null
./obj_dir/Vtb_counter > verilator_out.txt
# 4) SystemC
clang++ -std=c++17 -I"$SYSTEMC/include" -L"$SYSTEMC/lib" Counter_top.cpp -lsystemc -lpthread -o counter_sc >/dev/null
./counter_sc | sed 's/ ns//' > systemc_out.txt
# 5) Compare sequences (values only)
cut -d, -f2 verilator_out.txt | head -n 20 > v_vals.txt
cut -d, -f2 systemc_out.txt | head -n 20 > sc_vals.txt
if diff -q v_vals.txt sc_vals.txt >/dev/null; then
  echo "E2E PASS: value sequences match (first 20)"
  exit 0
else
  echo "E2E FAIL: sequences differ" >&2
  diff -u sc_vals.txt v_vals.txt || true
  exit 1
fi
