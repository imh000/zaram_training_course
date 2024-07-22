`ifndef	NOINC
`include "../common/riscv_configs.v"'
`include "../common/riscv_adder.v"
`include "../common/riscv_alu.v"
`include "../common/riscv_immdecode.v"
`include "../common/riscv_mux.v"
`include "../common/riscv_regfile.v"
`include "../common/riscv_register.v"
`endif

module riscv_datapath
#(
	parameter REGISTER_INIT = 0
)
(
	input [`XLEN-1:0] i_dp_mem_rd_data,
	input [`XLEN-1:0] i_dp_instr,
	input [2:0] i_dp_src_imm,
	input [1:0] i_dp_src_pc,
	input [1:0] i_dp_src_rd,
	input i_dp_src_alu_a,
	input i_dp_src_alu_b,
	input i_dp_reg_wr_en,
	input [3:0] i_dp_alu_ctrl,
	input i_clk,
	input i_rstn,
	output [`XLEN-1:0] o_dp_pc,
	output o_do_alu_zero,
	output [`XLEN-1:0] 
