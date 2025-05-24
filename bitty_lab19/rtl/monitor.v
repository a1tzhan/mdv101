import "DPI-C" function void test_instruction(input bit [15:0] instruction, input bit [15:0] reg_0, input bit [15:0] reg_1, input bit [15:0] reg_2,
                                        input bit [15:0] reg_3, input bit [15:0] reg_4, input bit [15:0] reg_5,
                                        input bit [15:0] reg_6, input bit [15:0] reg_7);
module monitor(
    input wire clk,
    input wire [15:0] instruction, 
    input wire done,
    input wire [15:0] reg_0,
    input wire [15:0] reg_1,
    input wire [15:0] reg_2,
    input wire [15:0] reg_3,
    input wire [15:0] reg_4,
    input wire [15:0] reg_5,
    input wire [15:0] reg_6,
    input wire [15:0] reg_7
);

    reg dpi;

    always @(posedge clk) begin
        if(done) begin
            dpi <= 0'b1;
        end else begin
            dpi <= 0'b0;
        end
    end

    always @(posedge dpi) begin
        test_instruction(
            instruction,
            reg_0, reg_1, reg_2, reg_3,
            reg_4, reg_5, reg_6, reg_7
        );
    end
endmodule