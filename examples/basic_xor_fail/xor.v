// Adapted from TimEx generated files for vcd_assert
`timescale 1ps/100fs
module basic_xor (a, b, clk, out);

// Define inputs
input a, b, clk;

// Define outputs
output out;
wire out;

// Define output internal variables
reg internal_out;
assign out = internal_out;

// Define state
integer state;

// Internal state variables
wire internal_state_0,
     internal_state_1,
     internal_state_2;

assign internal_state_0 = state == 0;
assign internal_state_1 = state == 1;
assign internal_state_2 = state == 2;

// Internal state variables
specify
    // Output delays
    specparam delay_state1_clk_out = 5;
    specparam delay_state2_clk_out = 5;

    // Critical timing spec params
    specparam ct_state0_a_clk = 2.5;
    specparam ct_state0_b_clk = 2.5;
    specparam ct_state1_a_b = 2.5;
    specparam ct_state1_a_clk = 2.5;
    specparam ct_state1_clk_b = 2.5;
    specparam ct_state2_b_a = 2.5;
    specparam ct_state2_b_clk = 2.5;
    specparam ct_state2_clk_a = 2.5;

    // Define output delays
    if (internal_state_1) (clk => out) = delay_state1_clk_out;
    if (internal_state_2) (clk => out) = delay_state2_clk_out;

    // Define critical timings assertions
    $hold( posedge a &&& internal_state_0, clk, ct_state0_a_clk);
    $hold( negedge a &&& internal_state_0, clk, ct_state0_a_clk);

    $hold( posedge b &&& internal_state_0, clk, ct_state0_b_clk);
    $hold( negedge b &&& internal_state_0, clk, ct_state0_b_clk);

    $hold( posedge a &&& internal_state_1, b, ct_state1_a_b);
    $hold( negedge a &&& internal_state_1, b, ct_state1_a_b);

    $hold( posedge a &&& internal_state_1, clk, ct_state1_a_clk);
    $hold( negedge a &&& internal_state_1, clk, ct_state1_a_clk);

    $hold( posedge clk &&& internal_state_1, b, ct_state1_clk_b);
    $hold( negedge clk &&& internal_state_1, b, ct_state1_clk_b);

    $hold( posedge b &&& internal_state_2, a, ct_state2_b_a);
    $hold( negedge b &&& internal_state_2, a, ct_state2_b_a);

    $hold( posedge b &&& internal_state_2, clk, ct_state2_b_clk);
    $hold( negedge b &&& internal_state_2, clk, ct_state2_b_clk);

    $hold( posedge clk &&& internal_state_2, a, ct_state2_clk_a);
    $hold( negedge clk &&& internal_state_2, a, ct_state2_clk_a);

endspecify

initial begin
    state = 0;
    internal_out = 0;
end

always @(posedge a or negedge a)
begin if ($time>2)
    case (state)
        0: begin
            state = 1;
        end
        2: begin
            state = 0;
        end
    endcase
end

always @(posedge b or negedge b)
begin if ($time>2)
    case (state)
        0: begin
            state = 2;
        end
        1: begin
            state = 0;
        end
    endcase
end

always @(posedge clk or negedge clk)
begin if ($time>2)
    case (state)
        1: begin
            internal_out = !internal_out;
            state = 0;
        end
        2: begin
            internal_out = !internal_out;
            state = 0;
        end
    endcase
end

endmodule
