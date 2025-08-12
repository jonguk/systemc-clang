// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter.h for the primary calling header

#include "Vtb_counter__pch.h"
#include "Vtb_counter_counter_sc_module_1_if.h"

VL_ATTR_COLD void Vtb_counter_counter_sc_module_1_if___ctor_var_reset(Vtb_counter_counter_sc_module_1_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_counter_counter_sc_module_1_if___ctor_var_reset\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8861071527689086543ull);
}
