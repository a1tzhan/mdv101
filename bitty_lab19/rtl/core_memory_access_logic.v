module core_memory_access_logic(
    input wire [15:0] instruction,
    input wire [15:0] memory_value,
    input wire [15:0] alu_value,
    input wire [15:0] reg_s_to_alu,
    output wire [15:0] value_to_regs,
    output wire [15:0] value_to_memory,
    output wire we
    );
    
    // avoid warning
    wire [6:0] empty_holder = instruction[9:3];
    wire _unused_holder_used = |empty_holder;
    reg [15:0] reg_value_to_regs;
    reg [15:0] reg_value_to_memory;
    assign value_to_memory = reg_value_to_memory;
    assign value_to_regs = reg_value_to_regs;

    always @(*) begin
        if(instruction[1:0] == 2'b11) begin
            if(instruction[2] == 1'b0) begin // load operation
                    reg_value_to_regs = memory_value;
                end
                else begin // store operation
                    reg_value_to_memory = reg_s_to_alu;
                end
        end else
        reg_value_to_regs = alu_value;
    end

endmodule

