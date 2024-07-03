// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		50		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"signed_alu.v"

module signed_alu_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg signed [3:0] a;
	reg [3:0] b;
	reg cin;
	wire signed [3:0] sum;
	wire Cout;

	signed_alu
	u_signed_alu(
		.a					(a					),
		.b					(b					),
		.cin				(cin				),
		.sum				(sum				),
		.Cout				(Cout				)
	);

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	integer err = 0;

	task init;
		begin
			taskState = "Init";
			a = 0;
			b = 0;
			cin = 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();

		for (i=0; i<`SIMCYCLE; i++) begin
			a = $random;
			b = $random;
			cin = $random;
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
			$dumpfile("signed_alu_tb.vcd");
			$dumpvars;
		end
	end

endmodule
