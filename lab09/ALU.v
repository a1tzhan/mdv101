module ALU (
input wire carry_in,
input wire [15:0] in_a,
input wire [15:0] in_b,
input wire [3:0] select,
input wire mode,
output wire carry_out,
output wire compare,
output wire [15:0] alu_out
);
    wire [15:0] alu_out_logic, alu_out_arith;

    logic_unit lu01 (
        .a(in_a), 
        .b(in_b), 
        .sel(select), 
        .lo_out(alu_out_logic)
    );

    arithmetic_unit au01 (
        .cin(carry_in), 
        .a(in_a), 
        .b(in_b), 
        .sel(select), 
        .cout(carry_out), 
        .cmp(compare), 
        .ar_out(alu_out_arith)
    );

    assign alu_out = mode ? alu_out_logic : alu_out_arith;

endmodule
