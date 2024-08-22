`ifndef NOINC
`include "../common/riscv_configs.v"
`endif

module riscv_hazard_unit
(
	input i_clk,

	input [4:0] i_id_rs1_addr,
	input [4:0] i_id_rs2_addr,
	input [4:0] i_ex_rs1_addr,
	input [4:0] i_ex_rs2_addr,
	input [4:0] i_ex_rd_addr,
	input [4:0] i_mem_rd_addr,
	input [4:0] i_wb_rd_addr,

	input [1:0] i_ex_ctrl_pc_src,
	input i_mem_ctrl_reg_write,
	input i_wb_ctrl_reg_write,
	input i_ex_ctrl_rd_src,

	output reg o_if_stall,
	output reg o_id_stall,
	output reg o_id_flush,
	output reg o_ex_flush,
	output reg [1:0] o_ForwardAE,
	output reg [1:0] o_ForwardBE
);
	
	// ForwardAE
	always @ (*) begin
		if(i_mem_ctrl_reg_write && (i_mem_rd_addr != 0) && (i_ex_rs1_addr == i_mem_rd_addr))
			o_ForwardAE = 2'b10;
		else if(i_wb_ctrl_reg_write && (i_wb_rd_addr != 0) && (i_ex_rs1_addr == i_wb_rd_addr))
			o_ForwardAE = 2'b01;
		else
			o_ForwardAE = 2'b00;
	end

	// ForwardBE
	always @ (*) begin
		if(i_mem_ctrl_reg_write && (i_mem_rd_addr != 0) && (i_ex_rs2_addr == i_mem_rd_addr))
			o_ForwardBE = 2'b10;
		else if(i_wb_ctrl_reg_write && (i_wb_rd_addr != 0) && (i_ex_rs2_addr == i_wb_rd_addr))
			o_ForwardBE = 2'b01;
		else
			o_ForwardBE = 2'b00;
	end

	// lw stall
	always @ (*) begin
		if(((i_id_rs1_addr == i_ex_rd_addr) || (i_id_rs2_addr == i_ex_rd_addr)) && (i_ex_ctrl_rd_src == 1'b0)) begin
			o_if_stall = 1'b1;
			o_id_stall = 1'b1;
			o_ex_flush = 1'b1;
		end
		else begin
			o_if_stall = 1'b0;
			o_id_stall = 1'b0;
			o_ex_flush = 1'b0;
		end
	end

	// branch flush
	always @ (*) begin
		if((i_ex_ctrl_pc_src == 2'b01) || (i_ex_ctrl_pc_src == 2'b10)) begin
			o_id_flush = 1'b1;
			o_ex_flush = 1'b1;
		end
		else begin
			o_id_flush = 1'b0;
			o_ex_flush = 1'b0;
		end
	end

endmodule
