module alu_temp (
input wire [15:0] in_a,
input wire [15:0] in_b,
input wire [3:0] select,
input wire mode,
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
        .a(in_a), 
        .b(in_b), 
        .sel(select), 
        .ar_out(alu_out_arith)
    );

    assign alu_out = mode ? alu_out_logic : alu_out_arith;
endmodule
