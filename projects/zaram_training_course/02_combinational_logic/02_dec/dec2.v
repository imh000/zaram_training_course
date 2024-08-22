module dec2_dataflow
(
	input    [1:0]   i_in,
	input            i_en,
	output   [3:0]   o_out
);
	
	assign o_out = i_en ? (4'd1 << i_in) : 4'd0;
endmodule

module dec2_behavior
(
	input    [1:0]   i_in,
	input    i_en,
	output   reg     [3:0]   o_out
);
	
	always @ (*) begin
		if(i_en == 1) begin
			case(i_in)
				0 : o_out = 4'b0001;
				1 : o_out = 4'b0010;
				2 : o_out = 4'b0100;
				3 : o_out = 4'b1000;
			endcase
		end
		else
			o_out = 4'd0;
	end
endmodule
