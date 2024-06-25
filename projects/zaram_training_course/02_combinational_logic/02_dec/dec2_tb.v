`define CLKFREQ		10 //MHz
`define SIMCYCLE	20

`include "dec2.v"

module dec2_tb ();

	reg    [1:0]   i_in;
	reg 		   i_en;
	wire   [3:0]   o_out_dataflow;
	wire   [3:0]   o_out_behavior;

	dec2_dataflow
	u_dec2_dataflow
	(
		.i_in(i_in),
		.i_en(i_en),
		.o_out(o_out_dataflow)
	);

	dec2_behavior
	u_dec2_behavior
	(
		.i_in(i_in),
		.i_en(i_en),
		.o_out(o_out_behavior)
	);

	task init;
		begin
			i_in = 0;
			i_en = 0;
		end
	endtask

	integer i;
	initial begin
		init();
		for(i=0; i<`SIMCYCLE; i++) begin
			{i_in, i_en} = $urandom_range(0, 7);
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
			$dumpfile("dec2_tb.vcd");
			$dumpvars;
		end
	end
endmodule
