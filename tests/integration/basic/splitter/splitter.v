// Adapted from TimEx generated files for vcd_assert testing
`timescale 1ps/100fs
module basic_splitter (in, out1, out2);

// Define inputs
input in;

// Define outputs
output out1, out2;
reg out1, out2;

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
    out1 = 0;
    out2 = 0;
end

always @(posedge in or negedge in)
begin if ($time>2)
    out1 = !out1;
    out2 = !out2;
end

endmodule
