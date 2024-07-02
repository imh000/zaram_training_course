// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		8		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"barrel_shifter.v"

module barrel_shifter_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg  [2:0] k;
	reg  [7:0] A;
	wire [7:0] Y;

	barrel_shifter
	u_barrel_shifter(
		.k					(k					),
		.A					(A					),
		.Y					(Y					)
	);

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	task init;
		begin
			k = 0;
			A = 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();

		for (i=0; i<`SIMCYCLE; i++) begin
			k = i;
			A = $urandom;
			#(1000/`CLKFREQ);
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
			$dumpfile("barrel_shifter_tb.vcd");
			$dumpvars;
		end
	end

endmodule
