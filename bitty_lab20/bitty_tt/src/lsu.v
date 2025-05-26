module lsu (
    //General ports
    input  wire        clk,
    input  wire        reset,       // Active-low reset
    output reg         done_out,    // Signal indicating the operation is complete

    // Control and Data ports
    input  wire [1:0]  en_ls,       // Load/Store control signal
    input  wire [7:0]  address,     // 8-bit memory address
    input  wire [15:0] data_to_store, // Data to be sent for storing
    output reg  [15:0] data_to_load,  // Data received from loading

    // Ports for UART Interaction
    input  wire        rx_do,       // Signal indicating data received from UART
    input  wire [7:0]  rx_data,     // Data byte received from UART
    input  wire        tx_done,     // Signal indicating UART transmission is done
    output reg         tx_start_out,// Signal to start UART transmission (active low)
    output reg  [7:0]  tx_data_out  // Data byte to be transmitted over UART
);

    reg [15:0] reg_data_to_load;    // 16-bit instruction received
    reg tx_start;              // Signal to start UART transmission
    reg [7:0] tx_data;         // Data to be transmitted over UART
    reg done;                  // Signal indicating the operation is complete

    assign done_out = done;
    assign reg_data_to_load = data_to_load;
    assign tx_start_out = tx_start;
    assign tx_data_out = tx_data;

    // State encoding
    parameter IDLE           = 3'b000;
    parameter SEND_FLAG      = 3'b001;
    parameter SEND_ADDR      = 3'b010;
    parameter SEND_DATA_LOW  = 3'b011;  // For store operations
    parameter SEND_DATA_HIGH = 3'b100;  // For store operations
    parameter RECEIVE_DATA_LOW  = 3'b101;  // For load operations
    parameter RECEIVE_DATA_HIGH = 3'b110;  // For load operations
    parameter DONE           = 3'b111;
    
    reg [3:0] state, next_state;

    // Command bytes
    localparam FLAG_LOAD  = 8'b00000001; 
    localparam FLAG_STORE = 8'b00000010;

    // Sequential logic for state transition
    always @(posedge clk) begin
        //ff_a <= instruction;
		if (!reset) begin
			state <= IDLE;
		end
		else begin
			state <= next_state;
		end
    end

    // State machine logic
    // Design Load on address and Store on address
    // We have Load on address in form of instruction load, need to store now
    // It takes 7 states to load address
    // Max I'll need 14 but I think less
    /* verilator lint_off LATCH */
    always @(*) begin
        // Default values
        tx_start = 1;  // No transmission by default
        tx_data = 8'b0;
        done = 0;
        data_to_load = data_to_load;  // Retain previous value
        case (state)

            SEND_FLAG: begin
                if(en_ls == 2'b01) begin
                    tx_data = FLAG_LOAD; // Flag to load
                end else if(en_ls == 2'b10) begin
                    tx_data = FLAG_STORE; // Flag to store
                end
                tx_start = 0;  // Start transmission
                done = 0;
            end

            SEND_ADDR: begin
                tx_data = address;  // Send address byte
                tx_start = 0;  // Start transmission
            end

            SEND_DATA_HIGH: begin
                tx_data = data_to_store[15:8];   // Send upper 8 bits of data
                tx_start = 0;   // Start transmission
            end

            SEND_DATA_LOW: begin
                tx_data = data_to_store[7:0]; // Send lower 8 bits of data
                tx_start = 0; // Start transmission
            end

            RECEIVE_DATA_HIGH: begin
                if (rx_do) begin
                    data_to_load[15:8] = rx_data;  // Load lower 8 bits of data
                end
            end

            RECEIVE_DATA_LOW: begin
                if (rx_do) begin
                    data_to_load[7:0] = rx_data;  // Store upper 8 bits of data
                end
            end

            DONE: begin
                done = 1;  // Set done signal
                $display("Done for Store/Load");
            end

            default: begin
				tx_start = 1;  // No transmission by default
                tx_data = 8'b00000000;
                done = 0;
                data_to_load = data_to_load;
            end
        endcase
    end

    always @(*) begin
        case (state)
            SEND_FLAG: begin
                /*if(tx_done) begin
                    $display("tx_done in FLAG state");
                end*/
                if (tx_done & (en_ls == 2'b01 | en_ls == 2'b10)) begin       // Load operation
                    next_state = SEND_ADDR;
                end
                else begin
                    next_state = SEND_FLAG;
                end
            end
            SEND_ADDR: begin
                /*if(tx_done) begin
                    $display("tx_done in ADDR");
                end*/
                if (en_ls == 2'b10) begin  // Store operation
                    next_state = (tx_done) ? SEND_DATA_HIGH : SEND_ADDR;
                end
                else begin                 // Load operation
                    next_state = (tx_done) ? RECEIVE_DATA_HIGH : SEND_ADDR;
                end
            end
            SEND_DATA_LOW: next_state = (tx_done) ?  DONE : SEND_DATA_LOW;
            SEND_DATA_HIGH: next_state = (tx_done) ? SEND_DATA_LOW : SEND_DATA_HIGH;
            RECEIVE_DATA_HIGH: next_state = (rx_do) ? RECEIVE_DATA_LOW:RECEIVE_DATA_HIGH;
            RECEIVE_DATA_LOW: next_state = (rx_do) ? DONE:RECEIVE_DATA_LOW;
            DONE: next_state = SEND_FLAG;
            default: next_state = SEND_FLAG;
        endcase 
    end
endmodule