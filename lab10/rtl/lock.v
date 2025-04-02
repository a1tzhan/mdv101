module lock ( // 3, 3, 5, 2, 5, 6 correct sequence
    input clk,
    input reset,           // Asynchronous reset
    input [3:0] in,
    output locked // locked (0 when unlocked, 1 otherwise)
);
    // State encoding
    parameter S0 = 3'd0;
    parameter S1 = 3'd1;
    parameter S2 = 3'd2;
    parameter S3 = 3'd3;
    parameter S4 = 3'd4;
    parameter S5 = 3'd5;
    parameter S6 = 3'd6;

    reg [2:0] current_state, next_state;

    // Model state register (sequential logic)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            current_state <= S0;
        end else begin
            current_state <= next_state;
        end
    end

    // Model next state decode logic (combinational logic)
    always @(*) begin
        case (current_state)
            S0: begin
                next_state = (in == 4'd3) ? S1 : S0;
            end
            S1: begin
                next_state = (in == 4'd3) ? S2 : S0;
            end
            S2: begin
                next_state = (in == 4'd5) ? S3 : S0;
            end
            S3: begin
                next_state = (in == 4'd2) ? S4 : S0;
            end
            S4: begin
                next_state = (in == 4'd5) ? S5 : S0;
            end
            S5: begin
                next_state = (in == 4'd6) ? S6 : S0;
            end
            S6: next_state = S6;
            default: next_state = S0;
        endcase
    end

    // Model output logic (combinational logic)
    assign locked = !(current_state == S6);
endmodule