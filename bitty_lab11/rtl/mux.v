module mux(
    input [15:0] reg_0, 
    input [15:0] reg_1,
    input [15:0] reg_2,
    input [15:0] reg_3,
    input [15:0] reg_4,
    input [15:0] reg_5,
    input [15:0] reg_6,
    input [15:0] reg_7,
    input [2:0] sel, // select
    output reg [15:0] out // output
);

always @(*) begin
    case(sel)
        3'h0: out = reg_0;
        3'h1: out = reg_1;
        3'h2: out = reg_2;
        3'h3: out = reg_3;
        3'h4: out = reg_4;
        3'h5: out = reg_5;
        3'h6: out = reg_6;
        3'h7: out = reg_7;
        default: out = 16'b0;
    endcase
end
endmodule