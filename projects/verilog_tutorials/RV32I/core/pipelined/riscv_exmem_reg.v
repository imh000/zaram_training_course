`ifndef NOINC
`include "../common/riscv_configs.v"
`endif

module riscv_exmem_reg
(
	input i_clk,
	input i_rstn,

	input [2:0] i_ex_funct3,
	output reg [2:0] o_mem_funct3,

	input i_ex_ctrl_rd_src,
	input i_ex_ctrl_reg_write,
	input i_ex_ctrl_mem_write,
	input [1:0] i_ex_ctrl_result_src,
	input [3:0] i_ex_ctrl_byte_sel,
	output reg o_mem_ctrl_rd_src,
	output reg o_mem_ctrl_reg_write,
	output reg o_mem_ctrl_mem_write,
	output reg [1:0] o_mem_ctrl_result_src,
	output reg [3:0] o_mem_ctrl_byte_sel,
	
	input [4:0] i_ex_rd_addr,
	input [`XLEN-1:0] i_ex_imm,
	input [`XLEN-1:0] i_ex_pc_plus_4,
	input [`XLEN-1:0] i_ex_pc_plus_imm,
	input [`XLEN-1:0] i_ex_alu_result,
	input [`XLEN-1:0] i_ex_write_data,
	output reg [4:0] o_mem_rd_addr,
	output reg [`XLEN-1:0] o_mem_imm,
	output reg [`XLEN-1:0] o_mem_alu_result,
	output reg [`XLEN-1:0] o_mem_pc_plus_4,
	output reg [`XLEN-1:0] o_mem_pc_plus_imm,
	output reg [`XLEN-1:0] o_mem_write_data
);

	always @ (posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_mem_ctrl_rd_src <= 0;
			o_mem_ctrl_reg_write <= 0;
			o_mem_ctrl_mem_write <= 0;
			o_mem_ctrl_result_src <= 0;
			o_mem_ctrl_byte_sel <= 0;

			o_mem_funct3 <= 0;

			o_mem_rd_addr <= 0;
			o_mem_imm <= 0;
			o_mem_pc_plus_4 <= 0;
			o_mem_pc_plus_imm <= 0;
			o_mem_alu_result <= 0;
			o_mem_write_data <= 0;
		end
		else begin
			o_mem_ctrl_rd_src <= i_ex_ctrl_rd_src;
			o_mem_ctrl_reg_write <= i_ex_ctrl_reg_write;
			o_mem_ctrl_mem_write <= i_ex_ctrl_mem_write;
			o_mem_ctrl_result_src <= i_ex_ctrl_result_src;
			o_mem_ctrl_byte_sel <= i_ex_ctrl_byte_sel;

			o_mem_funct3 <= i_ex_funct3;

			o_mem_rd_addr <= i_ex_rd_addr;
			o_mem_imm <= i_ex_imm;
			o_mem_pc_plus_4 <= i_ex_pc_plus_4;
			o_mem_pc_plus_imm <= i_ex_pc_plus_imm;
			o_mem_alu_result <= i_ex_alu_result;
			o_mem_write_data <= i_ex_write_data;
		end
	end

endmodule
