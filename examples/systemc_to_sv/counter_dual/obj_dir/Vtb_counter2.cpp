// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_counter2__pch.h"

//============================================================
// Constructors

Vtb_counter2::Vtb_counter2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_counter2__Syms(contextp(), _vcname__, this)}
    , __PVT__tb_counter2__DOT__itf{vlSymsp->TOP.__PVT__tb_counter2__DOT__itf}
    , __PVT__tb_counter2__DOT__dut__DOT__u0_itf{vlSymsp->TOP.__PVT__tb_counter2__DOT__dut__DOT__u0_itf}
    , __PVT__tb_counter2__DOT__dut__DOT__u1_itf{vlSymsp->TOP.__PVT__tb_counter2__DOT__dut__DOT__u1_itf}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_counter2::Vtb_counter2(const char* _vcname__)
    : Vtb_counter2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_counter2::~Vtb_counter2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_counter2___024root___eval_debug_assertions(Vtb_counter2___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_counter2___024root___eval_static(Vtb_counter2___024root* vlSelf);
void Vtb_counter2___024root___eval_initial(Vtb_counter2___024root* vlSelf);
void Vtb_counter2___024root___eval_settle(Vtb_counter2___024root* vlSelf);
void Vtb_counter2___024root___eval(Vtb_counter2___024root* vlSelf);

void Vtb_counter2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_counter2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_counter2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_counter2___024root___eval_static(&(vlSymsp->TOP));
        Vtb_counter2___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_counter2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_counter2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_counter2::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_counter2::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_counter2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_counter2___024root___eval_final(Vtb_counter2___024root* vlSelf);

VL_ATTR_COLD void Vtb_counter2::final() {
    Vtb_counter2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_counter2::hierName() const { return vlSymsp->name(); }
const char* Vtb_counter2::modelName() const { return "Vtb_counter2"; }
unsigned Vtb_counter2::threads() const { return 1; }
void Vtb_counter2::prepareClone() const { contextp()->prepareClone(); }
void Vtb_counter2::atClone() const {
    contextp()->threadPoolpOnClone();
}
