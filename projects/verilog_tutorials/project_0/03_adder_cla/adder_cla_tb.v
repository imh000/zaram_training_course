// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		50		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"adder_cla.v"

module adder_cla_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg [31:0] a;
	reg [31:0] b;
	reg cin;
	wire cout;
	wire [31:0] sum;
	wire [31:0] sum_test;

	adder_cla
	u_adder_cla(
		.a					(a					),
		.b					(b					),
		.cin				(cin				),
		.cout				(cout				),
		.sum				(sum				),
		.sum_test			(sum_test			)
	);

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;

	task init;
		begin
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
			a = $urandom;
			b = $urandom;
			cin = $urandom;
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
			$dumpfile("adder_cla_tb.vcd");
			$dumpvars;
		end
	end

endmodule
