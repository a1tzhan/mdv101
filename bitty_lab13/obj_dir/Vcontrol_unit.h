// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCONTROL_UNIT_H_
#define _VCONTROL_UNIT_H_  // guard

#include "verilated.h"

//==========

class Vcontrol_unit__Syms;

//----------

VL_MODULE(Vcontrol_unit) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(reset,0,0);
    VL_IN8(clk,0,0);
    VL_IN8(run,0,0);
    VL_OUT8(alu_sel,2,0);
    VL_OUT8(mux_sel,3,0);
    VL_OUT8(en_s,0,0);
    VL_OUT8(en_c,0,0);
    VL_OUT8(en_0,0,0);
    VL_OUT8(en_1,0,0);
    VL_OUT8(en_2,0,0);
    VL_OUT8(en_3,0,0);
    VL_OUT8(en_4,0,0);
    VL_OUT8(en_5,0,0);
    VL_OUT8(en_6,0,0);
    VL_OUT8(en_7,0,0);
    VL_OUT8(en_i,0,0);
    VL_OUT8(done,0,0);
    VL_IN16(instruction,15,0);
    VL_OUT16(imm,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ control_unit__DOT__current_state;
    CData/*1:0*/ control_unit__DOT__next_state;
    CData/*2:0*/ control_unit__DOT__reg_alu_sel;
    CData/*3:0*/ control_unit__DOT__reg_mux_sel;
    CData/*0:0*/ control_unit__DOT__reg_en_c;
    CData/*0:0*/ control_unit__DOT__reg_en_0;
    CData/*0:0*/ control_unit__DOT__reg_en_1;
    CData/*0:0*/ control_unit__DOT__reg_en_2;
    CData/*0:0*/ control_unit__DOT__reg_en_3;
    CData/*0:0*/ control_unit__DOT__reg_en_4;
    CData/*0:0*/ control_unit__DOT__reg_en_5;
    CData/*0:0*/ control_unit__DOT__reg_en_6;
    CData/*0:0*/ control_unit__DOT__reg_en_7;
    CData/*0:0*/ control_unit__DOT__reg_en_i;
    CData/*0:0*/ control_unit__DOT__reg_en_s;
    CData/*0:0*/ control_unit__DOT__reg_done;
    SData/*15:0*/ control_unit__DOT__reg_imm;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*3:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    static CData/*1:0*/ __Vtable1_control_unit__DOT__next_state[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcontrol_unit__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcontrol_unit);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcontrol_unit(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcontrol_unit();
    
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
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcontrol_unit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcontrol_unit__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcontrol_unit__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vcontrol_unit__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcontrol_unit__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcontrol_unit__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcontrol_unit__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vcontrol_unit__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vcontrol_unit__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
