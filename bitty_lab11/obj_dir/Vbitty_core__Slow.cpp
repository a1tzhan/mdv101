// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core.h"
#include "Vbitty_core__Syms.h"

//==========
CData/*1:0*/ Vbitty_core::__Vtable1_bitty_core__DOT__cu01__DOT__next_state[16];

VL_CTOR_IMP(Vbitty_core) {
    Vbitty_core__Syms* __restrict vlSymsp = __VlSymsp = new Vbitty_core__Syms(this, name());
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbitty_core::__Vconfigure(Vbitty_core__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vbitty_core::~Vbitty_core() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vbitty_core::_settle__TOP__2(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_settle__TOP__2\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->reg_0 = vlTOPp->bitty_core__DOT__reg0__DOT__reg_d_out;
    vlTOPp->reg_1 = vlTOPp->bitty_core__DOT__reg1__DOT__reg_d_out;
    vlTOPp->reg_2 = vlTOPp->bitty_core__DOT__reg2__DOT__reg_d_out;
    vlTOPp->reg_3 = vlTOPp->bitty_core__DOT__reg3__DOT__reg_d_out;
    vlTOPp->reg_4 = vlTOPp->bitty_core__DOT__reg4__DOT__reg_d_out;
    vlTOPp->reg_5 = vlTOPp->bitty_core__DOT__reg5__DOT__reg_d_out;
    vlTOPp->reg_6 = vlTOPp->bitty_core__DOT__reg6__DOT__reg_d_out;
    vlTOPp->reg_7 = vlTOPp->bitty_core__DOT__reg7__DOT__reg_d_out;
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_i = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_en_i = 1U;
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
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel 
                    = (0xfU & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                               >> 3U));
            }
        }
    }
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                             >> 0xaU));
            }
        } else {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                             >> 0xdU));
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
    vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_mode = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__current_state)))) {
                vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_mode 
                    = (1U & ((IData)(vlTOPp->bitty_core__DOT__reg_inst__DOT__reg_d_out) 
                             >> 2U));
            }
        }
    }
    vlTOPp->done = vlTOPp->bitty_core__DOT__cu01__DOT__reg_done;
    vlTOPp->bitty_core__DOT__mux_out = ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                         ? ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                 ? (IData)(vlTOPp->reg_07)
                                                 : (IData)(vlTOPp->reg_06))
                                             : ((1U 
                                                 & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                 ? (IData)(vlTOPp->reg_05)
                                                 : (IData)(vlTOPp->reg_04)))
                                         : ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                 ? (IData)(vlTOPp->reg_03)
                                                 : (IData)(vlTOPp->reg_02))
                                             : ((1U 
                                                 & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_mux_sel))
                                                 ? (IData)(vlTOPp->reg_01)
                                                 : (IData)(vlTOPp->reg_00))));
    if ((8U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))) {
        vlTOPp->bitty_core__DOT__alu01__DOT__alu1__DOT__lu01__DOT__lo_out_temp 
            = (0xffffU & ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out)
                                   : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      | (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                               : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      | (~ (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                   : 0xffffU)) : ((2U 
                                                   & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                                    ? 
                                                   ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                                    & (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                                    : (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                                     ^ (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                                    : 
                                                   ((~ (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out)) 
                                                    | (IData)(vlTOPp->bitty_core__DOT__mux_out))))));
        vlTOPp->bitty_core__DOT__alu01__DOT__alu1__DOT__au01__DOT__ar_out_temp 
            = (0xffffU & ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      - (IData)(1U))
                                   : (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                       | (~ (IData)(vlTOPp->bitty_core__DOT__mux_out))) 
                                      + (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out)))
                               : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                       | (IData)(vlTOPp->bitty_core__DOT__mux_out)) 
                                      + (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out))
                                   : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      + (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out))))
                           : ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                       & (IData)(vlTOPp->bitty_core__DOT__mux_out)) 
                                      - (IData)(1U))
                                   : (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                       | (~ (IData)(vlTOPp->bitty_core__DOT__mux_out))) 
                                      + ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                         & (IData)(vlTOPp->bitty_core__DOT__mux_out))))
                               : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      + (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                   : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      + ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                         & (IData)(vlTOPp->bitty_core__DOT__mux_out)))))));
    } else {
        vlTOPp->bitty_core__DOT__alu01__DOT__alu1__DOT__lu01__DOT__lo_out_temp 
            = (0xffffU & ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      & (~ (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                   : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      ^ (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                               : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? (~ (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                   : (~ ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                         & (IData)(vlTOPp->bitty_core__DOT__mux_out)))))
                           : ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? 0U : ((~ (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out)) 
                                           & (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                               : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? (~ ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                         | (IData)(vlTOPp->bitty_core__DOT__mux_out)))
                                   : (~ (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out))))));
        vlTOPp->bitty_core__DOT__alu01__DOT__alu1__DOT__au01__DOT__ar_out_temp 
            = (0xffffU & ((4U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                       & (~ (IData)(vlTOPp->bitty_core__DOT__mux_out))) 
                                      - (IData)(1U))
                                   : (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                       - (IData)(vlTOPp->bitty_core__DOT__mux_out)) 
                                      - (IData)(1U)))
                               : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? (((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                       | (IData)(vlTOPp->bitty_core__DOT__mux_out)) 
                                      + ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                         & (~ (IData)(vlTOPp->bitty_core__DOT__mux_out))))
                                   : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      | ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                         & (~ (IData)(vlTOPp->bitty_core__DOT__mux_out))))))
                           : ((2U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? 0xffffU : ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                                | (~ (IData)(vlTOPp->bitty_core__DOT__mux_out))))
                               : ((1U & (IData)(vlTOPp->bitty_core__DOT__cu01__DOT__reg_alu_sel))
                                   ? ((IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out) 
                                      | (IData)(vlTOPp->bitty_core__DOT__mux_out))
                                   : (IData)(vlTOPp->bitty_core__DOT__reg_s__DOT__reg_d_out)))));
    }
}

