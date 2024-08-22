// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


void Vriscv_top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vriscv_top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgWData(oldp+0,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
            tracep->chgWData(oldp+32,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+64,(((IData)(4U) 
                                       + vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc)),32);
            tracep->chgIData(oldp+65,(vlTOPp->riscv_top__DOT__id_pc),32);
            tracep->chgIData(oldp+66,(vlTOPp->riscv_top__DOT__id_pc_plus_4),32);
            tracep->chgCData(oldp+67,(vlTOPp->riscv_top__DOT__ex_ctrl_result_src),2);
            tracep->chgCData(oldp+68,(vlTOPp->riscv_top__DOT__ex_ctrl_jump),2);
            tracep->chgBit(oldp+69,(vlTOPp->riscv_top__DOT__ex_ctrl_branch));
            tracep->chgCData(oldp+70,(vlTOPp->riscv_top__DOT__ex_ctrl_byte_sel),4);
            tracep->chgCData(oldp+71,(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control),4);
            tracep->chgBit(oldp+72,(vlTOPp->riscv_top__DOT__ex_ctrl_alu_b_src));
            tracep->chgBit(oldp+73,(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src));
            tracep->chgIData(oldp+74,(vlTOPp->riscv_top__DOT__ex_rs1_data),32);
            tracep->chgIData(oldp+75,(vlTOPp->riscv_top__DOT__ex_rs2_data),32);
            tracep->chgCData(oldp+76,(vlTOPp->riscv_top__DOT__ex_rs1_addr),5);
            tracep->chgCData(oldp+77,(vlTOPp->riscv_top__DOT__ex_rs2_addr),5);
            tracep->chgIData(oldp+78,(vlTOPp->riscv_top__DOT__ex_pc),32);
            tracep->chgIData(oldp+79,(vlTOPp->riscv_top__DOT__ex_pc_plus_4),32);
            tracep->chgIData(oldp+80,(vlTOPp->riscv_top__DOT__ex_imm),32);
            tracep->chgIData(oldp+81,(vlTOPp->riscv_top__DOT__ex_pc_plus_imm),32);
            tracep->chgBit(oldp+82,(vlTOPp->riscv_top__DOT__mem_ctrl_rd_src));
            tracep->chgCData(oldp+83,(vlTOPp->riscv_top__DOT__mem_ctrl_result_src),2);
            tracep->chgCData(oldp+84,(vlTOPp->riscv_top__DOT__mem_ctrl_byte_sel),4);
            tracep->chgIData(oldp+85,(vlTOPp->riscv_top__DOT__mem_imm),32);
            tracep->chgIData(oldp+86,(vlTOPp->riscv_top__DOT__mem_pc_plus_4),32);
            tracep->chgIData(oldp+87,(vlTOPp->riscv_top__DOT__mem_pc_plus_imm),32);
            tracep->chgIData(oldp+88,(vlTOPp->riscv_top__DOT__mem_write_data),32);
            tracep->chgIData(oldp+89,(vlTOPp->riscv_top__DOT__wb_read_data),32);
            tracep->chgCData(oldp+90,(vlTOPp->riscv_top__DOT__ex_funct3),3);
            tracep->chgCData(oldp+91,(vlTOPp->riscv_top__DOT__mem_funct3),3);
            tracep->chgBit(oldp+92,(vlTOPp->riscv_top__DOT__wb_ctrl_rd_src));
            tracep->chgIData(oldp+93,(vlTOPp->riscv_top__DOT__wb_rd_result),32);
            tracep->chgIData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc),32);
            tracep->chgSData(oldp+95,((0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc 
                                                  >> 2U))),14);
            tracep->chgQData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
            tracep->chgQData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__mux_concat_rd),64);
            tracep->chgIData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr[1]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[0]),32);
            tracep->chgIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[1]),32);
            tracep->chgIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[2]),32);
            tracep->chgIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[3]),32);
            tracep->chgIData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[4]),32);
            tracep->chgIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[5]),32);
            tracep->chgIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[6]),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[7]),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[8]),32);
            tracep->chgIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[9]),32);
            tracep->chgIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[10]),32);
            tracep->chgIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[11]),32);
            tracep->chgIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[12]),32);
            tracep->chgIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[13]),32);
            tracep->chgIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[14]),32);
            tracep->chgIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[15]),32);
            tracep->chgIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[16]),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[17]),32);
            tracep->chgIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[18]),32);
            tracep->chgIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[19]),32);
            tracep->chgIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[20]),32);
            tracep->chgIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[21]),32);
            tracep->chgIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[22]),32);
            tracep->chgIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[23]),32);
            tracep->chgIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[24]),32);
            tracep->chgIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[25]),32);
            tracep->chgIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[26]),32);
            tracep->chgIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[27]),32);
            tracep->chgIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[28]),32);
            tracep->chgIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[29]),32);
            tracep->chgIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[30]),32);
            tracep->chgIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+134,(vlTOPp->riscv_top__DOT__id_stall));
            tracep->chgBit(oldp+135,(vlTOPp->riscv_top__DOT__id_flush));
            tracep->chgIData(oldp+136,(vlTOPp->riscv_top__DOT__id_instr),32);
            tracep->chgIData(oldp+137,(vlTOPp->riscv_top__DOT__id_imm),32);
            tracep->chgCData(oldp+138,((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+139,((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                                 >> 0x14U))),5);
            tracep->chgCData(oldp+140,((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                                 >> 7U))),5);
            tracep->chgBit(oldp+141,((1U & (~ ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__id_instr)) 
                                               | (0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr)))))));
            tracep->chgCData(oldp+142,(vlTOPp->riscv_top__DOT__id_ctrl_result_src),2);
            tracep->chgBit(oldp+143,((0x23U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__id_instr))));
            tracep->chgCData(oldp+144,(((0x6fU == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr))
                                         ? 1U : ((0x67U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr))
                                                  ? 2U
                                                  : 0U))),2);
            tracep->chgBit(oldp+145,((0x63U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__id_instr))));
            tracep->chgCData(oldp+146,((((0x23U == 
                                          (0x7fU & vlTOPp->riscv_top__DOT__id_instr)) 
                                         | (3U == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr)))
                                         ? ((0x4000U 
                                             & vlTOPp->riscv_top__DOT__id_instr)
                                             ? ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__id_instr)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__id_instr)
                                                  ? 3U
                                                  : 1U))
                                             : ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__id_instr)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__id_instr)
                                                  ? 3U
                                                  : 1U)))
                                         : 0xfU)),4);
            tracep->chgCData(oldp+147,(vlTOPp->riscv_top__DOT__id_ctrl_alu_control),4);
            tracep->chgBit(oldp+148,((1U & (~ ((0x33U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__id_instr)) 
                                               | (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr)))))));
            tracep->chgBit(oldp+149,((3U != (0x7fU 
                                             & vlTOPp->riscv_top__DOT__id_instr))));
            tracep->chgBit(oldp+150,(vlTOPp->riscv_top__DOT__ex_flush));
            tracep->chgBit(oldp+151,(vlTOPp->riscv_top__DOT__ex_ctrl_reg_write));
            tracep->chgBit(oldp+152,(vlTOPp->riscv_top__DOT__ex_ctrl_mem_write));
            tracep->chgCData(oldp+153,(vlTOPp->riscv_top__DOT__ex_rd_addr),5);
            tracep->chgCData(oldp+154,(vlTOPp->riscv_top__DOT__forwardAE),2);
            tracep->chgCData(oldp+155,(vlTOPp->riscv_top__DOT__forwardBE),2);
            tracep->chgCData(oldp+156,(vlTOPp->riscv_top__DOT__ex_src_pc),2);
            tracep->chgBit(oldp+157,((0U == vlTOPp->riscv_top__DOT__ex_alu_result)));
            tracep->chgIData(oldp+158,(vlTOPp->riscv_top__DOT__ex_alu_result),32);
            tracep->chgIData(oldp+159,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__src_rs2_data),32);
            tracep->chgBit(oldp+160,(vlTOPp->riscv_top__DOT__mem_ctrl_reg_write));
            tracep->chgBit(oldp+161,(vlTOPp->riscv_top__DOT__mem_ctrl_mem_write));
            tracep->chgCData(oldp+162,(vlTOPp->riscv_top__DOT__mem_rd_addr),5);
            tracep->chgIData(oldp+163,(vlTOPp->riscv_top__DOT__mem_alu_result),32);
            tracep->chgIData(oldp+164,(vlTOPp->riscv_top__DOT__mem_rd_result),32);
            tracep->chgIData(oldp+165,(vlTOPp->riscv_top__DOT__mem_read_data),32);
            tracep->chgBit(oldp+166,(vlTOPp->riscv_top__DOT__wb_ctrl_reg_write));
            tracep->chgCData(oldp+167,(vlTOPp->riscv_top__DOT__wb_rd_addr),5);
            tracep->chgIData(oldp+168,(vlTOPp->riscv_top__DOT__wb_rd_data),32);
            tracep->chgCData(oldp+169,((7U & (vlTOPp->riscv_top__DOT__id_instr 
                                              >> 0xcU))),3);
            tracep->chgWData(oldp+170,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc),96);
            tracep->chgIData(oldp+173,(((2U >= (IData)(vlTOPp->riscv_top__DOT__ex_src_pc))
                                         ? vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                        [vlTOPp->riscv_top__DOT__ex_src_pc]
                                         : 0U)),32);
            tracep->chgIData(oldp+174,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+175,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+176,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
            tracep->chgCData(oldp+177,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src),3);
            tracep->chgCData(oldp+178,((0x7fU & vlTOPp->riscv_top__DOT__id_instr)),7);
            tracep->chgBit(oldp+179,((1U & (vlTOPp->riscv_top__DOT__id_instr 
                                            >> 0x1eU))));
            tracep->chgWData(oldp+180,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR),256);
            tracep->chgWData(oldp+188,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1),96);
            tracep->chgWData(oldp+191,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2),96);
            tracep->chgQData(oldp+194,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_alu_b),64);
            tracep->chgIData(oldp+196,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a),32);
            tracep->chgIData(oldp+197,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b),32);
            tracep->chgBit(oldp+198,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__take_branch));
            tracep->chgIData(oldp+199,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+200,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+201,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+202,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+203,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+204,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+205,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+206,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+207,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data),32);
            tracep->chgCData(oldp+208,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel),4);
            tracep->chgWData(oldp+209,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result),128);
            tracep->chgIData(oldp+213,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
            tracep->chgSData(oldp+214,((0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                                                   >> 2U))),14);
            tracep->chgIData(oldp+215,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+216,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+217,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+218,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[3]),32);
        }
        tracep->chgBit(oldp+219,(vlTOPp->i_clk));
        tracep->chgBit(oldp+220,(vlTOPp->i_rstn));
        tracep->chgBit(oldp+221,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->chgIData(oldp+222,(vlTOPp->o_riscv_imem_pc),32);
        tracep->chgIData(oldp+223,(vlTOPp->o_riscv_imem_instr),32);
        tracep->chgIData(oldp+224,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->chgIData(oldp+225,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->chgIData(oldp+226,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->chgCData(oldp+227,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->chgBit(oldp+228,(((((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                              >> 0xfU)) 
                                    == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr)) 
                                   | ((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                                >> 0x14U)) 
                                      == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr))) 
                                  & (~ (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src)))));
        tracep->chgIData(oldp+229,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                              >> 0xfU))]),32);
        tracep->chgIData(oldp+230,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                              >> 0x14U))]),32);
        tracep->chgBit(oldp+231,((1U & (~ ((((0x1fU 
                                              & (vlTOPp->riscv_top__DOT__id_instr 
                                                 >> 0xfU)) 
                                             == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr)) 
                                            | ((0x1fU 
                                                & (vlTOPp->riscv_top__DOT__id_instr 
                                                   >> 0x14U)) 
                                               == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr))) 
                                           & (~ (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src)))))));
        tracep->chgIData(oldp+232,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
                                   [(0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                                                >> 2U))]),32);
        tracep->chgIData(oldp+233,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__i),32);
    }
}

void Vriscv_top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
