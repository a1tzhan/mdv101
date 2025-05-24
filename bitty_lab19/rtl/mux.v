module mux(
    input [15:0] reg_0, 
    input [15:0] reg_1,
    input [15:0] reg_2,
    input [15:0] reg_3,
    input [15:0] reg_4,
    input [15:0] reg_5,
    input [15:0] reg_6,
    input [15:0] reg_7,
    input [15:0] imm,
    input [3:0] sel, // select
    output reg [15:0] out // output
);

always @(*) begin
    case(sel)
        4'h0: out = reg_0;
        4'h1: out = reg_1;
        4'h2: out = reg_2;
        4'h3: out = reg_3;
        4'h4: out = reg_4;
        4'h5: out = reg_5;
        4'h6: out = reg_6;
        4'h7: out = reg_7;
        4'h8: out = imm;
        default: out = 16'b0;
    endcase
end
endmodule