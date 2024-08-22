`include "../common/riscv_configs.v"

module riscv_idex_reg
(
	input i_clk,
	input i_rstn,

	input i_flushE,

	input [2:0] i_id_funct3,
	output reg [2:0] o_ex_funct3,

	input i_id_ctrl_reg_write,
	input [1:0] i_id_ctrl_result_src,
	input i_id_ctrl_mem_write,
	input [1:0] i_id_ctrl_jump,
	input i_id_ctrl_branch,
	input [3:0] i_id_ctrl_byte_sel,
	input [3:0] i_id_ctrl_alu_ctrl,
	input i_id_ctrl_alu_b_src,
	input i_id_ctrl_rd_src,
	output reg o_ex_ctrl_reg_write,
	output reg [1:0] o_ex_ctrl_result_src,
	output reg o_ex_ctrl_mem_write,
	output reg [1:0] o_ex_ctrl_jump,
	output reg o_ex_ctrl_branch,
	output reg [3:0] o_ex_ctrl_byte_sel,
	output reg [3:0] o_ex_ctrl_alu_ctrl,
	output reg o_ex_ctrl_alu_b_src,
	output reg o_ex_ctrl_rd_src,

	input [`XLEN-1:0] i_id_rs1_data,
	input [`XLEN-1:0] i_id_rs2_data,
	input [4:0] i_id_rs1_addr,
	input [4:0] i_id_rs2_addr,
	input [4:0] i_id_rd_addr,
	input [`XLEN-1:0] i_id_imm,
	input [`XLEN-1:0] i_id_pc,
	input [`XLEN-1:0] i_id_pc_plus_4,
	output reg [`XLEN-1:0] o_ex_rs1_data,
	output reg [`XLEN-1:0] o_ex_rs2_data,
	output reg [4:0] o_ex_rs1_addr,
	output reg [4:0] o_ex_rs2_addr,
	output reg [4:0] o_ex_rd_addr,
	output reg [`XLEN-1:0] o_ex_imm,
	output reg [`XLEN-1:0] o_ex_pc,
	output reg [`XLEN-1:0] o_ex_pc_plus_4
);

	always @ (posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_ex_ctrl_reg_write <= 0;
			o_ex_ctrl_result_src <= 0;
			o_ex_ctrl_mem_write <= 0;
			o_ex_ctrl_jump <= 0;
			o_ex_ctrl_branch <= 0;
			o_ex_ctrl_byte_sel <= 0;
			o_ex_ctrl_alu_ctrl <= 0;
			o_ex_ctrl_alu_b_src <= 0;
			o_ex_ctrl_rd_src <= 0;

			o_ex_funct3 <= 0;

			o_ex_rs1_data <= 0;
			o_ex_rs2_data <= 0;
			o_ex_rs1_addr <= 0;
			o_ex_rs2_addr <= 0;
			o_ex_rd_addr <= 0;
			o_ex_imm <= 0;
			o_ex_pc <= 0;
			o_ex_pc_plus_4 <= 0;
		end
		else if(i_flushE) begin
			o_ex_ctrl_reg_write <= 0;
			o_ex_ctrl_result_src <= 0;
			o_ex_ctrl_mem_write <= 0;
			o_ex_ctrl_jump <= 0;
			o_ex_ctrl_branch <= 0;
			o_ex_ctrl_byte_sel <= 0;
			o_ex_ctrl_alu_ctrl <= 0;
			o_ex_ctrl_alu_b_src <= 0;
			o_ex_ctrl_rd_src <= 0;

			o_ex_funct3 <= 0;

			o_ex_rs1_data <= 0;
			o_ex_rs2_data <= 0;
			o_ex_rs1_addr <= 0;
			o_ex_rs2_addr <= 0;
			o_ex_rd_addr <= 0;
			o_ex_imm <= 0;
			o_ex_pc <= 0;
			o_ex_pc_plus_4 <= 0;
		end
		else begin
			o_ex_ctrl_reg_write <= i_id_ctrl_reg_write;
			o_ex_ctrl_result_src <= i_id_ctrl_result_src;
			o_ex_ctrl_mem_write <= i_id_ctrl_mem_write;
			o_ex_ctrl_jump <= i_id_ctrl_jump;
			o_ex_ctrl_branch <= i_id_ctrl_branch;
			o_ex_ctrl_byte_sel <= i_id_ctrl_byte_sel;
			o_ex_ctrl_alu_ctrl <= i_id_ctrl_alu_ctrl;
			o_ex_ctrl_alu_b_src <= i_id_ctrl_alu_b_src;
			o_ex_ctrl_rd_src <= i_id_ctrl_rd_src;

			o_ex_funct3 <= i_id_funct3;

			o_ex_rs1_data <= i_id_rs1_data;
			o_ex_rs2_data <= i_id_rs2_data;
			o_ex_rs1_addr <= i_id_rs1_addr;
			o_ex_rs2_addr <= i_id_rs2_addr;
			o_ex_rd_addr <= i_id_rd_addr;
			o_ex_imm <= i_id_imm;
			o_ex_pc <= i_id_pc;
			o_ex_pc_plus_4 <= i_id_pc_plus_4;
		end
	end

endmodule
