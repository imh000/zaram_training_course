// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: HyeRyun Lim (imh2880@gmail.com)
//	* Filename		: sram_doubled.v
//	* Date			: 2024-06-26 17:32:36
//	* Description	: 
//	00000
//	~
//	01111
//
//	10000
//	~
//	11111
//	only addr[4] is different.
// ==================================================

`include "spsram.v"
module sram_doubled
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
	spsram
	#(
		.BW_DATA			(32			),
		.BW_ADDR			(4			)
	)
	u_spsram0(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(~addr[4]			),
		.oen				(~addr[4]			),
		.addr				(addr[3:0]			),
		.i_data				(i_data				),
		.o_data				(o_data				)
	);

	spsram
	#(
		.BW_DATA			(32			),
		.BW_ADDR			(4			)
	)
	u_spsram1(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(addr[4]			),
		.oen				(addr[4]			),
		.addr				(addr[3:0]			),
		.i_data				(i_data				),
		.o_data				(o_data				)
	);
endmodule
