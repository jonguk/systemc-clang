// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter2.h for the primary calling header

#include "Vtb_counter2__pch.h"
#include "Vtb_counter2_top_wrap2_sc_module_0_if.h"

VL_ATTR_COLD void Vtb_counter2_top_wrap2_sc_module_0_if___ctor_var_reset(Vtb_counter2_top_wrap2_sc_module_0_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_counter2_top_wrap2_sc_module_0_if___ctor_var_reset\n"); );
    Vtb_counter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14129604614540204776ull);
    vlSelf->en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7710216835639188562ull);
}
