// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_unit.h for the primary calling header

#include "Vcontrol_unit.h"
#include "Vcontrol_unit__Syms.h"

//==========

void Vcontrol_unit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol_unit::eval\n"); );
    Vcontrol_unit__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("rtl/control_unit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcontrol_unit::_eval_initial_loop(Vcontrol_unit__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("rtl/control_unit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcontrol_unit::_sequent__TOP__1(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_sequent__TOP__1\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->control_unit__DOT__current_state = 0U;
    } else {
        if (vlTOPp->run) {
            vlTOPp->control_unit__DOT__current_state 
                = vlTOPp->control_unit__DOT__next_state;
        }
    }
}

VL_INLINE_OPT void Vcontrol_unit::_settle__TOP__2(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_settle__TOP__2\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->run) << 3U) 
                            | (((IData)(vlTOPp->reset) 
                                << 2U) | (IData)(vlTOPp->control_unit__DOT__current_state)));
    vlTOPp->control_unit__DOT__next_state = vlTOPp->__Vtable1_control_unit__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->control_unit__DOT__reg_done = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                vlTOPp->control_unit__DOT__reg_done = 1U;
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_i = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((1U & (~ ((IData)(vlTOPp->control_unit__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__current_state)))) {
                vlTOPp->control_unit__DOT__reg_en_i = 1U;
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_c = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__current_state)))) {
                vlTOPp->control_unit__DOT__reg_en_c = 1U;
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_s = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((1U & (~ ((IData)(vlTOPp->control_unit__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                vlTOPp->control_unit__DOT__reg_en_s = 1U;
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_alu_mode = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__current_state)))) {
                vlTOPp->control_unit__DOT__reg_alu_mode 
                    = (1U & ((IData)(vlTOPp->instruction) 
                             >> 2U));
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_7 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                        if ((0x2000U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->control_unit__DOT__reg_en_7 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_6 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                      >> 0xdU)))) {
                            vlTOPp->control_unit__DOT__reg_en_6 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_5 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->control_unit__DOT__reg_en_5 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_4 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                      >> 0xdU)))) {
                            vlTOPp->control_unit__DOT__reg_en_4 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_3 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                              >> 0xfU)))) {
                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                        if ((0x2000U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->control_unit__DOT__reg_en_3 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_2 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                              >> 0xfU)))) {
                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                      >> 0xdU)))) {
                            vlTOPp->control_unit__DOT__reg_en_2 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_1 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                              >> 0xfU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->control_unit__DOT__reg_en_1 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_en_0 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                              >> 0xfU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                      >> 0xdU)))) {
                            vlTOPp->control_unit__DOT__reg_en_0 = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_alu_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__current_state)))) {
                vlTOPp->control_unit__DOT__reg_alu_sel 
                    = (0xfU & ((IData)(vlTOPp->instruction) 
                               >> 3U));
            }
        }
    }
    vlTOPp->control_unit__DOT__reg_mux_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__current_state)))) {
                vlTOPp->control_unit__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlTOPp->instruction) 
                             >> 0xaU));
            }
        } else {
            if ((1U & (IData)(vlTOPp->control_unit__DOT__current_state))) {
                vlTOPp->control_unit__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlTOPp->instruction) 
                             >> 0xdU));
            }
        }
    }
    vlTOPp->done = vlTOPp->control_unit__DOT__reg_done;
    vlTOPp->en_i = vlTOPp->control_unit__DOT__reg_en_i;
    vlTOPp->en_c = vlTOPp->control_unit__DOT__reg_en_c;
    vlTOPp->en_s = vlTOPp->control_unit__DOT__reg_en_s;
    vlTOPp->alu_mode = vlTOPp->control_unit__DOT__reg_alu_mode;
    vlTOPp->en_7 = vlTOPp->control_unit__DOT__reg_en_7;
    vlTOPp->en_6 = vlTOPp->control_unit__DOT__reg_en_6;
    vlTOPp->en_5 = vlTOPp->control_unit__DOT__reg_en_5;
    vlTOPp->en_4 = vlTOPp->control_unit__DOT__reg_en_4;
    vlTOPp->en_3 = vlTOPp->control_unit__DOT__reg_en_3;
    vlTOPp->en_2 = vlTOPp->control_unit__DOT__reg_en_2;
    vlTOPp->en_1 = vlTOPp->control_unit__DOT__reg_en_1;
    vlTOPp->en_0 = vlTOPp->control_unit__DOT__reg_en_0;
    vlTOPp->alu_sel = vlTOPp->control_unit__DOT__reg_alu_sel;
    vlTOPp->mux_sel = vlTOPp->control_unit__DOT__reg_mux_sel;
}

void Vcontrol_unit::_eval(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_eval\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vcontrol_unit::_change_request(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_change_request\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vcontrol_unit::_change_request_1(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_change_request_1\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcontrol_unit::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
