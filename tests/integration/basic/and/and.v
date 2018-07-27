// Adapted from TimEx generated files for vcd_assert
`timescale 1ps/100fs
module basic_and (a, b, clk, out);

// Define inputs
input a, b, clk;

// Define outputs
output out;
reg out;

// Define state
integer state;

// Internal state variables
wire internal_state_0,
     internal_state_1,
     internal_state_2,
     internal_state_3;

assign internal_state_0 = state == 0;
assign internal_state_1 = state == 1;
assign internal_state_2 = state == 2;
assign internal_state_3 = state == 3;

specify
    // Output delays
    specparam delay_state3_clk_out = 5.5;

    // Critical timing spec params
    specparam ct_state0_clk_a = 2.5;
    specparam ct_state0_clk_b = 2.5;
    specparam ct_state1_a_b = 1;
    specparam ct_state1_a_clk = 7.0;
    specparam ct_state1_clk_b = 2.5;
    specparam ct_state2_b_a = 1;
    specparam ct_state2_b_clk = 7.0;
    specparam ct_state2_clk_a = 2.5;
    specparam ct_state3_clk_a = 0.5;
    specparam ct_state3_clk_b = 0.5;

    // Define output delays
    if (internal_state_3) (clk => out) = delay_state3_clk_out;

    // Define critical timings assertions
    $hold( posedge clk &&& internal_state_0, a, ct_state0_clk_a);
    $hold( negedge clk &&& internal_state_0, a, ct_state0_clk_a);

    $hold( posedge clk &&& internal_state_0, b, ct_state0_clk_b);
    $hold( negedge clk &&& internal_state_0, b, ct_state0_clk_b);

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

    $hold( posedge clk &&& internal_state_3, a, ct_state3_clk_a);
    $hold( negedge clk &&& internal_state_3, a, ct_state3_clk_a);

    $hold( posedge clk &&& internal_state_3, b, ct_state3_clk_b);
    $hold( negedge clk &&& internal_state_3, b, ct_state3_clk_b);

endspecify

initial begin
    state = 0;
    out = 0;
end

always @(posedge a or negedge a)
begin if ($time>2)
    case (state)
        0: begin
            state = 1;
        end
        2: begin
            state = 3;
        end
        3: begin
            // Input leads to invalid state
            state = 1'bX;
            out = 1'bX;
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
            state = 3;
        end
        3: begin
            // Input leads to invalid state
            state = 1'bX;
            out = 1'bX;
        end
    endcase
end

always @(posedge clk or negedge clk)
begin if ($time>2)
    case (state)
        3: begin
            out = !out;
            state = 0;
        end
    endcase
end

endmodule
