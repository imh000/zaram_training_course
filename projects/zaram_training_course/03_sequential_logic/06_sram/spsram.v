module spsram
#(
	parameter	BW_DATA = 32,
	parameter	BW_ADDR = 5
)
(
	input clk,
	input wen,
	input cen,
	input oen,
	input [BW_ADDR-1:0] addr,
	input [BW_DATA-1:0] i_data,
	output [BW_DATA-1:0] o_data
);

	// Memory Write
	reg		[BW_DATA-1:0]	mem[0:2**BW_ADDR-1];
	always @ (posedge clk) begin
		if(cen && wen)
			mem[addr] <= i_data;
		else
			mem[addr] <= mem[addr];
	end

	// Memory Read
	`ifdef	SPSRAM_ASYNC
		assign o_data = !oen ? 'bz :
						cen && !wen ? mem[addr] : 'bx;
	`else //sync
		reg		[BW_DATA-1:0] o_data;
		always @ (posedge clk) begin
			if(oen) begin
				if(cen && !wen)
					o_data <= mem[addr];
				else
					o_data <= 'bx;
			end
			else
				o_data <= 'bz;
		end
	`endif

endmodule
