// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux.h for the primary calling header

#include "Vmux.h"
#include "Vmux__Syms.h"

//==========

VL_CTOR_IMP(Vmux) {
    Vmux__Syms* __restrict vlSymsp = __VlSymsp = new Vmux__Syms(this, name());
    Vmux* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmux::__Vconfigure(Vmux__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vmux::~Vmux() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vmux::_eval_initial(Vmux__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux::_eval_initial\n"); );
    Vmux* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmux::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux::final\n"); );
    // Variables
    Vmux__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmux* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmux::_eval_settle(Vmux__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux::_eval_settle\n"); );
    Vmux* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vmux::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux::_ctor_var_reset\n"); );
    // Body
    reg_0 = VL_RAND_RESET_I(16);
    reg_1 = VL_RAND_RESET_I(16);
    reg_2 = VL_RAND_RESET_I(16);
    reg_3 = VL_RAND_RESET_I(16);
    reg_4 = VL_RAND_RESET_I(16);
    reg_5 = VL_RAND_RESET_I(16);
    reg_6 = VL_RAND_RESET_I(16);
    reg_7 = VL_RAND_RESET_I(16);
    imm = VL_RAND_RESET_I(16);
    sel = VL_RAND_RESET_I(4);
    out = VL_RAND_RESET_I(16);
}
