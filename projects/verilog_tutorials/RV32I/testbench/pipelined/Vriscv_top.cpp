// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top.h"
#include "Vriscv_top__Syms.h"

//==========

void Vriscv_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_top::eval\n"); );
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/limh/projects/verilog_tutorials/RV32I/core/pipelined/riscv_top.v", 16, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv_top::_eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("/home/limh/projects/verilog_tutorials/RV32I/core/pipelined/riscv_top.v", 16, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__2(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__2\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__riscv_top__DOT__id_pc;
    IData/*31:0*/ __Vdly__riscv_top__DOT__id_pc_plus_4;
    // Body
    __Vdly__riscv_top__DOT__id_pc = vlTOPp->riscv_top__DOT__id_pc;
    __Vdly__riscv_top__DOT__id_pc_plus_4 = vlTOPp->riscv_top__DOT__id_pc_plus_4;
    vlTOPp->__Vdly__riscv_top__DOT__id_instr = vlTOPp->riscv_top__DOT__id_instr;
    if (vlTOPp->i_rstn) {
        __Vdly__riscv_top__DOT__id_pc = ((IData)(vlTOPp->riscv_top__DOT__id_flush)
                                          ? 0U : ((IData)(vlTOPp->riscv_top__DOT__id_stall)
                                                   ? vlTOPp->riscv_top__DOT__id_pc
                                                   : vlTOPp->o_riscv_imem_pc));
        __Vdly__riscv_top__DOT__id_pc_plus_4 = ((IData)(vlTOPp->riscv_top__DOT__id_flush)
                                                 ? 0U
                                                 : 
                                                ((IData)(vlTOPp->riscv_top__DOT__id_stall)
                                                  ? vlTOPp->riscv_top__DOT__id_pc_plus_4
                                                  : 
                                                 ((IData)(4U) 
                                                  + vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc)));
        vlTOPp->riscv_top__DOT__mem_ctrl_byte_sel = vlTOPp->riscv_top__DOT__ex_ctrl_byte_sel;
        vlTOPp->riscv_top__DOT__ex_ctrl_jump = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                                 ? 0U
                                                 : 
                                                ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr))
                                                  ? 1U
                                                  : 
                                                 ((0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->riscv_top__DOT__id_instr))
                                                   ? 2U
                                                   : 0U)));
        vlTOPp->riscv_top__DOT__ex_ctrl_branch = ((
                                                   (~ (IData)(vlTOPp->riscv_top__DOT__ex_flush)) 
                                                   & (0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->riscv_top__DOT__id_instr))) 
                                                  & 1U);
        vlTOPp->__Vdly__riscv_top__DOT__id_instr = 
            ((IData)(vlTOPp->riscv_top__DOT__id_flush)
              ? 0U : ((IData)(vlTOPp->riscv_top__DOT__id_stall)
                       ? vlTOPp->riscv_top__DOT__id_instr
                       : vlTOPp->o_riscv_imem_instr));
        vlTOPp->riscv_top__DOT__ex_pc = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                          ? 0U : vlTOPp->riscv_top__DOT__id_pc);
        vlTOPp->riscv_top__DOT__mem_funct3 = vlTOPp->riscv_top__DOT__ex_funct3;
        vlTOPp->riscv_top__DOT__ex_ctrl_alu_control 
            = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                ? 0U : (IData)(vlTOPp->riscv_top__DOT__id_ctrl_alu_control));
        vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc 
            = (((((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                            >> 0xfU)) == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr)) 
                 | ((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                              >> 0x14U)) == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr))) 
                & (~ (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src)))
                ? vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc
                : ((2U >= (IData)(vlTOPp->riscv_top__DOT__ex_src_pc))
                    ? vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                   [vlTOPp->riscv_top__DOT__ex_src_pc]
                    : 0U));
        vlTOPp->riscv_top__DOT__ex_ctrl_alu_b_src = 
            (((~ (IData)(vlTOPp->riscv_top__DOT__ex_flush)) 
              & (~ ((0x33U == (0x7fU & vlTOPp->riscv_top__DOT__id_instr)) 
                    | (0x63U == (0x7fU & vlTOPp->riscv_top__DOT__id_instr))))) 
             & 1U);
        vlTOPp->riscv_top__DOT__ex_rs1_addr = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                                ? 0U
                                                : (0x1fU 
                                                   & (vlTOPp->riscv_top__DOT__id_instr 
                                                      >> 0xfU)));
        vlTOPp->riscv_top__DOT__mem_write_data = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__src_rs2_data;
        vlTOPp->riscv_top__DOT__ex_rs1_data = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                                ? 0U
                                                : vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers
                                               [(0x1fU 
                                                 & (vlTOPp->riscv_top__DOT__id_instr 
                                                    >> 0xfU))]);
        vlTOPp->riscv_top__DOT__ex_rs2_addr = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                                ? 0U
                                                : (0x1fU 
                                                   & (vlTOPp->riscv_top__DOT__id_instr 
                                                      >> 0x14U)));
        vlTOPp->riscv_top__DOT__ex_rs2_data = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                                ? 0U
                                                : vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers
                                               [(0x1fU 
                                                 & (vlTOPp->riscv_top__DOT__id_instr 
                                                    >> 0x14U))]);
        vlTOPp->riscv_top__DOT__mem_ctrl_result_src 
            = vlTOPp->riscv_top__DOT__ex_ctrl_result_src;
        vlTOPp->riscv_top__DOT__wb_ctrl_rd_src = ((IData)(vlTOPp->riscv_top__DOT__mem_ctrl_rd_src) 
                                                  & 1U);
        vlTOPp->riscv_top__DOT__wb_read_data = vlTOPp->riscv_top__DOT__mem_read_data;
        vlTOPp->riscv_top__DOT__wb_rd_result = vlTOPp->riscv_top__DOT__mem_rd_result;
        vlTOPp->riscv_top__DOT__mem_pc_plus_4 = vlTOPp->riscv_top__DOT__ex_pc_plus_4;
        vlTOPp->riscv_top__DOT__mem_pc_plus_imm = vlTOPp->riscv_top__DOT__ex_pc_plus_imm;
        vlTOPp->riscv_top__DOT__mem_imm = vlTOPp->riscv_top__DOT__ex_imm;
    } else {
        __Vdly__riscv_top__DOT__id_pc = 0U;
        __Vdly__riscv_top__DOT__id_pc_plus_4 = 0U;
        vlTOPp->riscv_top__DOT__mem_ctrl_byte_sel = 0U;
        vlTOPp->riscv_top__DOT__ex_ctrl_jump = 0U;
        vlTOPp->riscv_top__DOT__ex_ctrl_branch = 0U;
        vlTOPp->__Vdly__riscv_top__DOT__id_instr = 0U;
        vlTOPp->riscv_top__DOT__ex_pc = 0U;
        vlTOPp->riscv_top__DOT__mem_funct3 = 0U;
        vlTOPp->riscv_top__DOT__ex_ctrl_alu_control = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc = 0U;
        vlTOPp->riscv_top__DOT__ex_ctrl_alu_b_src = 0U;
        vlTOPp->riscv_top__DOT__ex_rs1_addr = 0U;
        vlTOPp->riscv_top__DOT__mem_write_data = 0U;
        vlTOPp->riscv_top__DOT__ex_rs1_data = 0U;
        vlTOPp->riscv_top__DOT__ex_rs2_addr = 0U;
        vlTOPp->riscv_top__DOT__ex_rs2_data = 0U;
        vlTOPp->riscv_top__DOT__mem_ctrl_result_src = 0U;
        vlTOPp->riscv_top__DOT__wb_ctrl_rd_src = 0U;
        vlTOPp->riscv_top__DOT__wb_read_data = 0U;
        vlTOPp->riscv_top__DOT__wb_rd_result = 0U;
        vlTOPp->riscv_top__DOT__mem_pc_plus_4 = 0U;
        vlTOPp->riscv_top__DOT__mem_pc_plus_imm = 0U;
        vlTOPp->riscv_top__DOT__mem_imm = 0U;
    }
    vlTOPp->riscv_top__DOT__id_pc = __Vdly__riscv_top__DOT__id_pc;
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__ex_ctrl_byte_sel = 
            ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
              ? 0U : (((0x23U == (0x7fU & vlTOPp->riscv_top__DOT__id_instr)) 
                       | (3U == (0x7fU & vlTOPp->riscv_top__DOT__id_instr)))
                       ? ((0x4000U & vlTOPp->riscv_top__DOT__id_instr)
                           ? ((0x2000U & vlTOPp->riscv_top__DOT__id_instr)
                               ? 0xfU : ((0x1000U & vlTOPp->riscv_top__DOT__id_instr)
                                          ? 3U : 1U))
                           : ((0x2000U & vlTOPp->riscv_top__DOT__id_instr)
                               ? 0xfU : ((0x1000U & vlTOPp->riscv_top__DOT__id_instr)
                                          ? 3U : 1U)))
                       : 0xfU));
        vlTOPp->riscv_top__DOT__ex_funct3 = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                              ? 0U : 
                                             (7U & 
                                              (vlTOPp->riscv_top__DOT__id_instr 
                                               >> 0xcU)));
    } else {
        vlTOPp->riscv_top__DOT__ex_ctrl_byte_sel = 0U;
        vlTOPp->riscv_top__DOT__ex_funct3 = 0U;
    }
    vlTOPp->__Vtableidx5 = vlTOPp->riscv_top__DOT__ex_ctrl_alu_control;
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP 
        = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_ex__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP
        [vlTOPp->__Vtableidx5];
    vlTOPp->o_riscv_imem_pc = vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc;
    vlTOPp->o_riscv_imem_instr = vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_imem__DOT__imem_arr
        [(0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc 
                     >> 2U))];
    vlTOPp->o_riscv_dmem_wr_data = vlTOPp->riscv_top__DOT__mem_write_data;
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__ex_ctrl_result_src 
            = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                ? 0U : (IData)(vlTOPp->riscv_top__DOT__id_ctrl_result_src));
        vlTOPp->riscv_top__DOT__mem_ctrl_rd_src = ((IData)(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src) 
                                                   & 1U);
    } else {
        vlTOPp->riscv_top__DOT__ex_ctrl_result_src = 0U;
        vlTOPp->riscv_top__DOT__mem_ctrl_rd_src = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__mux_concat_rd 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__wb_rd_result)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__wb_read_data)));
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__ex_pc_plus_4 = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                                 ? 0U
                                                 : vlTOPp->riscv_top__DOT__id_pc_plus_4);
        vlTOPp->riscv_top__DOT__ex_imm = ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                           ? 0U : vlTOPp->riscv_top__DOT__id_imm);
    } else {
        vlTOPp->riscv_top__DOT__ex_pc_plus_4 = 0U;
        vlTOPp->riscv_top__DOT__ex_imm = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__mux_concat_rd);
    vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__mux_concat_rd 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__id_pc_plus_4 = __Vdly__riscv_top__DOT__id_pc_plus_4;
    vlTOPp->riscv_top__DOT__ex_ctrl_rd_src = ((IData)(vlTOPp->i_rstn) 
                                              & ((~ (IData)(vlTOPp->riscv_top__DOT__ex_flush)) 
                                                 & (3U 
                                                    != 
                                                    (0x7fU 
                                                     & vlTOPp->riscv_top__DOT__id_instr))));
    vlTOPp->riscv_top__DOT__ex_pc_plus_imm = (vlTOPp->riscv_top__DOT__ex_pc 
                                              + vlTOPp->riscv_top__DOT__ex_imm);
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__3\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->riscv_top__DOT__wb_ctrl_reg_write) 
         & (0U != (IData)(vlTOPp->riscv_top__DOT__wb_rd_addr)))) {
        vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[vlTOPp->riscv_top__DOT__wb_rd_addr] 
            = vlTOPp->riscv_top__DOT__wb_rd_data;
    }
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__4(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__4\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    // Body
    if (vlTOPp->riscv_top__DOT__mem_ctrl_mem_write) {
        vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__i = 4U;
    }
    __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 0U;
    if (vlTOPp->riscv_top__DOT__mem_ctrl_mem_write) {
        if ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0xffU & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data);
            __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                              >> 2U));
        }
        if ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0xffU & (vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data 
                            >> 8U));
            __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 8U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                              >> 2U));
        }
        if ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0xffU & (vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data 
                            >> 0x10U));
            __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0x10U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                              >> 2U));
        }
        if ((8U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0xffU & (vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data 
                            >> 0x18U));
            __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0x18U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                              >> 2U));
        }
    } else {
        __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
            [(0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                         >> 2U))];
        __Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 1U;
        __Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = (0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                          >> 2U));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0) {
        vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0))) 
                & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v0)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1) {
        vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1))) 
                & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v1)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2) {
        vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2))) 
                & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v2)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3) {
        vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3))) 
                & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v3)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4) {
        vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4] 
            = __Vdlyvval__riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    }
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__6(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__6\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->riscv_top__DOT__wb_rd_data = vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__wb_ctrl_rd_src];
    vlTOPp->riscv_top__DOT__wb_ctrl_reg_write = ((IData)(vlTOPp->i_rstn) 
                                                 & (IData)(vlTOPp->riscv_top__DOT__mem_ctrl_reg_write));
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__wb_rd_addr = vlTOPp->riscv_top__DOT__mem_rd_addr;
        vlTOPp->riscv_top__DOT__mem_ctrl_mem_write 
            = ((IData)(vlTOPp->riscv_top__DOT__ex_ctrl_mem_write) 
               & 1U);
        vlTOPp->riscv_top__DOT__mem_alu_result = vlTOPp->riscv_top__DOT__ex_alu_result;
        vlTOPp->riscv_top__DOT__mem_ctrl_reg_write 
            = ((IData)(vlTOPp->riscv_top__DOT__ex_ctrl_reg_write) 
               & 1U);
        vlTOPp->riscv_top__DOT__mem_rd_addr = vlTOPp->riscv_top__DOT__ex_rd_addr;
    } else {
        vlTOPp->riscv_top__DOT__wb_rd_addr = 0U;
        vlTOPp->riscv_top__DOT__mem_ctrl_mem_write = 0U;
        vlTOPp->riscv_top__DOT__mem_alu_result = 0U;
        vlTOPp->riscv_top__DOT__mem_ctrl_reg_write = 0U;
        vlTOPp->riscv_top__DOT__mem_rd_addr = 0U;
    }
    vlTOPp->o_riscv_dmem_wr_en = vlTOPp->riscv_top__DOT__mem_ctrl_mem_write;
    vlTOPp->riscv_top__DOT__ex_ctrl_mem_write = ((IData)(vlTOPp->i_rstn) 
                                                 & ((~ (IData)(vlTOPp->riscv_top__DOT__ex_flush)) 
                                                    & (0x23U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->riscv_top__DOT__id_instr))));
    vlTOPp->o_riscv_dmem_addr = vlTOPp->riscv_top__DOT__mem_alu_result;
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data 
        = ((0x1fU >= (0x18U & (vlTOPp->riscv_top__DOT__mem_alu_result 
                               << 3U))) ? (vlTOPp->riscv_top__DOT__mem_write_data 
                                           << (0x18U 
                                               & (vlTOPp->riscv_top__DOT__mem_alu_result 
                                                  << 3U)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel 
        = ((3U >= (3U & vlTOPp->riscv_top__DOT__mem_alu_result))
            ? (0xfU & ((IData)(vlTOPp->riscv_top__DOT__mem_ctrl_byte_sel) 
                       << (3U & vlTOPp->riscv_top__DOT__mem_alu_result)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
        = ((0x1fU >= (0x18U & (vlTOPp->riscv_top__DOT__mem_alu_result 
                               << 3U))) ? (vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
                                           [(0x3fffU 
                                             & (vlTOPp->riscv_top__DOT__mem_alu_result 
                                                >> 2U))] 
                                           >> (0x18U 
                                               & (vlTOPp->riscv_top__DOT__mem_alu_result 
                                                  << 3U)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[0U] 
        = vlTOPp->riscv_top__DOT__mem_alu_result;
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[1U] 
        = vlTOPp->riscv_top__DOT__mem_imm;
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[2U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__mem_pc_plus_4)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__mem_pc_plus_imm))));
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[3U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__mem_pc_plus_4)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__mem_pc_plus_imm))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__mem_read_data = ((4U & (IData)(vlTOPp->riscv_top__DOT__mem_funct3))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->riscv_top__DOT__mem_funct3))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__mem_funct3))
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                              : ((2U 
                                                  & (IData)(vlTOPp->riscv_top__DOT__mem_funct3))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__mem_funct3))
                                                   ? 0U
                                                   : vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__mem_funct3))
                                                   ? 
                                                  ((0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                      >> 0xfU)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                                   : 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))));
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[0U];
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[1U];
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[2U];
    vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[3U] 
        = vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[3U];
    vlTOPp->riscv_top__DOT__ex_ctrl_reg_write = ((IData)(vlTOPp->i_rstn) 
                                                 & ((~ (IData)(vlTOPp->riscv_top__DOT__ex_flush)) 
                                                    & (~ 
                                                       ((0x63U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->riscv_top__DOT__id_instr)) 
                                                        | (0x23U 
                                                           == 
                                                           (0x7fU 
                                                            & vlTOPp->riscv_top__DOT__id_instr))))));
    vlTOPp->riscv_top__DOT__ex_rd_addr = ((IData)(vlTOPp->i_rstn)
                                           ? ((IData)(vlTOPp->riscv_top__DOT__ex_flush)
                                               ? 0U
                                               : (0x1fU 
                                                  & (vlTOPp->riscv_top__DOT__id_instr 
                                                     >> 7U)))
                                           : 0U);
    vlTOPp->riscv_top__DOT__forwardAE = ((((IData)(vlTOPp->riscv_top__DOT__mem_ctrl_reg_write) 
                                           & (0U != (IData)(vlTOPp->riscv_top__DOT__mem_rd_addr))) 
                                          & ((IData)(vlTOPp->riscv_top__DOT__ex_rs1_addr) 
                                             == (IData)(vlTOPp->riscv_top__DOT__mem_rd_addr)))
                                          ? 2U : ((
                                                   ((IData)(vlTOPp->riscv_top__DOT__wb_ctrl_reg_write) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->riscv_top__DOT__wb_rd_addr))) 
                                                   & ((IData)(vlTOPp->riscv_top__DOT__ex_rs1_addr) 
                                                      == (IData)(vlTOPp->riscv_top__DOT__wb_rd_addr)))
                                                   ? 1U
                                                   : 0U));
    vlTOPp->riscv_top__DOT__forwardBE = ((((IData)(vlTOPp->riscv_top__DOT__mem_ctrl_reg_write) 
                                           & (0U != (IData)(vlTOPp->riscv_top__DOT__mem_rd_addr))) 
                                          & ((IData)(vlTOPp->riscv_top__DOT__ex_rs2_addr) 
                                             == (IData)(vlTOPp->riscv_top__DOT__mem_rd_addr)))
                                          ? 2U : ((
                                                   ((IData)(vlTOPp->riscv_top__DOT__wb_ctrl_reg_write) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->riscv_top__DOT__wb_rd_addr))) 
                                                   & ((IData)(vlTOPp->riscv_top__DOT__ex_rs2_addr) 
                                                      == (IData)(vlTOPp->riscv_top__DOT__wb_rd_addr)))
                                                   ? 1U
                                                   : 0U));
    vlTOPp->o_riscv_dmem_rd_data = vlTOPp->riscv_top__DOT__mem_read_data;
    vlTOPp->riscv_top__DOT__mem_rd_result = vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__mem_ctrl_result_src];
    vlTOPp->riscv_top__DOT__id_instr = vlTOPp->__Vdly__riscv_top__DOT__id_instr;
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1[0U] 
        = vlTOPp->riscv_top__DOT__ex_rs1_data;
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__mem_rd_result)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__wb_rd_data))));
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__mem_rd_result)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__wb_rd_data))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2[0U] 
        = vlTOPp->riscv_top__DOT__ex_rs2_data;
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__mem_rd_result)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__wb_rd_data))));
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__mem_rd_result)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__wb_rd_data))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__id_ctrl_alu_control = (
                                                   ((0x33U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->riscv_top__DOT__id_instr)) 
                                                    | (0x13U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->riscv_top__DOT__id_instr)))
                                                    ? 
                                                   ((0x4000U 
                                                     & vlTOPp->riscv_top__DOT__id_instr)
                                                     ? 
                                                    ((0x2000U 
                                                      & vlTOPp->riscv_top__DOT__id_instr)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlTOPp->riscv_top__DOT__id_instr)
                                                       ? 7U
                                                       : 6U)
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->riscv_top__DOT__id_instr)
                                                       ? 
                                                      ((0x40000000U 
                                                        & vlTOPp->riscv_top__DOT__id_instr)
                                                        ? 0xdU
                                                        : 5U)
                                                       : 4U))
                                                     : 
                                                    ((0x2000U 
                                                      & vlTOPp->riscv_top__DOT__id_instr)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlTOPp->riscv_top__DOT__id_instr)
                                                       ? 3U
                                                       : 2U)
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->riscv_top__DOT__id_instr)
                                                       ? 1U
                                                       : 
                                                      (((0x33U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->riscv_top__DOT__id_instr)) 
                                                        & (vlTOPp->riscv_top__DOT__id_instr 
                                                           >> 0x1eU))
                                                        ? 8U
                                                        : 0U))))
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->riscv_top__DOT__id_instr))
                                                     ? 
                                                    ((0x4000U 
                                                      & vlTOPp->riscv_top__DOT__id_instr)
                                                      ? 
                                                     ((0x2000U 
                                                       & vlTOPp->riscv_top__DOT__id_instr)
                                                       ? 3U
                                                       : 2U)
                                                      : 
                                                     ((0x2000U 
                                                       & vlTOPp->riscv_top__DOT__id_instr)
                                                       ? 0xfU
                                                       : 8U))
                                                     : 0U));
    vlTOPp->riscv_top__DOT__id_stall = ((((0x1fU & 
                                           (vlTOPp->riscv_top__DOT__id_instr 
                                            >> 0xfU)) 
                                          == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr)) 
                                         | ((0x1fU 
                                             & (vlTOPp->riscv_top__DOT__id_instr 
                                                >> 0x14U)) 
                                            == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr))) 
                                        & (~ (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src)));
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->riscv_top__DOT__id_instr);
    vlTOPp->riscv_top__DOT__id_ctrl_result_src = vlTOPp->__Vtable1_riscv_top__DOT__id_ctrl_result_src
        [vlTOPp->__Vtableidx1];
    vlTOPp->__Vtableidx3 = ((0x400U & (vlTOPp->riscv_top__DOT__id_instr 
                                       >> 0x14U)) | 
                            ((0x380U & (vlTOPp->riscv_top__DOT__id_instr 
                                        >> 5U)) | (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr)));
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[0U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][0U];
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[1U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][1U];
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[2U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][2U];
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[3U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][3U];
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[4U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][4U];
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[5U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][5U];
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[6U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][6U];
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[7U] 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx3][7U];
    vlTOPp->__Vtableidx2 = (0x7fU & vlTOPp->riscv_top__DOT__id_instr);
    vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src 
        = vlTOPp->__Vtable2_riscv_top__DOT__u_riscv_id__DOT__id_imm_src
        [vlTOPp->__Vtableidx2];
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1[0U];
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1[1U];
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1[2U];
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2[0U];
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2[1U];
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2[2U];
    vlTOPp->riscv_top__DOT__id_imm = ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src))
                                       ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src))
                                           ? 0U : (
                                                   (1U 
                                                    & (IData)(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlTOPp->riscv_top__DOT__id_instr)
                                                    : 
                                                   ((0xfff00000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->riscv_top__DOT__id_instr 
                                                                       >> 0x1fU)))) 
                                                        << 0x14U)) 
                                                    | ((0xff000U 
                                                        & vlTOPp->riscv_top__DOT__id_instr) 
                                                       | ((0x800U 
                                                           & (vlTOPp->riscv_top__DOT__id_instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (vlTOPp->riscv_top__DOT__id_instr 
                                                                >> 0x14U)))))))
                                       : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src))
                                           ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src))
                                               ? ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->riscv_top__DOT__id_instr 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (vlTOPp->riscv_top__DOT__id_instr 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlTOPp->riscv_top__DOT__id_instr 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlTOPp->riscv_top__DOT__id_instr 
                                                              >> 7U)))))
                                               : ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->riscv_top__DOT__id_instr 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0xfe0U 
                                                      & (vlTOPp->riscv_top__DOT__id_instr 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->riscv_top__DOT__id_instr 
                                                           >> 7U)))))
                                           : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src))
                                               ? ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->riscv_top__DOT__id_instr 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | (0xfffU 
                                                     & (vlTOPp->riscv_top__DOT__id_instr 
                                                        >> 0x14U)))
                                               : 0U)));
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
        = ((2U >= (IData)(vlTOPp->riscv_top__DOT__forwardAE))
            ? vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__forwardAE] : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__src_rs2_data 
        = ((2U >= (IData)(vlTOPp->riscv_top__DOT__forwardBE))
            ? vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__forwardBE] : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_alu_b 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__ex_imm)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__src_rs2_data)));
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_alu_b);
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_alu_b 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b 
        = vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__ex_ctrl_alu_b_src];
    vlTOPp->riscv_top__DOT__ex_alu_result = ((8U & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                              ? ((4U 
                                                  & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,5, vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a, 
                                                                  (0x1fU 
                                                                   & vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b))
                                                    : 0U))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                    ? 0U
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                    - vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b))))
                                              : ((4U 
                                                  & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                    ? 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b)
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                    | vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                    ? 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                    >> 
                                                    (0x1fU 
                                                     & vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b))
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                    ^ vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                    ? 
                                                   ((vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                     < vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   (VL_LTS_III(1,32,32, vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a, vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b)
                                                     ? 1U
                                                     : 0U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control))
                                                    ? 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                    << 
                                                    (0x1fU 
                                                     & vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b))
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a 
                                                    + vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b)))));
    vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc[0U] 
        = ((IData)(4U) + vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc);
    vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__ex_alu_result)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__ex_pc_plus_imm))));
    vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__ex_alu_result)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__ex_pc_plus_imm))) 
                   >> 0x20U));
    vlTOPp->__Vtableidx4 = (((0U == vlTOPp->riscv_top__DOT__ex_alu_result) 
                             << 3U) | (IData)(vlTOPp->riscv_top__DOT__ex_funct3));
    vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__take_branch 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_ex__DOT__take_branch
        [vlTOPp->__Vtableidx4];
    vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc[0U];
    vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc[1U];
    vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc[2U];
    vlTOPp->riscv_top__DOT__ex_src_pc = (((IData)(vlTOPp->riscv_top__DOT__ex_ctrl_branch) 
                                          & (IData)(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__take_branch))
                                          ? 1U : ((1U 
                                                   == (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_jump))
                                                   ? 1U
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_jump))
                                                    ? 2U
                                                    : 0U)));
    vlTOPp->riscv_top__DOT__id_flush = ((1U == (IData)(vlTOPp->riscv_top__DOT__ex_src_pc)) 
                                        | (2U == (IData)(vlTOPp->riscv_top__DOT__ex_src_pc)));
    vlTOPp->riscv_top__DOT__ex_flush = ((1U == (IData)(vlTOPp->riscv_top__DOT__ex_src_pc)) 
                                        | (2U == (IData)(vlTOPp->riscv_top__DOT__ex_src_pc)));
}

void Vriscv_top::_eval(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((~ (IData)(vlTOPp->i_clk)) & (IData)(vlTOPp->__Vclklast__TOP__i_clk))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__i_rstn = vlTOPp->i_rstn;
}

VL_INLINE_OPT QData Vriscv_top::_change_request(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vriscv_top::_change_request_1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request_1\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vriscv_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_rstn & 0xfeU))) {
        Verilated::overWidthError("i_rstn");}
}
#endif  // VL_DEBUG
