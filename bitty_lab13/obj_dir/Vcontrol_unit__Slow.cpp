// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_unit.h for the primary calling header

#include "Vcontrol_unit.h"
#include "Vcontrol_unit__Syms.h"

//==========
CData/*1:0*/ Vcontrol_unit::__Vtable1_control_unit__DOT__next_state[16];

VL_CTOR_IMP(Vcontrol_unit) {
    Vcontrol_unit__Syms* __restrict vlSymsp = __VlSymsp = new Vcontrol_unit__Syms(this, name());
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcontrol_unit::__Vconfigure(Vcontrol_unit__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vcontrol_unit::~Vcontrol_unit() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcontrol_unit::_eval_initial(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_eval_initial\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vcontrol_unit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::final\n"); );
    // Variables
    Vcontrol_unit__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcontrol_unit::_eval_settle(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_eval_settle\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vcontrol_unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_ctor_var_reset\n"); );
    // Body
    run = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    instruction = VL_RAND_RESET_I(16);
    alu_sel = VL_RAND_RESET_I(3);
    mux_sel = VL_RAND_RESET_I(4);
    imm = VL_RAND_RESET_I(16);
    en_s = VL_RAND_RESET_I(1);
    en_c = VL_RAND_RESET_I(1);
    en_0 = VL_RAND_RESET_I(1);
    en_1 = VL_RAND_RESET_I(1);
    en_2 = VL_RAND_RESET_I(1);
    en_3 = VL_RAND_RESET_I(1);
    en_4 = VL_RAND_RESET_I(1);
    en_5 = VL_RAND_RESET_I(1);
    en_6 = VL_RAND_RESET_I(1);
    en_7 = VL_RAND_RESET_I(1);
    en_i = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_imm = VL_RAND_RESET_I(16);
    control_unit__DOT__current_state = VL_RAND_RESET_I(2);
    control_unit__DOT__next_state = VL_RAND_RESET_I(2);
    control_unit__DOT__reg_alu_sel = VL_RAND_RESET_I(3);
    control_unit__DOT__reg_mux_sel = VL_RAND_RESET_I(4);
    control_unit__DOT__reg_en_c = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_0 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_1 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_2 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_3 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_4 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_5 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_6 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_7 = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_i = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_en_s = VL_RAND_RESET_I(1);
    control_unit__DOT__reg_done = VL_RAND_RESET_I(1);
    __Vtableidx1 = 0;
    __Vtable1_control_unit__DOT__next_state[0] = 0U;
    __Vtable1_control_unit__DOT__next_state[1] = 1U;
    __Vtable1_control_unit__DOT__next_state[2] = 2U;
    __Vtable1_control_unit__DOT__next_state[3] = 3U;
    __Vtable1_control_unit__DOT__next_state[4] = 0U;
    __Vtable1_control_unit__DOT__next_state[5] = 1U;
    __Vtable1_control_unit__DOT__next_state[6] = 2U;
    __Vtable1_control_unit__DOT__next_state[7] = 3U;
    __Vtable1_control_unit__DOT__next_state[8] = 1U;
    __Vtable1_control_unit__DOT__next_state[9] = 2U;
    __Vtable1_control_unit__DOT__next_state[10] = 3U;
    __Vtable1_control_unit__DOT__next_state[11] = 0U;
    __Vtable1_control_unit__DOT__next_state[12] = 0U;
    __Vtable1_control_unit__DOT__next_state[13] = 1U;
    __Vtable1_control_unit__DOT__next_state[14] = 2U;
    __Vtable1_control_unit__DOT__next_state[15] = 3U;
}
