#!/usr/bin/env bash
set -euo pipefail
export SYSTEMC_CLANG_BUILD_DIR=/home/jonguk/Projects/CXL_SWITCH/systemc-clang/build
export SYSTEMC_CLANG=/home/jonguk/Projects/CXL_SWITCH/systemc-clang
SRCDIR=$(pwd)
export SYSTEMC=/usr/local
export LLVM_INSTALL_DIR=/usr/lib/llvm-15
# 1) Generate SV
bash /home/jonguk/Projects/CXL_SWITCH/systemc-clang/scripts/run-cpp-sv.sh "$SRCDIR/Counter_top.cpp" >/dev/null
SV=$(ls -1 *.sv | head -n1)
# 2) Format
if command -v verible-verilog-format >/dev/null 2>&1; then
  verible-verilog-format --inplace "$SV"
fi
# 3) Verilator sim
rm -rf obj_dir
verilator -sv --top-module tb_counter -Wall -Wno-DECLFILENAME -Wno-TIMESCALEMOD --cc --binary "$SV" tb_counter.sv >/dev/null
./obj_dir/Vtb_counter > verilator_out.txt
# 4) SystemC sim
clang++ -std=c++17 -I"$SYSTEMC/include" -L"$SYSTEMC/lib" Counter_top.cpp -lsystemc -lpthread -o counter_sc >/dev/null
./counter_sc | sed 's/ ns//' > systemc_out.txt
# 5) Compare value sequences (ignore time units)
cut -d, -f2 verilator_out.txt | head -n 20 > v_vals.txt
cut -d, -f2 systemc_out.txt | head -n 20 > sc_vals.txt
if diff -q v_vals.txt sc_vals.txt >/dev/null; then
  echo "REGRESSION PASS: value sequences match (first 20)"
  exit 0
else
  echo "REGRESSION FAIL: sequences differ" >&2
  diff -u sc_vals.txt v_vals.txt || true
  exit 1
fi
