// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: HyeRyun Lim (imh2880@gmail.com)
//	* Filename		: sram_extension.v
//	* Date			: 2024-07-01 10:27:18
//	* Description	: 
// ==================================================

module sram_extension
(
	input		  clk,
	input		  wen,
	input		  cen,
	input		  oen,
	input  [5:0]  addr,
	input  [63:0] i_data,
	output [63:0] o_data
);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram0(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(~addr[5] & ~addr[4]),
		.oen				(~addr[5] & ~addr[4]),
		.addr				(addr[3:0]			),
		.i_data				(i_data[31:0]		),
		.o_data				(o_data[31:0]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram1(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(~addr[5] & ~addr[4]),
		.oen				(~addr[5] & ~addr[4]),
		.addr				(addr[3:0]			),
		.i_data				(i_data[63:32]		),
		.o_data				(o_data[63:32]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram2(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(~addr[5] & addr[4] ),
		.oen				(~addr[5] & addr[4] ),
		.addr				(addr[3:0]			),
		.i_data				(i_data[31:0]		),
		.o_data				(o_data[31:0]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram3(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(~addr[5] & addr[4] ),
		.oen				(~addr[5] & addr[4] ),
		.addr				(addr[3:0]			),
		.i_data				(i_data[63:32]		),
		.o_data				(o_data[63:32]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram4(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(addr[5] & ~addr[4] ),
		.oen				(addr[5] & ~addr[4] ),
		.addr				(addr[3:0]			),
		.i_data				(i_data[31:0]		),
		.o_data				(o_data[31:0]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram5(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(addr[5] & ~addr[4] ),
		.oen				(addr[5] & ~addr[4] ),
		.addr				(addr[3:0]			),
		.i_data				(i_data[63:32]		),
		.o_data				(o_data[63:32]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram6(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(addr[5] & addr[4]  ),
		.oen				(addr[5] & addr[4]  ),
		.addr				(addr[3:0]			),
		.i_data				(i_data[31:0]		),
		.o_data				(o_data[31:0]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram7(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(addr[5] & addr[4]  ),
		.oen				(addr[5] & addr[4]  ),
		.addr				(addr[3:0]			),
		.i_data				(i_data[63:32]		),
		.o_data				(o_data[63:32]		)
	);
endmodule

module spsram
#(
	parameter	BW_DATA = 32,
	parameter	BW_ADDR = 4
)
(
	input				 clk,
	input				 wen,
	input				 cen,
	input				 oen,
	input  [BW_ADDR-1:0] addr,
	input  [BW_DATA-1:0] i_data,
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
