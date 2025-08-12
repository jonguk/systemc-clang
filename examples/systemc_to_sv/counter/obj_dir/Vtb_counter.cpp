// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_counter__pch.h"

//============================================================
// Constructors

Vtb_counter::Vtb_counter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_counter__Syms(contextp(), _vcname__, this)}
    , __PVT__tb_counter__DOT__itf{vlSymsp->TOP.__PVT__tb_counter__DOT__itf}
    , __PVT__tb_counter__DOT__dut__DOT__u_counter_itf{vlSymsp->TOP.__PVT__tb_counter__DOT__dut__DOT__u_counter_itf}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_counter::Vtb_counter(const char* _vcname__)
    : Vtb_counter(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_counter::~Vtb_counter() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_counter___024root___eval_debug_assertions(Vtb_counter___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_counter___024root___eval_static(Vtb_counter___024root* vlSelf);
void Vtb_counter___024root___eval_initial(Vtb_counter___024root* vlSelf);
void Vtb_counter___024root___eval_settle(Vtb_counter___024root* vlSelf);
void Vtb_counter___024root___eval(Vtb_counter___024root* vlSelf);

void Vtb_counter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_counter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_counter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_counter___024root___eval_static(&(vlSymsp->TOP));
        Vtb_counter___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_counter___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_counter___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_counter::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_counter::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_counter::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_counter___024root___eval_final(Vtb_counter___024root* vlSelf);

VL_ATTR_COLD void Vtb_counter::final() {
    Vtb_counter___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_counter::hierName() const { return vlSymsp->name(); }
const char* Vtb_counter::modelName() const { return "Vtb_counter"; }
unsigned Vtb_counter::threads() const { return 1; }
void Vtb_counter::prepareClone() const { contextp()->prepareClone(); }
void Vtb_counter::atClone() const {
    contextp()->threadPoolpOnClone();
}
