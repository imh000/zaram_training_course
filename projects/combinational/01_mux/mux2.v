module mux2_assign
(
	input    i_sel,
	input    i_in0,
	input    i_in1,
	output   o_out
);

	assign o_out = i_sel ? i_in1 : i_in0;

endmodule

module mux2_if
(
	input          i_sel,
	input          i_in0,
	input          i_in1,
	output   reg   o_out
);

	always @ (*) begin
		if(i_sel == 0)
			o_out = i_in0;
		else
			o_out = i_in1;
	end

endmodule

module mux2_case
(
	input          i_sel,
	input          i_in0,
	input          i_in1,
	output   reg   o_out
);

	always @ (*) begin
		case(i_sel)
			0 : o_out = i_in0;
			1 : o_out = i_in1;
		endcase
	end

endmodule
