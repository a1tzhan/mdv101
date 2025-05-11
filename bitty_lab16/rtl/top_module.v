module top_module(
    input wire clk,
    input wire run,
    input wire reset
);

wire [15:0] instruction;
wire done;

fetch_unit fetch1 (.clk(clk), .reset(reset), .done(done), .out(instruction));

bitty_core bitty1 (.reset(reset), .clk(clk), .instruction(instruction), .run(run), .done(done));

endmodule