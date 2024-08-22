// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


//======================

void Vriscv_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv_top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv_top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv_top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv_top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+220,"i_clk", false,-1);
        tracep->declBit(c+221,"i_rstn", false,-1);
        tracep->declBit(c+222,"o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+223,"o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+224,"o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+225,"o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBus(c+226,"o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+227,"o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+228,"o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+235,"riscv_top REGISTER_INIT", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top i_rstn", false,-1);
        tracep->declBit(c+222,"riscv_top o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+223,"riscv_top o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+225,"riscv_top o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBus(c+226,"riscv_top o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+227,"riscv_top o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+228,"riscv_top o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+65,"riscv_top if_pc_plus_4", false,-1, 31,0);
        tracep->declBit(c+229,"riscv_top if_stall", false,-1);
        tracep->declBit(c+135,"riscv_top id_stall", false,-1);
        tracep->declBit(c+136,"riscv_top id_flush", false,-1);
        tracep->declBus(c+66,"riscv_top id_pc", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top id_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+137,"riscv_top id_instr", false,-1, 31,0);
        tracep->declBus(c+236,"riscv_top id_rd_data", false,-1, 31,0);
        tracep->declBus(c+230,"riscv_top id_rs1_data", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top id_rs2_data", false,-1, 31,0);
        tracep->declBus(c+138,"riscv_top id_imm", false,-1, 31,0);
        tracep->declBus(c+139,"riscv_top id_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+140,"riscv_top id_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+141,"riscv_top id_rd_addr", false,-1, 4,0);
        tracep->declBit(c+142,"riscv_top id_ctrl_reg_write", false,-1);
        tracep->declBus(c+143,"riscv_top id_ctrl_result_src", false,-1, 1,0);
        tracep->declBit(c+144,"riscv_top id_ctrl_mem_write", false,-1);
        tracep->declBus(c+145,"riscv_top id_ctrl_jump", false,-1, 1,0);
        tracep->declBit(c+146,"riscv_top id_ctrl_branch", false,-1);
        tracep->declBus(c+147,"riscv_top id_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBus(c+148,"riscv_top id_ctrl_alu_control", false,-1, 3,0);
        tracep->declBit(c+149,"riscv_top id_ctrl_alu_b_src", false,-1);
        tracep->declBit(c+150,"riscv_top id_ctrl_rd_src", false,-1);
        tracep->declBit(c+151,"riscv_top ex_flush", false,-1);
        tracep->declBit(c+152,"riscv_top ex_ctrl_reg_write", false,-1);
        tracep->declBus(c+68,"riscv_top ex_ctrl_result_src", false,-1, 1,0);
        tracep->declBit(c+153,"riscv_top ex_ctrl_mem_write", false,-1);
        tracep->declBus(c+69,"riscv_top ex_ctrl_jump", false,-1, 1,0);
        tracep->declBit(c+70,"riscv_top ex_ctrl_branch", false,-1);
        tracep->declBus(c+71,"riscv_top ex_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBus(c+72,"riscv_top ex_ctrl_alu_control", false,-1, 3,0);
        tracep->declBit(c+73,"riscv_top ex_ctrl_alu_b_src", false,-1);
        tracep->declBit(c+74,"riscv_top ex_ctrl_rd_src", false,-1);
        tracep->declBus(c+75,"riscv_top ex_rs1_data", false,-1, 31,0);
        tracep->declBus(c+76,"riscv_top ex_rs2_data", false,-1, 31,0);
        tracep->declBus(c+77,"riscv_top ex_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+78,"riscv_top ex_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+154,"riscv_top ex_rd_addr", false,-1, 4,0);
        tracep->declBus(c+79,"riscv_top ex_pc", false,-1, 31,0);
        tracep->declBus(c+80,"riscv_top ex_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+81,"riscv_top ex_imm", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top forwardAE", false,-1, 1,0);
        tracep->declBus(c+156,"riscv_top forwardBE", false,-1, 1,0);
        tracep->declBus(c+237,"riscv_top ex_forward_rd_data", false,-1, 31,0);
        tracep->declBus(c+238,"riscv_top ex_forward_alu_result", false,-1, 31,0);
        tracep->declBus(c+157,"riscv_top ex_src_pc", false,-1, 1,0);
        tracep->declBit(c+158,"riscv_top ex_alu_zero", false,-1);
        tracep->declBus(c+159,"riscv_top ex_alu_result", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top ex_write_data", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top ex_pc_plus_imm", false,-1, 31,0);
        tracep->declBit(c+83,"riscv_top mem_ctrl_rd_src", false,-1);
        tracep->declBit(c+161,"riscv_top mem_ctrl_reg_write", false,-1);
        tracep->declBit(c+162,"riscv_top mem_ctrl_mem_write", false,-1);
        tracep->declBus(c+84,"riscv_top mem_ctrl_result_src", false,-1, 1,0);
        tracep->declBus(c+85,"riscv_top mem_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top mem_rd_addr", false,-1, 4,0);
        tracep->declBus(c+86,"riscv_top mem_imm", false,-1, 31,0);
        tracep->declBus(c+164,"riscv_top mem_alu_result", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top mem_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_top mem_pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+89,"riscv_top mem_write_data", false,-1, 31,0);
        tracep->declBus(c+165,"riscv_top mem_rd_result", false,-1, 31,0);
        tracep->declBus(c+166,"riscv_top mem_read_data", false,-1, 31,0);
        tracep->declBit(c+167,"riscv_top wb_ctrl_reg_write", false,-1);
        tracep->declBus(c+239,"riscv_top wb_ctrl_result_src", false,-1, 1,0);
        tracep->declBus(c+168,"riscv_top wb_rd_addr", false,-1, 4,0);
        tracep->declBus(c+240,"riscv_top wb_imm", false,-1, 31,0);
        tracep->declBus(c+241,"riscv_top wb_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+242,"riscv_top wb_alu_result", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top wb_read_data", false,-1, 31,0);
        tracep->declBus(c+169,"riscv_top wb_rd_data", false,-1, 31,0);
        tracep->declBus(c+170,"riscv_top id_funct3", false,-1, 2,0);
        tracep->declBus(c+91,"riscv_top ex_funct3", false,-1, 2,0);
        tracep->declBus(c+92,"riscv_top mem_funct3", false,-1, 2,0);
        tracep->declBit(c+93,"riscv_top wb_ctrl_rd_src", false,-1);
        tracep->declBus(c+94,"riscv_top wb_rd_result", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_hazard_unit i_clk", false,-1);
        tracep->declBus(c+139,"riscv_top u_riscv_hazard_unit i_id_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+140,"riscv_top u_riscv_hazard_unit i_id_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+77,"riscv_top u_riscv_hazard_unit i_ex_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+78,"riscv_top u_riscv_hazard_unit i_ex_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+154,"riscv_top u_riscv_hazard_unit i_ex_rd_addr", false,-1, 4,0);
        tracep->declBus(c+163,"riscv_top u_riscv_hazard_unit i_mem_rd_addr", false,-1, 4,0);
        tracep->declBus(c+168,"riscv_top u_riscv_hazard_unit i_wb_rd_addr", false,-1, 4,0);
        tracep->declBus(c+157,"riscv_top u_riscv_hazard_unit i_ex_ctrl_pc_src", false,-1, 1,0);
        tracep->declBit(c+161,"riscv_top u_riscv_hazard_unit i_mem_ctrl_reg_write", false,-1);
        tracep->declBit(c+167,"riscv_top u_riscv_hazard_unit i_wb_ctrl_reg_write", false,-1);
        tracep->declBit(c+74,"riscv_top u_riscv_hazard_unit i_ex_ctrl_rd_src", false,-1);
        tracep->declBit(c+229,"riscv_top u_riscv_hazard_unit o_if_stall", false,-1);
        tracep->declBit(c+135,"riscv_top u_riscv_hazard_unit o_id_stall", false,-1);
        tracep->declBit(c+136,"riscv_top u_riscv_hazard_unit o_id_flush", false,-1);
        tracep->declBit(c+151,"riscv_top u_riscv_hazard_unit o_ex_flush", false,-1);
        tracep->declBus(c+155,"riscv_top u_riscv_hazard_unit o_ForwardAE", false,-1, 1,0);
        tracep->declBus(c+156,"riscv_top u_riscv_hazard_unit o_ForwardBE", false,-1, 1,0);
        tracep->declBus(c+235,"riscv_top u_riscv_if REGISTER_INIT", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_if i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_if i_rstn", false,-1);
        tracep->declBit(c+229,"riscv_top u_riscv_if i_if_stall", false,-1);
        tracep->declBus(c+157,"riscv_top u_riscv_if i_if_src_pc", false,-1, 1,0);
        tracep->declBus(c+82,"riscv_top u_riscv_if i_if_pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_if i_if_alu_result", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top u_riscv_if o_if_instr", false,-1, 31,0);
        tracep->declBus(c+223,"riscv_top u_riscv_if o_if_pc", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_if o_if_pc_plus_4", false,-1, 31,0);
        tracep->declArray(c+171,"riscv_top u_riscv_if mux_concat_pc", false,-1, 95,0);
        tracep->declBus(c+174,"riscv_top u_riscv_if next_pc", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_if current_pc", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_if pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top u_riscv_if u_riscv_mux_pc N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+157,"riscv_top u_riscv_if u_riscv_mux_pc i_mux_sel", false,-1, 1,0);
        tracep->declArray(c+171,"riscv_top u_riscv_if u_riscv_mux_pc i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+174,"riscv_top u_riscv_if u_riscv_mux_pc o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+175+i*1,"riscv_top u_riscv_if u_riscv_mux_pc mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+235,"riscv_top u_riscv_if u_riscv_register REGISTER_INIT", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_if u_riscv_register i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_if u_riscv_register i_rstn", false,-1);
        tracep->declBit(c+232,"riscv_top u_riscv_if u_riscv_register i_register_en", false,-1);
        tracep->declBus(c+174,"riscv_top u_riscv_if u_riscv_register i_register_d", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_if u_riscv_register o_register_q", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_if u_riscv_adder i_adder_a", false,-1, 31,0);
        tracep->declBus(c+244,"riscv_top u_riscv_if u_riscv_adder i_adder_b", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_if u_riscv_adder o_adder_sum", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_if u_riscv_imem i_clk", false,-1);
        tracep->declBus(c+96,"riscv_top u_riscv_if u_riscv_imem i_imem_addr", false,-1, 13,0);
        tracep->declBus(c+224,"riscv_top u_riscv_if u_riscv_imem o_imem_data", false,-1, 31,0);
        tracep->declArray(c+1,"riscv_top u_riscv_if u_riscv_imem FILE_TEXT_MIF", false,-1, 1023,0);
        tracep->declBit(c+220,"riscv_top u_riscv_ifid_reg i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_ifid_reg i_rstn", false,-1);
        tracep->declBit(c+135,"riscv_top u_riscv_ifid_reg i_id_stall", false,-1);
        tracep->declBit(c+136,"riscv_top u_riscv_ifid_reg i_id_flush", false,-1);
        tracep->declBus(c+224,"riscv_top u_riscv_ifid_reg i_if_instr", false,-1, 31,0);
        tracep->declBus(c+223,"riscv_top u_riscv_ifid_reg i_if_pc", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_ifid_reg i_if_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+137,"riscv_top u_riscv_ifid_reg o_id_instr", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_ifid_reg o_id_pc", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_ifid_reg o_id_pc_plus_4", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_id i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_id i_rstn", false,-1);
        tracep->declBus(c+168,"riscv_top u_riscv_id i_id_rd_addr", false,-1, 4,0);
        tracep->declBit(c+167,"riscv_top u_riscv_id i_id_wb_reg_write", false,-1);
        tracep->declBus(c+137,"riscv_top u_riscv_id i_id_instr", false,-1, 31,0);
        tracep->declBus(c+169,"riscv_top u_riscv_id i_id_rd_data", false,-1, 31,0);
        tracep->declBus(c+230,"riscv_top u_riscv_id o_id_rs1_data", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top u_riscv_id o_id_rs2_data", false,-1, 31,0);
        tracep->declBus(c+139,"riscv_top u_riscv_id o_id_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+140,"riscv_top u_riscv_id o_id_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+141,"riscv_top u_riscv_id o_id_rd_addr", false,-1, 4,0);
        tracep->declBus(c+138,"riscv_top u_riscv_id o_id_imm", false,-1, 31,0);
        tracep->declBus(c+170,"riscv_top u_riscv_id o_id_funct3", false,-1, 2,0);
        tracep->declBit(c+142,"riscv_top u_riscv_id o_id_ctrl_reg_write", false,-1);
        tracep->declBus(c+143,"riscv_top u_riscv_id o_id_ctrl_result_src", false,-1, 1,0);
        tracep->declBit(c+144,"riscv_top u_riscv_id o_id_ctrl_mem_write", false,-1);
        tracep->declBus(c+145,"riscv_top u_riscv_id o_id_ctrl_jump", false,-1, 1,0);
        tracep->declBit(c+146,"riscv_top u_riscv_id o_id_ctrl_branch", false,-1);
        tracep->declBus(c+148,"riscv_top u_riscv_id o_id_ctrl_alu_control", false,-1, 3,0);
        tracep->declBus(c+147,"riscv_top u_riscv_id o_id_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBit(c+149,"riscv_top u_riscv_id o_id_ctrl_alu_b_src", false,-1);
        tracep->declBit(c+150,"riscv_top u_riscv_id o_id_ctrl_rd_src", false,-1);
        tracep->declBus(c+178,"riscv_top u_riscv_id id_imm_src", false,-1, 2,0);
        tracep->declBus(c+179,"riscv_top u_riscv_id u_riscv_control_unit opcode", false,-1, 6,0);
        tracep->declBus(c+170,"riscv_top u_riscv_id u_riscv_control_unit funct3", false,-1, 2,0);
        tracep->declBit(c+180,"riscv_top u_riscv_id u_riscv_control_unit funct7_5b", false,-1);
        tracep->declBit(c+142,"riscv_top u_riscv_id u_riscv_control_unit regwrite", false,-1);
        tracep->declBus(c+143,"riscv_top u_riscv_id u_riscv_control_unit result_src", false,-1, 1,0);
        tracep->declBit(c+144,"riscv_top u_riscv_id u_riscv_control_unit memwrite", false,-1);
        tracep->declBus(c+145,"riscv_top u_riscv_id u_riscv_control_unit jump", false,-1, 1,0);
        tracep->declBit(c+146,"riscv_top u_riscv_id u_riscv_control_unit branch", false,-1);
        tracep->declBus(c+147,"riscv_top u_riscv_id u_riscv_control_unit byte_sel", false,-1, 3,0);
        tracep->declBus(c+148,"riscv_top u_riscv_id u_riscv_control_unit alu_control", false,-1, 3,0);
        tracep->declBit(c+150,"riscv_top u_riscv_id u_riscv_control_unit rd_src", false,-1);
        tracep->declBit(c+149,"riscv_top u_riscv_id u_riscv_control_unit alu_b_src", false,-1);
        tracep->declBus(c+178,"riscv_top u_riscv_id u_riscv_control_unit imm_src", false,-1, 2,0);
        tracep->declArray(c+181,"riscv_top u_riscv_id u_riscv_control_unit DEBUG_INSTR", false,-1, 255,0);
        tracep->declBit(c+220,"riscv_top u_riscv_id u_riscv_register_file i_clk", false,-1);
        tracep->declBit(c+167,"riscv_top u_riscv_id u_riscv_register_file i_regfile_rd_wen", false,-1);
        tracep->declBus(c+139,"riscv_top u_riscv_id u_riscv_register_file i_regfile_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+140,"riscv_top u_riscv_id u_riscv_register_file i_regfile_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+168,"riscv_top u_riscv_id u_riscv_register_file i_regfile_rd_addr", false,-1, 4,0);
        tracep->declBus(c+169,"riscv_top u_riscv_id u_riscv_register_file i_regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+230,"riscv_top u_riscv_id u_riscv_register_file o_regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top u_riscv_id u_riscv_register_file o_regfile_rs2_data", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+103+i*1,"riscv_top u_riscv_id u_riscv_register_file registers", true,(i+0), 31,0);}}
        tracep->declBus(c+178,"riscv_top u_riscv_id u_riscv_immdecode i_imm_scr", false,-1, 2,0);
        tracep->declBus(c+137,"riscv_top u_riscv_id u_riscv_immdecode i_imm_instr", false,-1, 31,0);
        tracep->declBus(c+138,"riscv_top u_riscv_id u_riscv_immdecode o_imm_decode", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_idex_reg i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_idex_reg i_rstn", false,-1);
        tracep->declBit(c+151,"riscv_top u_riscv_idex_reg i_flushE", false,-1);
        tracep->declBus(c+170,"riscv_top u_riscv_idex_reg i_id_funct3", false,-1, 2,0);
        tracep->declBus(c+91,"riscv_top u_riscv_idex_reg o_ex_funct3", false,-1, 2,0);
        tracep->declBit(c+142,"riscv_top u_riscv_idex_reg i_id_ctrl_reg_write", false,-1);
        tracep->declBus(c+143,"riscv_top u_riscv_idex_reg i_id_ctrl_result_src", false,-1, 1,0);
        tracep->declBit(c+144,"riscv_top u_riscv_idex_reg i_id_ctrl_mem_write", false,-1);
        tracep->declBus(c+145,"riscv_top u_riscv_idex_reg i_id_ctrl_jump", false,-1, 1,0);
        tracep->declBit(c+146,"riscv_top u_riscv_idex_reg i_id_ctrl_branch", false,-1);
        tracep->declBus(c+147,"riscv_top u_riscv_idex_reg i_id_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBus(c+148,"riscv_top u_riscv_idex_reg i_id_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+149,"riscv_top u_riscv_idex_reg i_id_ctrl_alu_b_src", false,-1);
        tracep->declBit(c+150,"riscv_top u_riscv_idex_reg i_id_ctrl_rd_src", false,-1);
        tracep->declBit(c+152,"riscv_top u_riscv_idex_reg o_ex_ctrl_reg_write", false,-1);
        tracep->declBus(c+68,"riscv_top u_riscv_idex_reg o_ex_ctrl_result_src", false,-1, 1,0);
        tracep->declBit(c+153,"riscv_top u_riscv_idex_reg o_ex_ctrl_mem_write", false,-1);
        tracep->declBus(c+69,"riscv_top u_riscv_idex_reg o_ex_ctrl_jump", false,-1, 1,0);
        tracep->declBit(c+70,"riscv_top u_riscv_idex_reg o_ex_ctrl_branch", false,-1);
        tracep->declBus(c+71,"riscv_top u_riscv_idex_reg o_ex_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBus(c+72,"riscv_top u_riscv_idex_reg o_ex_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+73,"riscv_top u_riscv_idex_reg o_ex_ctrl_alu_b_src", false,-1);
        tracep->declBit(c+74,"riscv_top u_riscv_idex_reg o_ex_ctrl_rd_src", false,-1);
        tracep->declBus(c+230,"riscv_top u_riscv_idex_reg i_id_rs1_data", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top u_riscv_idex_reg i_id_rs2_data", false,-1, 31,0);
        tracep->declBus(c+139,"riscv_top u_riscv_idex_reg i_id_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+140,"riscv_top u_riscv_idex_reg i_id_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+141,"riscv_top u_riscv_idex_reg i_id_rd_addr", false,-1, 4,0);
        tracep->declBus(c+138,"riscv_top u_riscv_idex_reg i_id_imm", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_idex_reg i_id_pc", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_idex_reg i_id_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+75,"riscv_top u_riscv_idex_reg o_ex_rs1_data", false,-1, 31,0);
        tracep->declBus(c+76,"riscv_top u_riscv_idex_reg o_ex_rs2_data", false,-1, 31,0);
        tracep->declBus(c+77,"riscv_top u_riscv_idex_reg o_ex_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+78,"riscv_top u_riscv_idex_reg o_ex_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+154,"riscv_top u_riscv_idex_reg o_ex_rd_addr", false,-1, 4,0);
        tracep->declBus(c+81,"riscv_top u_riscv_idex_reg o_ex_imm", false,-1, 31,0);
        tracep->declBus(c+79,"riscv_top u_riscv_idex_reg o_ex_pc", false,-1, 31,0);
        tracep->declBus(c+80,"riscv_top u_riscv_idex_reg o_ex_pc_plus_4", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_ex i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_ex i_rstn", false,-1);
        tracep->declBus(c+72,"riscv_top u_riscv_ex i_ex_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBus(c+69,"riscv_top u_riscv_ex i_ex_ctrl_jump", false,-1, 1,0);
        tracep->declBit(c+70,"riscv_top u_riscv_ex i_ex_ctrl_branch", false,-1);
        tracep->declBit(c+73,"riscv_top u_riscv_ex i_ex_ctrl_alu_b_src", false,-1);
        tracep->declBus(c+91,"riscv_top u_riscv_ex i_ex_funct3", false,-1, 2,0);
        tracep->declBus(c+155,"riscv_top u_riscv_ex i_ForwardAE", false,-1, 1,0);
        tracep->declBus(c+156,"riscv_top u_riscv_ex i_ForwardBE", false,-1, 1,0);
        tracep->declBus(c+169,"riscv_top u_riscv_ex i_ex_forward_rd_data", false,-1, 31,0);
        tracep->declBus(c+165,"riscv_top u_riscv_ex i_ex_forward_alu_result", false,-1, 31,0);
        tracep->declBus(c+75,"riscv_top u_riscv_ex i_ex_rs1_data", false,-1, 31,0);
        tracep->declBus(c+76,"riscv_top u_riscv_ex i_ex_rs2_data", false,-1, 31,0);
        tracep->declBus(c+81,"riscv_top u_riscv_ex i_ex_imm", false,-1, 31,0);
        tracep->declBus(c+79,"riscv_top u_riscv_ex i_ex_pc", false,-1, 31,0);
        tracep->declBit(c+158,"riscv_top u_riscv_ex o_ex_alu_zero", false,-1);
        tracep->declBus(c+159,"riscv_top u_riscv_ex o_ex_alu_result", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_ex o_ex_write_data", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top u_riscv_ex o_ex_pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+157,"riscv_top u_riscv_ex o_ex_ctrl_pc_src", false,-1, 1,0);
        tracep->declArray(c+189,"riscv_top u_riscv_ex mux_concat_src_rs1", false,-1, 95,0);
        tracep->declArray(c+192,"riscv_top u_riscv_ex mux_concat_src_rs2", false,-1, 95,0);
        tracep->declQuad(c+195,"riscv_top u_riscv_ex mux_concat_alu_b", false,-1, 63,0);
        tracep->declBus(c+160,"riscv_top u_riscv_ex src_rs2_data", false,-1, 31,0);
        tracep->declBus(c+197,"riscv_top u_riscv_ex alu_a", false,-1, 31,0);
        tracep->declBus(c+198,"riscv_top u_riscv_ex alu_b", false,-1, 31,0);
        tracep->declBit(c+199,"riscv_top u_riscv_ex take_branch", false,-1);
        tracep->declBus(c+243,"riscv_top u_riscv_ex u_riscv_mux_rs1 N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_ex u_riscv_mux_rs1 i_mux_sel", false,-1, 1,0);
        tracep->declArray(c+189,"riscv_top u_riscv_ex u_riscv_mux_rs1 i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+197,"riscv_top u_riscv_ex u_riscv_mux_rs1 o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+200+i*1,"riscv_top u_riscv_ex u_riscv_mux_rs1 mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+243,"riscv_top u_riscv_ex u_riscv_mux_rs2 N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_ex u_riscv_mux_rs2 i_mux_sel", false,-1, 1,0);
        tracep->declArray(c+192,"riscv_top u_riscv_ex u_riscv_mux_rs2 i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+160,"riscv_top u_riscv_ex u_riscv_mux_rs2 o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+203+i*1,"riscv_top u_riscv_ex u_riscv_mux_rs2 mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+245,"riscv_top u_riscv_ex u_riscv_mux_alu_b N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_ex u_riscv_mux_alu_b i_mux_sel", false,-1, 0,0);
        tracep->declQuad(c+195,"riscv_top u_riscv_ex u_riscv_mux_alu_b i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+198,"riscv_top u_riscv_ex u_riscv_mux_alu_b o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+206+i*1,"riscv_top u_riscv_ex u_riscv_mux_alu_b mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+72,"riscv_top u_riscv_ex u_riscv_alu i_alu_ctrl", false,-1, 3,0);
        tracep->declBus(c+197,"riscv_top u_riscv_ex u_riscv_alu i_alu_a", false,-1, 31,0);
        tracep->declBus(c+198,"riscv_top u_riscv_ex u_riscv_alu i_alu_b", false,-1, 31,0);
        tracep->declBit(c+158,"riscv_top u_riscv_ex u_riscv_alu o_alu_zero", false,-1);
        tracep->declBus(c+159,"riscv_top u_riscv_ex u_riscv_alu o_alu_result", false,-1, 31,0);
        tracep->declQuad(c+97,"riscv_top u_riscv_ex u_riscv_alu DEBUG_ALU_OP", false,-1, 63,0);
        tracep->declBus(c+79,"riscv_top u_riscv_ex u_riscv_adder i_adder_a", false,-1, 31,0);
        tracep->declBus(c+81,"riscv_top u_riscv_ex u_riscv_adder i_adder_b", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top u_riscv_ex u_riscv_adder o_adder_sum", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_exmem_reg i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_exmem_reg i_rstn", false,-1);
        tracep->declBus(c+91,"riscv_top u_riscv_exmem_reg i_ex_funct3", false,-1, 2,0);
        tracep->declBus(c+92,"riscv_top u_riscv_exmem_reg o_mem_funct3", false,-1, 2,0);
        tracep->declBit(c+74,"riscv_top u_riscv_exmem_reg i_ex_ctrl_rd_src", false,-1);
        tracep->declBit(c+152,"riscv_top u_riscv_exmem_reg i_ex_ctrl_reg_write", false,-1);
        tracep->declBit(c+153,"riscv_top u_riscv_exmem_reg i_ex_ctrl_mem_write", false,-1);
        tracep->declBus(c+68,"riscv_top u_riscv_exmem_reg i_ex_ctrl_result_src", false,-1, 1,0);
        tracep->declBus(c+71,"riscv_top u_riscv_exmem_reg i_ex_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBit(c+83,"riscv_top u_riscv_exmem_reg o_mem_ctrl_rd_src", false,-1);
        tracep->declBit(c+161,"riscv_top u_riscv_exmem_reg o_mem_ctrl_reg_write", false,-1);
        tracep->declBit(c+162,"riscv_top u_riscv_exmem_reg o_mem_ctrl_mem_write", false,-1);
        tracep->declBus(c+84,"riscv_top u_riscv_exmem_reg o_mem_ctrl_result_src", false,-1, 1,0);
        tracep->declBus(c+85,"riscv_top u_riscv_exmem_reg o_mem_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBus(c+154,"riscv_top u_riscv_exmem_reg i_ex_rd_addr", false,-1, 4,0);
        tracep->declBus(c+81,"riscv_top u_riscv_exmem_reg i_ex_imm", false,-1, 31,0);
        tracep->declBus(c+80,"riscv_top u_riscv_exmem_reg i_ex_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top u_riscv_exmem_reg i_ex_pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_exmem_reg i_ex_alu_result", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_exmem_reg i_ex_write_data", false,-1, 31,0);
        tracep->declBus(c+163,"riscv_top u_riscv_exmem_reg o_mem_rd_addr", false,-1, 4,0);
        tracep->declBus(c+86,"riscv_top u_riscv_exmem_reg o_mem_imm", false,-1, 31,0);
        tracep->declBus(c+164,"riscv_top u_riscv_exmem_reg o_mem_alu_result", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_exmem_reg o_mem_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_top u_riscv_exmem_reg o_mem_pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+89,"riscv_top u_riscv_exmem_reg o_mem_write_data", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_mem i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_mem i_rstn", false,-1);
        tracep->declBus(c+92,"riscv_top u_riscv_mem i_mem_funct3", false,-1, 2,0);
        tracep->declBus(c+84,"riscv_top u_riscv_mem i_mem_ctrl_result_src", false,-1, 1,0);
        tracep->declBit(c+162,"riscv_top u_riscv_mem i_mem_ctrl_mem_write", false,-1);
        tracep->declBus(c+85,"riscv_top u_riscv_mem i_mem_ctrl_byte_sel", false,-1, 3,0);
        tracep->declBus(c+89,"riscv_top u_riscv_mem i_mem_write_data", false,-1, 31,0);
        tracep->declBus(c+164,"riscv_top u_riscv_mem i_mem_alu_result", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_mem i_mem_imm", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_top u_riscv_mem i_mem_pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_mem i_mem_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+165,"riscv_top u_riscv_mem o_mem_rd_result", false,-1, 31,0);
        tracep->declBus(c+166,"riscv_top u_riscv_mem o_mem_read_data", false,-1, 31,0);
        tracep->declBus(c+164,"riscv_top u_riscv_mem dmem_addr", false,-1, 31,0);
        tracep->declBit(c+162,"riscv_top u_riscv_mem dmem_mem_write", false,-1);
        tracep->declBus(c+208,"riscv_top u_riscv_mem dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+209,"riscv_top u_riscv_mem dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+233,"riscv_top u_riscv_mem dmem_rd_data", false,-1, 31,0);
        tracep->declArray(c+210,"riscv_top u_riscv_mem mux_concat_src_result", false,-1, 127,0);
        tracep->declBit(c+220,"riscv_top u_riscv_mem u_riscv_dmem_interface i_clk", false,-1);
        tracep->declBus(c+164,"riscv_top u_riscv_mem u_riscv_dmem_interface i_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+162,"riscv_top u_riscv_mem u_riscv_dmem_interface i_dmem_intf_wr_en", false,-1);
        tracep->declBus(c+89,"riscv_top u_riscv_mem u_riscv_dmem_interface i_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+233,"riscv_top u_riscv_mem u_riscv_dmem_interface i_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+85,"riscv_top u_riscv_mem u_riscv_dmem_interface i_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+92,"riscv_top u_riscv_mem u_riscv_dmem_interface i_dmem_intf_func3", false,-1, 2,0);
        tracep->declBus(c+164,"riscv_top u_riscv_mem u_riscv_dmem_interface o_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+162,"riscv_top u_riscv_mem u_riscv_dmem_interface o_dmem_intf_wr_en", false,-1);
        tracep->declBus(c+208,"riscv_top u_riscv_mem u_riscv_dmem_interface o_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+209,"riscv_top u_riscv_mem u_riscv_dmem_interface o_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_mem u_riscv_dmem_interface o_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+214,"riscv_top u_riscv_mem u_riscv_dmem_interface byte_aligned_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+220,"riscv_top u_riscv_mem u_riscv_dmem i_clk", false,-1);
        tracep->declBit(c+162,"riscv_top u_riscv_mem u_riscv_dmem i_dmem_wr_en", false,-1);
        tracep->declBus(c+209,"riscv_top u_riscv_mem u_riscv_dmem i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+215,"riscv_top u_riscv_mem u_riscv_dmem i_dmem_addr", false,-1, 13,0);
        tracep->declBus(c+208,"riscv_top u_riscv_mem u_riscv_dmem i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+233,"riscv_top u_riscv_mem u_riscv_dmem o_dmem_data", false,-1, 31,0);
        tracep->declArray(c+33,"riscv_top u_riscv_mem u_riscv_dmem FILE_DATA_MIF", false,-1, 1023,0);
        tracep->declBus(c+234,"riscv_top u_riscv_mem u_riscv_dmem i", false,-1, 31,0);
        tracep->declBus(c+246,"riscv_top u_riscv_mem u_riscv_mux_rd N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+84,"riscv_top u_riscv_mem u_riscv_mux_rd i_mux_sel", false,-1, 1,0);
        tracep->declArray(c+210,"riscv_top u_riscv_mem u_riscv_mux_rd i_mux_concat_data", false,-1, 127,0);
        tracep->declBus(c+165,"riscv_top u_riscv_mem u_riscv_mux_rd o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+216+i*1,"riscv_top u_riscv_mem u_riscv_mux_rd mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBit(c+220,"riscv_top u_riscv_memwb_reg i_clk", false,-1);
        tracep->declBit(c+221,"riscv_top u_riscv_memwb_reg i_rstn", false,-1);
        tracep->declBit(c+161,"riscv_top u_riscv_memwb_reg i_mem_ctrl_reg_write", false,-1);
        tracep->declBit(c+83,"riscv_top u_riscv_memwb_reg i_mem_ctrl_rd_src", false,-1);
        tracep->declBit(c+167,"riscv_top u_riscv_memwb_reg o_wb_ctrl_reg_write", false,-1);
        tracep->declBit(c+93,"riscv_top u_riscv_memwb_reg o_wb_ctrl_rd_src", false,-1);
        tracep->declBus(c+163,"riscv_top u_riscv_memwb_reg i_mem_rd_addr", false,-1, 4,0);
        tracep->declBus(c+165,"riscv_top u_riscv_memwb_reg i_mem_rd_result", false,-1, 31,0);
        tracep->declBus(c+166,"riscv_top u_riscv_memwb_reg i_mem_read_data", false,-1, 31,0);
        tracep->declBus(c+168,"riscv_top u_riscv_memwb_reg o_wb_rd_addr", false,-1, 4,0);
        tracep->declBus(c+94,"riscv_top u_riscv_memwb_reg o_wb_rd_result", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top u_riscv_memwb_reg o_wb_read_data", false,-1, 31,0);
        tracep->declBit(c+93,"riscv_top u_riscv_wb i_wb_ctrl_rd_src", false,-1);
        tracep->declBus(c+94,"riscv_top u_riscv_wb i_wb_rd_data", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top u_riscv_wb i_wb_read_data", false,-1, 31,0);
        tracep->declBus(c+169,"riscv_top u_riscv_wb o_wb_rd_result", false,-1, 31,0);
        tracep->declQuad(c+99,"riscv_top u_riscv_wb mux_concat_rd", false,-1, 63,0);
        tracep->declBus(c+245,"riscv_top u_riscv_wb u_riscv_mux N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+93,"riscv_top u_riscv_wb u_riscv_mux i_mux_sel", false,-1, 0,0);
        tracep->declQuad(c+99,"riscv_top u_riscv_wb u_riscv_mux i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+169,"riscv_top u_riscv_wb u_riscv_mux o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+101+i*1,"riscv_top u_riscv_wb u_riscv_mux mux_input_arr", true,(i+0), 31,0);}}
    }
}

void Vriscv_top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv_top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv_top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullWData(oldp+1,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
        tracep->fullWData(oldp+33,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        tracep->fullIData(oldp+65,(((IData)(4U) + vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc)),32);
        tracep->fullIData(oldp+66,(vlTOPp->riscv_top__DOT__id_pc),32);
        tracep->fullIData(oldp+67,(vlTOPp->riscv_top__DOT__id_pc_plus_4),32);
        tracep->fullCData(oldp+68,(vlTOPp->riscv_top__DOT__ex_ctrl_result_src),2);
        tracep->fullCData(oldp+69,(vlTOPp->riscv_top__DOT__ex_ctrl_jump),2);
        tracep->fullBit(oldp+70,(vlTOPp->riscv_top__DOT__ex_ctrl_branch));
        tracep->fullCData(oldp+71,(vlTOPp->riscv_top__DOT__ex_ctrl_byte_sel),4);
        tracep->fullCData(oldp+72,(vlTOPp->riscv_top__DOT__ex_ctrl_alu_control),4);
        tracep->fullBit(oldp+73,(vlTOPp->riscv_top__DOT__ex_ctrl_alu_b_src));
        tracep->fullBit(oldp+74,(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src));
        tracep->fullIData(oldp+75,(vlTOPp->riscv_top__DOT__ex_rs1_data),32);
        tracep->fullIData(oldp+76,(vlTOPp->riscv_top__DOT__ex_rs2_data),32);
        tracep->fullCData(oldp+77,(vlTOPp->riscv_top__DOT__ex_rs1_addr),5);
        tracep->fullCData(oldp+78,(vlTOPp->riscv_top__DOT__ex_rs2_addr),5);
        tracep->fullIData(oldp+79,(vlTOPp->riscv_top__DOT__ex_pc),32);
        tracep->fullIData(oldp+80,(vlTOPp->riscv_top__DOT__ex_pc_plus_4),32);
        tracep->fullIData(oldp+81,(vlTOPp->riscv_top__DOT__ex_imm),32);
        tracep->fullIData(oldp+82,(vlTOPp->riscv_top__DOT__ex_pc_plus_imm),32);
        tracep->fullBit(oldp+83,(vlTOPp->riscv_top__DOT__mem_ctrl_rd_src));
        tracep->fullCData(oldp+84,(vlTOPp->riscv_top__DOT__mem_ctrl_result_src),2);
        tracep->fullCData(oldp+85,(vlTOPp->riscv_top__DOT__mem_ctrl_byte_sel),4);
        tracep->fullIData(oldp+86,(vlTOPp->riscv_top__DOT__mem_imm),32);
        tracep->fullIData(oldp+87,(vlTOPp->riscv_top__DOT__mem_pc_plus_4),32);
        tracep->fullIData(oldp+88,(vlTOPp->riscv_top__DOT__mem_pc_plus_imm),32);
        tracep->fullIData(oldp+89,(vlTOPp->riscv_top__DOT__mem_write_data),32);
        tracep->fullIData(oldp+90,(vlTOPp->riscv_top__DOT__wb_read_data),32);
        tracep->fullCData(oldp+91,(vlTOPp->riscv_top__DOT__ex_funct3),3);
        tracep->fullCData(oldp+92,(vlTOPp->riscv_top__DOT__mem_funct3),3);
        tracep->fullBit(oldp+93,(vlTOPp->riscv_top__DOT__wb_ctrl_rd_src));
        tracep->fullIData(oldp+94,(vlTOPp->riscv_top__DOT__wb_rd_result),32);
        tracep->fullIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc),32);
        tracep->fullSData(oldp+96,((0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_if__DOT__current_pc 
                                               >> 2U))),14);
        tracep->fullQData(oldp+97,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
        tracep->fullQData(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__mux_concat_rd),64);
        tracep->fullIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[0]),32);
        tracep->fullIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[1]),32);
        tracep->fullIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[2]),32);
        tracep->fullIData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[3]),32);
        tracep->fullIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[4]),32);
        tracep->fullIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[5]),32);
        tracep->fullIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[6]),32);
        tracep->fullIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[7]),32);
        tracep->fullIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[8]),32);
        tracep->fullIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[9]),32);
        tracep->fullIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[10]),32);
        tracep->fullIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[11]),32);
        tracep->fullIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[12]),32);
        tracep->fullIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[13]),32);
        tracep->fullIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[14]),32);
        tracep->fullIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[15]),32);
        tracep->fullIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[16]),32);
        tracep->fullIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[17]),32);
        tracep->fullIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[18]),32);
        tracep->fullIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[19]),32);
        tracep->fullIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[20]),32);
        tracep->fullIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[21]),32);
        tracep->fullIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[22]),32);
        tracep->fullIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[23]),32);
        tracep->fullIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[24]),32);
        tracep->fullIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[25]),32);
        tracep->fullIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[26]),32);
        tracep->fullIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[27]),32);
        tracep->fullIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[28]),32);
        tracep->fullIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[29]),32);
        tracep->fullIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[30]),32);
        tracep->fullIData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[31]),32);
        tracep->fullBit(oldp+135,(vlTOPp->riscv_top__DOT__id_stall));
        tracep->fullBit(oldp+136,(vlTOPp->riscv_top__DOT__id_flush));
        tracep->fullIData(oldp+137,(vlTOPp->riscv_top__DOT__id_instr),32);
        tracep->fullIData(oldp+138,(vlTOPp->riscv_top__DOT__id_imm),32);
        tracep->fullCData(oldp+139,((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+140,((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+141,((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                              >> 7U))),5);
        tracep->fullBit(oldp+142,((1U & (~ ((0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__id_instr)) 
                                            | (0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr)))))));
        tracep->fullCData(oldp+143,(vlTOPp->riscv_top__DOT__id_ctrl_result_src),2);
        tracep->fullBit(oldp+144,((0x23U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__id_instr))));
        tracep->fullCData(oldp+145,(((0x6fU == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__id_instr))
                                      ? 1U : ((0x67U 
                                               == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr))
                                               ? 2U
                                               : 0U))),2);
        tracep->fullBit(oldp+146,((0x63U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__id_instr))));
        tracep->fullCData(oldp+147,((((0x23U == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__id_instr)) 
                                      | (3U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__id_instr)))
                                      ? ((0x4000U & vlTOPp->riscv_top__DOT__id_instr)
                                          ? ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__id_instr)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__id_instr)
                                                  ? 3U
                                                  : 1U))
                                          : ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__id_instr)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__id_instr)
                                                  ? 3U
                                                  : 1U)))
                                      : 0xfU)),4);
        tracep->fullCData(oldp+148,(vlTOPp->riscv_top__DOT__id_ctrl_alu_control),4);
        tracep->fullBit(oldp+149,((1U & (~ ((0x33U 
                                             == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__id_instr)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__id_instr)))))));
        tracep->fullBit(oldp+150,((3U != (0x7fU & vlTOPp->riscv_top__DOT__id_instr))));
        tracep->fullBit(oldp+151,(vlTOPp->riscv_top__DOT__ex_flush));
        tracep->fullBit(oldp+152,(vlTOPp->riscv_top__DOT__ex_ctrl_reg_write));
        tracep->fullBit(oldp+153,(vlTOPp->riscv_top__DOT__ex_ctrl_mem_write));
        tracep->fullCData(oldp+154,(vlTOPp->riscv_top__DOT__ex_rd_addr),5);
        tracep->fullCData(oldp+155,(vlTOPp->riscv_top__DOT__forwardAE),2);
        tracep->fullCData(oldp+156,(vlTOPp->riscv_top__DOT__forwardBE),2);
        tracep->fullCData(oldp+157,(vlTOPp->riscv_top__DOT__ex_src_pc),2);
        tracep->fullBit(oldp+158,((0U == vlTOPp->riscv_top__DOT__ex_alu_result)));
        tracep->fullIData(oldp+159,(vlTOPp->riscv_top__DOT__ex_alu_result),32);
        tracep->fullIData(oldp+160,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__src_rs2_data),32);
        tracep->fullBit(oldp+161,(vlTOPp->riscv_top__DOT__mem_ctrl_reg_write));
        tracep->fullBit(oldp+162,(vlTOPp->riscv_top__DOT__mem_ctrl_mem_write));
        tracep->fullCData(oldp+163,(vlTOPp->riscv_top__DOT__mem_rd_addr),5);
        tracep->fullIData(oldp+164,(vlTOPp->riscv_top__DOT__mem_alu_result),32);
        tracep->fullIData(oldp+165,(vlTOPp->riscv_top__DOT__mem_rd_result),32);
        tracep->fullIData(oldp+166,(vlTOPp->riscv_top__DOT__mem_read_data),32);
        tracep->fullBit(oldp+167,(vlTOPp->riscv_top__DOT__wb_ctrl_reg_write));
        tracep->fullCData(oldp+168,(vlTOPp->riscv_top__DOT__wb_rd_addr),5);
        tracep->fullIData(oldp+169,(vlTOPp->riscv_top__DOT__wb_rd_data),32);
        tracep->fullCData(oldp+170,((7U & (vlTOPp->riscv_top__DOT__id_instr 
                                           >> 0xcU))),3);
        tracep->fullWData(oldp+171,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc),96);
        tracep->fullIData(oldp+174,(((2U >= (IData)(vlTOPp->riscv_top__DOT__ex_src_pc))
                                      ? vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                     [vlTOPp->riscv_top__DOT__ex_src_pc]
                                      : 0U)),32);
        tracep->fullIData(oldp+175,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+176,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+177,(vlTOPp->riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
        tracep->fullCData(oldp+178,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__id_imm_src),3);
        tracep->fullCData(oldp+179,((0x7fU & vlTOPp->riscv_top__DOT__id_instr)),7);
        tracep->fullBit(oldp+180,((1U & (vlTOPp->riscv_top__DOT__id_instr 
                                         >> 0x1eU))));
        tracep->fullWData(oldp+181,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR),256);
        tracep->fullWData(oldp+189,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1),96);
        tracep->fullWData(oldp+192,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2),96);
        tracep->fullQData(oldp+195,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__mux_concat_alu_b),64);
        tracep->fullIData(oldp+197,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_a),32);
        tracep->fullIData(oldp+198,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__alu_b),32);
        tracep->fullBit(oldp+199,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__take_branch));
        tracep->fullIData(oldp+200,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+201,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+202,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+203,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+204,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+205,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+206,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+207,(vlTOPp->riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+208,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data),32);
        tracep->fullCData(oldp+209,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel),4);
        tracep->fullWData(oldp+210,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result),128);
        tracep->fullIData(oldp+214,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        tracep->fullSData(oldp+215,((0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                                                >> 2U))),14);
        tracep->fullIData(oldp+216,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+217,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+218,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+219,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[3]),32);
        tracep->fullBit(oldp+220,(vlTOPp->i_clk));
        tracep->fullBit(oldp+221,(vlTOPp->i_rstn));
        tracep->fullBit(oldp+222,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->fullIData(oldp+223,(vlTOPp->o_riscv_imem_pc),32);
        tracep->fullIData(oldp+224,(vlTOPp->o_riscv_imem_instr),32);
        tracep->fullIData(oldp+225,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->fullIData(oldp+226,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->fullIData(oldp+227,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->fullCData(oldp+228,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->fullBit(oldp+229,(((((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                               >> 0xfU)) 
                                     == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr)) 
                                    | ((0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                                 >> 0x14U)) 
                                       == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr))) 
                                   & (~ (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src)))));
        tracep->fullIData(oldp+230,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers
                                    [(0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                               >> 0xfU))]),32);
        tracep->fullIData(oldp+231,(vlTOPp->riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers
                                    [(0x1fU & (vlTOPp->riscv_top__DOT__id_instr 
                                               >> 0x14U))]),32);
        tracep->fullBit(oldp+232,((1U & (~ ((((0x1fU 
                                               & (vlTOPp->riscv_top__DOT__id_instr 
                                                  >> 0xfU)) 
                                              == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr)) 
                                             | ((0x1fU 
                                                 & (vlTOPp->riscv_top__DOT__id_instr 
                                                    >> 0x14U)) 
                                                == (IData)(vlTOPp->riscv_top__DOT__ex_rd_addr))) 
                                            & (~ (IData)(vlTOPp->riscv_top__DOT__ex_ctrl_rd_src)))))));
        tracep->fullIData(oldp+233,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr
                                    [(0x3fffU & (vlTOPp->riscv_top__DOT__mem_alu_result 
                                                 >> 2U))]),32);
        tracep->fullIData(oldp+234,(vlTOPp->riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__i),32);
        tracep->fullIData(oldp+235,(0U),32);
        tracep->fullIData(oldp+236,(vlTOPp->riscv_top__DOT__id_rd_data),32);
        tracep->fullIData(oldp+237,(vlTOPp->riscv_top__DOT__ex_forward_rd_data),32);
        tracep->fullIData(oldp+238,(vlTOPp->riscv_top__DOT__ex_forward_alu_result),32);
        tracep->fullCData(oldp+239,(vlTOPp->riscv_top__DOT__wb_ctrl_result_src),2);
        tracep->fullIData(oldp+240,(vlTOPp->riscv_top__DOT__wb_imm),32);
        tracep->fullIData(oldp+241,(vlTOPp->riscv_top__DOT__wb_pc_plus_4),32);
        tracep->fullIData(oldp+242,(vlTOPp->riscv_top__DOT__wb_alu_result),32);
        tracep->fullIData(oldp+243,(3U),32);
        tracep->fullIData(oldp+244,(4U),32);
        tracep->fullIData(oldp+245,(2U),32);
        tracep->fullIData(oldp+246,(4U),32);
    }
}
