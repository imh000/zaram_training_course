`include "mux2.v"

module mux2_tb;

// ========================================
// Module Instanciation
// ========================================
	reg    i_sel;
	reg    i_in0;
	reg    i_in1;
	wire   o_out_assign;
	wire   o_out_if;
	wire   o_out_case;

	mux2_assign u_0
	(
		.i_sel         (i_sel),
		.i_in0         (i_in0),
		.i_in1         (i_in1),
		.o_out   (o_out_assign)
	);

	mux2_if u_1
	(
		.i_sel (i_sel),
		.i_in0 (i_in0),
		.i_in1 (i_in1),
		.o_out (o_out_if)
	);

	mux2_case u_2
	(
		.i_sel (i_sel),
		.i_in0 (i_in0),
		.i_in1 (i_in1),
		.o_out (o_out_case)
	);

	integer i;
	initial begin
		for(i=0; i<10; i++) begin
			{i_sel, i_in0, i_in1} = $urandom_range(0, 7);
			#(100);
		end	
		$finish;
	end

	reg [8*32-1:0]  vcd_file;
    initial begin
        if ($value$plusargs("vcd_file=%s", vcd_file)) begin
            $dumpfile(vcd_file);
            $dumpvars;
        end
    end
 
endmodule
