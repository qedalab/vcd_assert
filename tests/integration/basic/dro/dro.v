// Adapted from TimEx generated files for vcd_assert testing
`timescale 1ps/100fs
module basic_dro (set, reset, out);

// Define inputs
input set, reset;

// Define outputs
output out;
reg out;

// State
integer state; 

// Internal state variables
wire internal_state_0,
     internal_state_1;

assign internal_state_0 = state == 0;
assign internal_state_1 = state == 1;

specify
    // Output delays spec params
    specparam delay_state1_reset_out = 5.5;

    // Critical timing spec params
    specparam ct_state0_set_reset    = 2.5;
    specparam ct_state0_reset_set    = 2.5;
    specparam ct_state1_set_reset    = 2.5;

    // Define output delays
    if (internal_state_1) (reset => out) = delay_state1_reset_out;

    // Define critical timing assertions
    $hold( posedge set &&& internal_state_0, reset, ct_state0_set_reset);
    $hold( negedge set &&& internal_state_0, reset, ct_state0_set_reset);

    $hold( posedge set &&& internal_state_1, reset, ct_state1_set_reset);
    $hold( negedge set &&& internal_state_1, reset, ct_state1_set_reset);

    $hold( posedge reset &&& internal_state_0, set, ct_state0_reset_set);
    $hold( negedge reset &&& internal_state_0, set, ct_state0_reset_set);

endspecify

initial begin
    state = 0;
    out = 0;
end

always @(posedge set or negedge set)
begin if ($time>2)
    case (state)
        0: begin 
            state = 1;
        end
    endcase
end

always @(posedge reset or negedge reset)
begin if ($time>2)
    case (state)
        1: begin 
            out = !out;
        end
    endcase
end

endmodule
