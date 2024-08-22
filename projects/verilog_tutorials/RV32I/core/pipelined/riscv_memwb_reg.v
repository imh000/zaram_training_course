`ifndef NOINC
`include "../common/riscv_configs.v"
`endif

module riscv_memwb_reg
(
	input i_clk,
	input i_rstn,

	input i_mem_ctrl_reg_write,
	input i_mem_ctrl_rd_src,
	output reg o_wb_ctrl_reg_write,
	output reg o_wb_ctrl_rd_src,

	input [4:0] i_mem_rd_addr,
	input [`XLEN-1:0] i_mem_rd_result,
	input [`XLEN-1:0] i_mem_read_data,
	output reg [4:0] o_wb_rd_addr,
	output reg [`XLEN-1:0] o_wb_rd_result,
	output reg [`XLEN-1:0] o_wb_read_data
);

	always @ (posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_wb_ctrl_reg_write <= 0;
			o_wb_ctrl_rd_src <= 0;

			o_wb_rd_addr <= 0;
			o_wb_rd_result <= 0;
			o_wb_read_data <= 0;
		end
		else begin
			o_wb_ctrl_reg_write <= i_mem_ctrl_reg_write;
			o_wb_ctrl_rd_src <= i_mem_ctrl_rd_src;

			o_wb_rd_addr <= i_mem_rd_addr;
			o_wb_rd_result <= i_mem_rd_result;
			o_wb_read_data <= i_mem_read_data;
		end
	end

endmodule
