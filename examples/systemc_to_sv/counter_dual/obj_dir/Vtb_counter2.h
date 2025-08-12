// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTB_COUNTER2_H_
#define VERILATED_VTB_COUNTER2_H_  // guard

#include "verilated.h"

class Vtb_counter2__Syms;
class Vtb_counter2___024root;
class Vtb_counter2_counter_sc_module_1_if;
class Vtb_counter2_counter_sc_module_2_if;
class Vtb_counter2_top_wrap2_sc_module_0_if;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtb_counter2 VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtb_counter2__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtb_counter2_top_wrap2_sc_module_0_if* const __PVT__tb_counter2__DOT__itf;
    Vtb_counter2_counter_sc_module_1_if* const __PVT__tb_counter2__DOT__dut__DOT__u0_itf;
    Vtb_counter2_counter_sc_module_2_if* const __PVT__tb_counter2__DOT__dut__DOT__u1_itf;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtb_counter2___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtb_counter2(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtb_counter2(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtb_counter2();
  private:
    VL_UNCOPYABLE(Vtb_counter2);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
