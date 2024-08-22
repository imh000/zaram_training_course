// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		32		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"ALU.v"

module ALU_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg		 [2:0]  F;
	reg		 [31:0] A;
	reg		 [31:0] B;
	wire	 [31:0] ALUOut;
	wire			Cout;

	ALU
	u_ALU(
		.F					(F					),
		.A					(A					),
		.B					(B					),
		.ALUOut				(ALUOut				),
		.Cout				(Cout				)
	);


// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;

	task init;
		begin
			F = 0;
			A = 0;
			B = 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();

		for (i=0; i<`SIMCYCLE; i++) begin
			F = $urandom;
			A = $urandom;
			B = $urandom;
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
			$dumpfile("ALU_tb.vcd");
			$dumpvars;
		end
	end
endmodule
