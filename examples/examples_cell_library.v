// Adapted from TimEx generated files for vcd_assert
`ifndef examples_cell_library_
`define examples_cell_library_

`ifndef begin_time
`define begin_time 8
`endif

`timescale 1ps/100fs

`celldefine
module basic_and (a, b, clk, out);

    // Define inputs
    input a, b, clk;

    // Define outputs
    output out;
    wire out;

    // Internal output variables
    reg internal_out = 0;
    assign out = internal_out;

    // Define state
    integer state;

    // Internal state variables
    wire internal_state_0,
        internal_state_1,
        internal_state_2,
        internal_state_3;

    assign internal_state_0 = state === 0;
    assign internal_state_1 = state === 1;
    assign internal_state_2 = state === 2;
    assign internal_state_3 = state === 3;

    specify
        // Output delays
        specparam delay_state3_clk_out = 5.5;

        // Critical timing spec params
        specparam ct_state0_clk_a = 2.5;
        specparam ct_state0_clk_b = 2.5;
        specparam ct_state1_a_b = 2.5;
        specparam ct_state1_a_clk = 2.5;
        specparam ct_state1_clk_b = 2.5;
        specparam ct_state2_b_a = 2.5;
        specparam ct_state2_b_clk = 2.5;
        specparam ct_state2_clk_a = 2.5;
        specparam ct_state3_clk_a = 2.5;
        specparam ct_state3_clk_b = 2.5;

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
        state = 1'bX;
        internal_out = 0;
        #`begin_time state = 0;
    end

    always @(posedge a or negedge a)
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
            internal_out = 1'bX;
        end
    endcase

    always @(posedge b or negedge b)
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
            internal_out = 1'bX;
        end
    endcase

    always @(posedge clk or negedge clk)
    case (state)
        1: begin
            state = 0;
        end
        2: begin
            state = 0;
        end
        3: begin
            internal_out = !internal_out;
            state = 0;
        end
    endcase

endmodule
`endcelldefine


//////////////////////////////////////////////////////////////////////
`celldefine
module basic_dro (set, reset, out);

    // Define inputs
    input set, reset;

    // Define outputs
    output out;
    wire out;

    // Internal output variables
    reg internal_out;
    assign out = internal_out;

    // State
    integer state;

    // Internal state variables
    wire internal_state_0,
        internal_state_1;

    assign internal_state_0 = state === 0;
    assign internal_state_1 = state === 1;

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
            internal_out = !internal_out;
            state = 0;
        end
    endcase

endmodule
`endcelldefine

//////////////////////////////////////////////////////////////////////
`celldefine
module basic_jtl (in, out);

    // Define inputs
    input in;

    // Define outputs
    output out;
    wire out;

    // Define internal output variables
    reg internal_out;
    assign out = internal_out;

    // Single state

    specify
        // Output delays spec params
        specparam delay_state0_in_out = 3.5;

        // No critical timings spec params

        // Define output delays
        (in => out) = delay_state0_in_out;

        // No critical timing assertions

    endspecify

    initial begin
        // No state
        internal_out = 0; // All outputs start at 0
    end

    always @(posedge in or negedge in)
    begin
        internal_out = !internal_out;
    end

endmodule
`endcelldefine

//////////////////////////////////////////////////////////////////////
`celldefine
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
`endcelldefine
    

//////////////////////////////////////////////////////////////////////
`celldefine
module basic_or (a, b, clk, out);

    // Define inputs
    input a, b, clk;

    // Define outputs
    output out;
    wire out;

    // Internal output variables
    reg internal_out;
    assign out = internal_out;

    // Define state
    integer state = 1'bX;

    // Internal state variables
    wire internal_state_0,
        internal_state_1,
        internal_state_2,
        internal_state_3;

    assign internal_state_0 = state === 0;
    assign internal_state_1 = state === 1;
    assign internal_state_2 = state === 2;
    assign internal_state_3 = state === 3;

    specify
        // Output delays
        specparam delay_state3_clk_out = 5.5;

        // Critical timing spec params
        specparam ct_state0_clk_a = 2.5;
        specparam ct_state0_clk_b = 2.5;
        specparam ct_state1_a_b = 2.5;
        specparam ct_state1_a_clk = 2.5;
        specparam ct_state1_clk_b = 2.5;
        specparam ct_state2_b_a = 2.5;
        specparam ct_state2_b_clk = 2.5;
        specparam ct_state2_clk_a = 2.5;
        specparam ct_state3_clk_a = 2.5;
        specparam ct_state3_clk_b = 2.5;

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
        state = 1'bX;
        internal_out = 0;
        #`begin_time state = 0;
    end

    always @(posedge a or negedge a)
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
            internal_out = 1'bX;
        end
    endcase

    always @(posedge b or negedge b)
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
            internal_out = 1'bX;
        end
    endcase

    always @(posedge clk or negedge clk)
    case (state)
        1: begin
            internal_out = !internal_out;
            state = 0;
        end
        2: begin
            internal_out = !internal_out;
            state = 0;
        end
        3: begin
            internal_out = !internal_out;
            state = 0;
        end
    endcase

endmodule
`endcelldefine

//////////////////////////////////////////////////////////////////////
`celldefine
module basic_splitter (in, out1, out2);

    // Define inputs
    input in;

    // Define outputs
    output out1, out2;
    wire out1, out2;

    // Define internal output variables
    reg internal_out1, internal_out2;
    assign out1 = internal_out1;
    assign out2 = internal_out2;

    // Single state

    specify
        // Output delays spec params
        specparam delay_state0_in_out1 = 5.0;
        specparam delay_state0_in_out2 = 5.0;

        // No critical timing spec params

        // Define output delays
        (in => out1) = delay_state0_in_out1;
        (in => out2) = delay_state0_in_out2;

        // No critical timings assertions

    endspecify

    initial begin
        // No state
        internal_out1 = 0;
        internal_out2 = 0;
    end

    always @(posedge in or negedge in)
    begin
        internal_out1 = !internal_out1;
        internal_out2 = !internal_out2;
    end

endmodule
`endcelldefine

//////////////////////////////////////////////////////////////////////
`celldefine
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

    assign internal_state_0 = state === 0;
    assign internal_state_1 = state === 1;
    assign internal_state_2 = state === 2;

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
        state = 1'bX;
        internal_out = 0;
        #`begin_time state = 0;
    end

    always @(posedge a or negedge a)
    case (state)
        0: begin
            state = 1;
        end
        2: begin
            state = 0;
        end
    endcase

    always @(posedge b or negedge b)
    case (state)
        0: begin
            state = 2;
        end
        1: begin
            state = 0;
        end
    endcase

    always @(posedge clk or negedge clk)
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

endmodule
`endcelldefine

`endif // examples_cell_library_
