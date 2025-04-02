// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlock.h for the primary calling header

#include "Vlock.h"
#include "Vlock__Syms.h"

//==========
CData/*2:0*/ Vlock::__Vtable1_lock__DOT__next_state[128];

VL_CTOR_IMP(Vlock) {
    Vlock__Syms* __restrict vlSymsp = __VlSymsp = new Vlock__Syms(this, name());
    Vlock* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vlock::__Vconfigure(Vlock__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vlock::~Vlock() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vlock::_settle__TOP__2(Vlock__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlock::_settle__TOP__2\n"); );
    Vlock* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->locked = (6U != (IData)(vlTOPp->lock__DOT__current_state));
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->in) << 3U) 
                            | (IData)(vlTOPp->lock__DOT__current_state));
    vlTOPp->lock__DOT__next_state = vlTOPp->__Vtable1_lock__DOT__next_state
        [vlTOPp->__Vtableidx1];
}

void Vlock::_eval_initial(Vlock__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlock::_eval_initial\n"); );
    Vlock* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vlock::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlock::final\n"); );
    // Variables
    Vlock__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vlock* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlock::_eval_settle(Vlock__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlock::_eval_settle\n"); );
    Vlock* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vlock::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlock::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    in = VL_RAND_RESET_I(4);
    locked = VL_RAND_RESET_I(1);
    lock__DOT__current_state = VL_RAND_RESET_I(3);
    lock__DOT__next_state = VL_RAND_RESET_I(3);
    __Vtableidx1 = 0;
    __Vtable1_lock__DOT__next_state[0] = 0U;
    __Vtable1_lock__DOT__next_state[1] = 0U;
    __Vtable1_lock__DOT__next_state[2] = 0U;
    __Vtable1_lock__DOT__next_state[3] = 0U;
    __Vtable1_lock__DOT__next_state[4] = 0U;
    __Vtable1_lock__DOT__next_state[5] = 0U;
    __Vtable1_lock__DOT__next_state[6] = 6U;
    __Vtable1_lock__DOT__next_state[7] = 0U;
    __Vtable1_lock__DOT__next_state[8] = 0U;
    __Vtable1_lock__DOT__next_state[9] = 0U;
    __Vtable1_lock__DOT__next_state[10] = 0U;
    __Vtable1_lock__DOT__next_state[11] = 0U;
    __Vtable1_lock__DOT__next_state[12] = 0U;
    __Vtable1_lock__DOT__next_state[13] = 0U;
    __Vtable1_lock__DOT__next_state[14] = 6U;
    __Vtable1_lock__DOT__next_state[15] = 0U;
    __Vtable1_lock__DOT__next_state[16] = 0U;
    __Vtable1_lock__DOT__next_state[17] = 0U;
    __Vtable1_lock__DOT__next_state[18] = 0U;
    __Vtable1_lock__DOT__next_state[19] = 4U;
    __Vtable1_lock__DOT__next_state[20] = 0U;
    __Vtable1_lock__DOT__next_state[21] = 0U;
    __Vtable1_lock__DOT__next_state[22] = 6U;
    __Vtable1_lock__DOT__next_state[23] = 0U;
    __Vtable1_lock__DOT__next_state[24] = 1U;
    __Vtable1_lock__DOT__next_state[25] = 2U;
    __Vtable1_lock__DOT__next_state[26] = 0U;
    __Vtable1_lock__DOT__next_state[27] = 0U;
    __Vtable1_lock__DOT__next_state[28] = 0U;
    __Vtable1_lock__DOT__next_state[29] = 0U;
    __Vtable1_lock__DOT__next_state[30] = 6U;
    __Vtable1_lock__DOT__next_state[31] = 0U;
    __Vtable1_lock__DOT__next_state[32] = 0U;
    __Vtable1_lock__DOT__next_state[33] = 0U;
    __Vtable1_lock__DOT__next_state[34] = 0U;
    __Vtable1_lock__DOT__next_state[35] = 0U;
    __Vtable1_lock__DOT__next_state[36] = 0U;
    __Vtable1_lock__DOT__next_state[37] = 0U;
    __Vtable1_lock__DOT__next_state[38] = 6U;
    __Vtable1_lock__DOT__next_state[39] = 0U;
    __Vtable1_lock__DOT__next_state[40] = 0U;
    __Vtable1_lock__DOT__next_state[41] = 0U;
    __Vtable1_lock__DOT__next_state[42] = 3U;
    __Vtable1_lock__DOT__next_state[43] = 0U;
    __Vtable1_lock__DOT__next_state[44] = 5U;
    __Vtable1_lock__DOT__next_state[45] = 0U;
    __Vtable1_lock__DOT__next_state[46] = 6U;
    __Vtable1_lock__DOT__next_state[47] = 0U;
    __Vtable1_lock__DOT__next_state[48] = 0U;
    __Vtable1_lock__DOT__next_state[49] = 0U;
    __Vtable1_lock__DOT__next_state[50] = 0U;
    __Vtable1_lock__DOT__next_state[51] = 0U;
    __Vtable1_lock__DOT__next_state[52] = 0U;
    __Vtable1_lock__DOT__next_state[53] = 6U;
    __Vtable1_lock__DOT__next_state[54] = 6U;
    __Vtable1_lock__DOT__next_state[55] = 0U;
    __Vtable1_lock__DOT__next_state[56] = 0U;
    __Vtable1_lock__DOT__next_state[57] = 0U;
    __Vtable1_lock__DOT__next_state[58] = 0U;
    __Vtable1_lock__DOT__next_state[59] = 0U;
    __Vtable1_lock__DOT__next_state[60] = 0U;
    __Vtable1_lock__DOT__next_state[61] = 0U;
    __Vtable1_lock__DOT__next_state[62] = 6U;
    __Vtable1_lock__DOT__next_state[63] = 0U;
    __Vtable1_lock__DOT__next_state[64] = 0U;
    __Vtable1_lock__DOT__next_state[65] = 0U;
    __Vtable1_lock__DOT__next_state[66] = 0U;
    __Vtable1_lock__DOT__next_state[67] = 0U;
    __Vtable1_lock__DOT__next_state[68] = 0U;
    __Vtable1_lock__DOT__next_state[69] = 0U;
    __Vtable1_lock__DOT__next_state[70] = 6U;
    __Vtable1_lock__DOT__next_state[71] = 0U;
    __Vtable1_lock__DOT__next_state[72] = 0U;
    __Vtable1_lock__DOT__next_state[73] = 0U;
    __Vtable1_lock__DOT__next_state[74] = 0U;
    __Vtable1_lock__DOT__next_state[75] = 0U;
    __Vtable1_lock__DOT__next_state[76] = 0U;
    __Vtable1_lock__DOT__next_state[77] = 0U;
    __Vtable1_lock__DOT__next_state[78] = 6U;
    __Vtable1_lock__DOT__next_state[79] = 0U;
    __Vtable1_lock__DOT__next_state[80] = 0U;
    __Vtable1_lock__DOT__next_state[81] = 0U;
    __Vtable1_lock__DOT__next_state[82] = 0U;
    __Vtable1_lock__DOT__next_state[83] = 0U;
    __Vtable1_lock__DOT__next_state[84] = 0U;
    __Vtable1_lock__DOT__next_state[85] = 0U;
    __Vtable1_lock__DOT__next_state[86] = 6U;
    __Vtable1_lock__DOT__next_state[87] = 0U;
    __Vtable1_lock__DOT__next_state[88] = 0U;
    __Vtable1_lock__DOT__next_state[89] = 0U;
    __Vtable1_lock__DOT__next_state[90] = 0U;
    __Vtable1_lock__DOT__next_state[91] = 0U;
    __Vtable1_lock__DOT__next_state[92] = 0U;
    __Vtable1_lock__DOT__next_state[93] = 0U;
    __Vtable1_lock__DOT__next_state[94] = 6U;
    __Vtable1_lock__DOT__next_state[95] = 0U;
    __Vtable1_lock__DOT__next_state[96] = 0U;
    __Vtable1_lock__DOT__next_state[97] = 0U;
    __Vtable1_lock__DOT__next_state[98] = 0U;
    __Vtable1_lock__DOT__next_state[99] = 0U;
    __Vtable1_lock__DOT__next_state[100] = 0U;
    __Vtable1_lock__DOT__next_state[101] = 0U;
    __Vtable1_lock__DOT__next_state[102] = 6U;
    __Vtable1_lock__DOT__next_state[103] = 0U;
    __Vtable1_lock__DOT__next_state[104] = 0U;
    __Vtable1_lock__DOT__next_state[105] = 0U;
    __Vtable1_lock__DOT__next_state[106] = 0U;
    __Vtable1_lock__DOT__next_state[107] = 0U;
    __Vtable1_lock__DOT__next_state[108] = 0U;
    __Vtable1_lock__DOT__next_state[109] = 0U;
    __Vtable1_lock__DOT__next_state[110] = 6U;
    __Vtable1_lock__DOT__next_state[111] = 0U;
    __Vtable1_lock__DOT__next_state[112] = 0U;
    __Vtable1_lock__DOT__next_state[113] = 0U;
    __Vtable1_lock__DOT__next_state[114] = 0U;
    __Vtable1_lock__DOT__next_state[115] = 0U;
    __Vtable1_lock__DOT__next_state[116] = 0U;
    __Vtable1_lock__DOT__next_state[117] = 0U;
    __Vtable1_lock__DOT__next_state[118] = 6U;
    __Vtable1_lock__DOT__next_state[119] = 0U;
    __Vtable1_lock__DOT__next_state[120] = 0U;
    __Vtable1_lock__DOT__next_state[121] = 0U;
    __Vtable1_lock__DOT__next_state[122] = 0U;
    __Vtable1_lock__DOT__next_state[123] = 0U;
    __Vtable1_lock__DOT__next_state[124] = 0U;
    __Vtable1_lock__DOT__next_state[125] = 0U;
    __Vtable1_lock__DOT__next_state[126] = 6U;
    __Vtable1_lock__DOT__next_state[127] = 0U;
}
