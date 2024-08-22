// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: HyeRyun Lim (imh2880@gmail.com)
//	* Filename		: regfile.v
//	* Date			: 2024-06-26 17:30:45
//	* Description	: 2 read ports & 1 wirte port
// ==================================================
module regfile
#(
	parameter MIF_FILE = "regfile.mif",
	parameter BW_DATA = 32,
	parameter BW_ADDR = 5
)
(
	input clk,
	input wen,
	input [BW_ADDR-1:0] rd_addr0,
	input [BW_ADDR-1:0] rd_addr1,
	input [BW_ADDR-1:0] wr_addr,
	input [BW_DATA-1:0] wr_data,
	output [BW_DATA-1:0] rd_data0,
	output [BW_DATA-1:0] rd_data1
);

	reg		[BW_DATA-1:0]	rf_arr[0:2**BW_ADDR-1];

	`ifdef MEM_INIT
		initial begin
			$readmemb(MIF_FILE, rf_arr);
		end
	`endif

	// Async read
	assign rd_data0 = rf_arr[rd_addr0];
	assign rd_data1 = rf_arr[rd_addr1];

	//write
	always @ (posedge clk) begin
		if(wen)
			rf_arr[wr_addr] <= wr_data;
		else
			rf_arr[wr_addr] <= rf_arr[wr_addr];
	end
endmodule
