// Adapted from TimEx genrated files for vcd_assert testing
`define begin_time 8
`timescale 1ps/100fs
module basic_ndro (set, reset, clk, out);

// Define inputs
input set, reset, clk;

// Define outputs
output out;
wire out;

// Define internal outputs
reg internal_out;
assign out = internal_out;

// Define State
integer state;

// Internal state variables
wire internal_state_0,
     internal_state_1;

assign internal_state_0 = state === 0;
assign internal_state_1 = state === 1;

specify
    // Output delays spec params
    specparam delay_state1_clk_out = 7.0;

    // Critical timings spec param
    specparam ct_state0_reset_set = 2.5;
    specparam ct_state1_reset_set = 2.5;
    specparam ct_state1_clk_reset = 2.5;

    // Define output delays
    if (internal_state_1) (clk => out) = delay_state1_clk_out;

    // Define critical timings assertions
    $hold( posedge reset &&& internal_state_0, set, ct_state0_reset_set);
    $hold( negedge reset &&& internal_state_0, set, ct_state0_reset_set);

    $hold( posedge reset &&& internal_state_1, set, ct_state1_reset_set);
    $hold( negedge reset &&& internal_state_1, set, ct_state1_reset_set);

    $hold( posedge clk &&& internal_state_1, reset, ct_state1_clk_reset);
    $hold( negedge clk &&& internal_state_1, reset, ct_state1_clk_reset);

endspecify

// Set initial state
initial begin
    state = 1'bX;
    internal_out = 0;
    #`begin_time state = 0;
end

always @(posedge set or negedge set)
case (state)
    0: begin
        state = 1;
    end
endcase

always @(posedge reset or negedge reset)
case (state)
    1: begin
        state = 0;
    end
endcase

always @(posedge clk or negedge clk)
case (state)
    1: begin
        internal_out = !internal_out;
    end
endcase

endmodule
