// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		32		// # of Test Vector
//`define SPSRAM_ASYNC

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"sram_doubled.v"

module sram_doubled_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg clk;
	reg wen;
	reg cen;
	reg oen;
	reg [BW_ADDR-1:0] addr;
	reg [BW_DATA-1:0] i_data;
	wire [BW_DATA-1:0] o_data;

	parameter BW_DATA = 32;
	parameter BW_ADDR = 5;

	sram_doubled
	#(
		.BW_DATA			(BW_DATA			),
		.BW_ADDR			(BW_ADDR			)
	)
	u_sram_doubled(
		.clk				(clk				),
		.wen				(wen				),
		.cen				(cen				),
		.oen				(oen				),
		.addr				(addr				),
		.i_data				(i_data				),
		.o_data				(o_data				)
	);


// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	integer err = 0;

	task init;
		begin
			taskState = "Init";
			clk		= 0;
			wen		= 0;
			cen 	= 0;
			oen		= 0;
			addr	= 0;
			i_data	= 0;
		end
	endtask

	task memWR;
		input	[BW_ADDR-1:0] t_addr;
		input	[BW_DATA-1:0] t_data;
		begin
			@(negedge clk) begin
				taskState = "WR";
				i_data = t_data;
				addr = t_addr;
				cen	 = 1;
				wen  = 1;
				oen  = 0;
			end
		end
	endtask

	task memRD;
		input	[BW_ADDR-1:0] t_addr;
		begin
			@(negedge clk) begin
				taskState = "RD";
				addr = t_addr;
				cen = 1;
				wen = 0;
				oen = 1;
			end
		end
	endtask


	always #(500/`CLKFREQ) clk = ~clk;

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		#(4*1000/`CLKFREQ);

		for (i=0; i<`SIMCYCLE; i++) begin
			memWR(i, i);
		end
		for (i=0; i<`SIMCYCLE; i++) begin
			memRD(i);
		end
		$finish;
	end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end else begin
			$dumpfile("sram_doubled_tb.vcd");
			$dumpvars;
		end
	end

endmodule
