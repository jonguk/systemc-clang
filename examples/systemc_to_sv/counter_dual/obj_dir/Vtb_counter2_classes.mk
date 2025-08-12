# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtb_counter2.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
  Vtb_counter2 \
  Vtb_counter2___024root__DepSet_h064710dd__0 \
  Vtb_counter2___024root__DepSet_hb93b8bac__0 \
  Vtb_counter2_top_wrap2_sc_module_0_if__DepSet_hb539f669__0 \
  Vtb_counter2_counter_sc_module_1_if__DepSet_hbf065e29__0 \
  Vtb_counter2_counter_sc_module_2_if__DepSet_had2b8f97__0 \
  Vtb_counter2__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  Vtb_counter2___024root__Slow \
  Vtb_counter2___024root__DepSet_h064710dd__0__Slow \
  Vtb_counter2___024root__DepSet_hb93b8bac__0__Slow \
  Vtb_counter2_top_wrap2_sc_module_0_if__Slow \
  Vtb_counter2_top_wrap2_sc_module_0_if__DepSet_hb539f669__0__Slow \
  Vtb_counter2_counter_sc_module_1_if__Slow \
  Vtb_counter2_counter_sc_module_1_if__DepSet_hbf065e29__0__Slow \
  Vtb_counter2_counter_sc_module_2_if__Slow \
  Vtb_counter2_counter_sc_module_2_if__DepSet_had2b8f97__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  Vtb_counter2__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_timing \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
