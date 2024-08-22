`define CLKFREQ		100
`define NVEC		100
`define SIMCYCLE	`NVEC

`define DF_DATA		6

`include "adder.v"

module adder_tb ();

	parameter PAR_DATA = 6;

	wire [PAR_DATA-1:0] sum_param;
	wire [`DF_DATA-1:0] sum_def;
	wire cout_param;
	wire cout_def;
	reg [PAR_DATA-1:0] i_a;
	reg [PAR_DATA-1:0] i_b;
	reg cin;

	adder_param
	#(
		.BW_DATA(PAR_DATA)
	)
	u_adder_param
	(
		.sum(sum_param),
		.cout(cout_param),
		.i_a(i_a),
		.i_b(i_b),
		.cin(cin)
	);

	adder_def
	u_adder_def
	(
		.sum(sum_def),
		.cout(cout_def),
		.i_a(i_a),
		.i_b(i_b),
		.cin(cin)
	);

	integer i;
	initial begin
		for (i = 0; i < `SIMCYCLE; i++) begin
			i_a = $urandom;
			i_b = $urandom;
			cin = $urandom;
			#(1000/`CLKFREQ);
		end
		$finish;
	end

	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end
		else begin
			$dumpfile("adder_tb.vcd");
			$dumpvars;
		end
	end
	endmodule
