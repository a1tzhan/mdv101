module top_module (
	input wire carry_in,
	input wire [15:0] in_a,
	input wire [15:0] in_b, 
	input wire [3:0] select,
	input wire mode,
	output wire cout,
	output wire compare,
	output wire [15:0] alu_out);

	ALU alu01(carry_in, in_a, in_b, select, mode, cout, compare, alu_out);

endmodule