void Vbitty_core::_eval_initial(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_initial\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbitty_core::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::final\n"); );
    // Variables
    Vbitty_core__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbitty_core::_eval_settle(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_settle\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vbitty_core::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_ctor_var_reset\n"); );
    // Body
    reset = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    instruction = VL_RAND_RESET_I(16);
    run = VL_RAND_RESET_I(1);
    reg_00 = VL_RAND_RESET_I(16);
    reg_01 = VL_RAND_RESET_I(16);
    reg_02 = VL_RAND_RESET_I(16);
    reg_03 = VL_RAND_RESET_I(16);
    reg_04 = VL_RAND_RESET_I(16);
    reg_05 = VL_RAND_RESET_I(16);
    reg_06 = VL_RAND_RESET_I(16);
    reg_07 = VL_RAND_RESET_I(16);
    done = VL_RAND_RESET_I(1);
    reg_0 = VL_RAND_RESET_I(16);
    reg_1 = VL_RAND_RESET_I(16);
    reg_2 = VL_RAND_RESET_I(16);
    reg_3 = VL_RAND_RESET_I(16);
    reg_4 = VL_RAND_RESET_I(16);
    reg_5 = VL_RAND_RESET_I(16);
    reg_6 = VL_RAND_RESET_I(16);
    reg_7 = VL_RAND_RESET_I(16);
    bitty_core__DOT__mux_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg_inst__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg0__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg1__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg2__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg3__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg4__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg5__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg6__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg7__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__cu01__DOT__current_state = VL_RAND_RESET_I(2);
    bitty_core__DOT__cu01__DOT__next_state = VL_RAND_RESET_I(2);
    bitty_core__DOT__cu01__DOT__reg_alu_sel = VL_RAND_RESET_I(4);
    bitty_core__DOT__cu01__DOT__reg_mux_sel = VL_RAND_RESET_I(3);
    bitty_core__DOT__cu01__DOT__reg_en_c = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_0 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_1 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_2 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_3 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_4 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_5 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_6 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_7 = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_i = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_en_s = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_done = VL_RAND_RESET_I(1);
    bitty_core__DOT__cu01__DOT__reg_alu_mode = VL_RAND_RESET_I(1);
    bitty_core__DOT__reg_s__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__alu01__DOT__alu1__DOT__lu01__DOT__lo_out_temp = VL_RAND_RESET_I(16);
    bitty_core__DOT__alu01__DOT__alu1__DOT__au01__DOT__ar_out_temp = VL_RAND_RESET_I(16);
    bitty_core__DOT__reg_c__DOT__reg_d_out = VL_RAND_RESET_I(16);
    __Vtableidx1 = 0;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[0] = 0U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[1] = 1U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[2] = 2U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[3] = 3U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[4] = 0U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[5] = 1U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[6] = 2U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[7] = 3U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[8] = 1U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[9] = 2U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[10] = 3U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[11] = 0U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[12] = 0U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[13] = 1U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[14] = 2U;
    __Vtable1_bitty_core__DOT__cu01__DOT__next_state[15] = 3U;
}
