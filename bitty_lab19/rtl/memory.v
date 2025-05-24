module memory(
    input wire clk,
    input wire [7:0] address,
    input wire [15:0] value_in,
    input wire we,
    output wire [15:0] instruction,
    output wire [15:0] value_out
);

    reg [15:0] mem [0:255];
    reg [15:0] reg_instruction;
    reg [15:0] reg_value_out;
    assign value_out = reg_value_out;
    assign instruction = reg_instruction;
    
    initial begin
        $readmemh("/mnt/c/Users/Professional/Desktop/mdv101/bitty_lab19/instructions.hex", mem);
    end

    /*always @(posedge clk) begin
        // Instruction fetch port (read-only)
        reg_instruction <= mem[address];

        // Data port: if we==1, write; else read
        if (we)
            mem[address] <= value_in;
        reg_value_out <= mem[address];
    end*/
    always @(*) begin
        reg_instruction = mem[address];
        if(instruction[1:0] == 2'b11 && instruction[2] == 1'b0) reg_value_out = mem[{5'b00000, instruction[12:10]}];
        else if(instruction[1:0] == 2'b11 && instruction[2] == 1'b1) mem[{5'b00000, instruction[12:10]}] = value_in;
    end
endmodule