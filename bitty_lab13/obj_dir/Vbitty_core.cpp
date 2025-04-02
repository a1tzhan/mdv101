// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core.h"
#include "Vbitty_core__Syms.h"

//==========

void Vbitty_core::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbitty_core::eval\n"); );
    Vbitty_core__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/bitty_core.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbitty_core::_eval_initial_loop(Vbitty_core__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/bitty_core.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vbitty_core::_sequent__TOP__1(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_sequent__TOP__1\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg7__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_7) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg7__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg6__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_6) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg6__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg5__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_5) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg5__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg4__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_4) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg4__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg3__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_3) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg3__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg2__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_2) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg2__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg1__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_1) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg1__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg0__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_0) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg0__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_i) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out 
                = vlTOPp->instruction;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__cu01__DOT__current_state = 0U;
    } else {
        if (vlTOPp->run) {
            vlTOPp->bitty_core__DOT__cu01__DOT__current_state 
                = vlTOPp->bitty_core__DOT__cu01__DOT__next_state;
        }
    }
    vlTOPp->reg_7 = vlTOPp->bitty_core__DOT__reg7__DOT__reg_d_out;
    vlTOPp->reg_6 = vlTOPp->bitty_core__DOT__reg6__DOT__reg_d_out;
    vlTOPp->reg_5 = vlTOPp->bitty_core__DOT__reg5__DOT__reg_d_out;
    vlTOPp->reg_4 = vlTOPp->bitty_core__DOT__reg4__DOT__reg_d_out;
    vlTOPp->reg_3 = vlTOPp->bitty_core__DOT__reg3__DOT__reg_d_out;
    vlTOPp->reg_2 = vlTOPp->bitty_core__DOT__reg2__DOT__reg_d_out;
    vlTOPp->reg_1 = vlTOPp->bitty_core__DOT__reg1__DOT__reg_d_out;
    vlTOPp->reg_0 = vlTOPp->bitty_core__DOT__reg0__DOT__reg_d_out;
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_c) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg_c__DOT__reg_d_out 
                = (0xffffU & ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                       ? (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                           == (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                                    > (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                                    ? 1U
                                                    : 2U))
                                       : ((0xfU >= 
                                           (0xfU & (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                           ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                              >> (0xfU 
                                                  & (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                           : 0U)) : 
                                  ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                    ? ((0xfU >= (0xfU 
                                                 & (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                        ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                           << (0xfU 
                                               & (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                        : 0U) : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                                 ^ (IData)(vlTOPp->bitty_core__DOT__mux_out))))
                               : ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                       ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                          | (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                       : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                          & (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                   : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                       ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                          - (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                       : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                          + (IData)(vlTOPp->bitty_core__DOT__mux_out))))));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out = 0U;
    } else {
        if (((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_s) 
             & (~ (IData)(vlTOPp->reset)))) {
            vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__mux_out;
        }
    }
}

VL_INLINE_OPT void Vbitty_core::_combo__TOP__3(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_combo__TOP__3\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_i = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_i = 1U;
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_7 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                    if ((0x4000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                        if ((0x2000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_7 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_6 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                    if ((0x4000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_6 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_5 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                    if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_5 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_4 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                    if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_4 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_3 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                              >> 0xfU)))) {
                    if ((0x4000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                        if ((0x2000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_3 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_2 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                              >> 0xfU)))) {
                    if ((0x4000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_2 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_1 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                              >> 0xfU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_1 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_0 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                              >> 0xfU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_0 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->run) << 3U) 
                            | (((IData)(vlTOPp->reset) 
                                << 2U) | (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)));
    vlTOPp->bitty_core__DOT__cu01__DOT__next_state 
        = vlTOPp->__Vtable1_bitty_core__DOT__cu01__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_done = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_done = 1U;
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                if ((0U == (3U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out)))) {
                    vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel 
                        = (7U & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                 >> 0xaU));
                } else {
                    if ((1U == (3U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out)))) {
                        vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel = 8U;
                    }
                }
            }
        } else {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                             >> 0xdU));
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_imm = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                if ((0U != (3U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out)))) {
                    if ((1U == (3U & (IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out)))) {
                        vlTOPp->bitty_core__DOT__cu01__DOT__reg_imm 
                            = (0xffU & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                                        >> 5U));
                    }
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_c = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_c = 1U;
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel 
                    = (7U & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                             >> 2U));
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_s = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_s = 1U;
            }
        }
    }
    vlTOPp->done = vlTOPp->bitty_core__DOT__cu01__DOT__reg_done;
    vlTOPp->bitty_core__DOT__mux_out = ((8U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                         ? ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                             ? 0U : 
                                            ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                              ? 0U : 
                                             ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                               ? 0U
                                               : (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_imm))))
                                         : ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                  ? (IData)(vlTOPp->reg_7)
                                                  : (IData)(vlTOPp->reg_6))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                  ? (IData)(vlTOPp->reg_5)
                                                  : (IData)(vlTOPp->reg_4)))
                                             : ((2U 
                                                 & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                  ? (IData)(vlTOPp->reg_3)
                                                  : (IData)(vlTOPp->reg_2))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                  ? (IData)(vlTOPp->reg_1)
                                                  : (IData)(vlTOPp->reg_0)))));
}

void Vbitty_core::_eval(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vbitty_core::_change_request(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_change_request\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vbitty_core::_change_request_1(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_change_request_1\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbitty_core::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
}
#endif  // VL_DEBUG
