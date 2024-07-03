module adder_cla
(
	input  [31:0] a,
	input  [31:0] b,
	input         cin,
	output        cout,
	output [31:0] sum
);

	wire [8:0] co;
	
	assign co[0] = cin;

	genvar i;
	generate
		for(i=0; i<8; i=i+1) begin : adder_cla_loop
			adder_cla_4bit
			u_adder_cla_4bit(
				.a					(a[4*i+3:4*i]		),
				.b					(b[4*i+3:4*i]		),
				.cin				(co[i]				),
				.cout				(co[i+1]			),
				.sum				(sum[4*i+3:4*i]		)
			);
		end
	endgenerate

	assign cout = co[8];

endmodule
	
module adder_cla_4bit
(
	input  [3:0] a,
	input  [3:0] b,
	input        cin,
	output       cout,
	output [3:0] sum
);

	wire [3:0] P, G, C;
	wire out_P, out_G;

	// bitwise PG Logic
	assign P = a ^ b;
	assign G = a & b;

	// Group PG Logic
	assign C[0] = cin;
	assign C[1] = G[0] | (P[0] & C[0]);
	assign C[2] = G[1] | (P[1] & C[1]);
	assign C[3] = G[2] | (P[2] & C[2]);
	assign cout = G[3] | P[3] & C[3];

	// Sum LogiC
	assign sum = a ^ b ^ C;

endmodule

