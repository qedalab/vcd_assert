// Adapted from TimEx generated files for vcd_assert testing
`timescale 1ps/100fs
module basic_jtl (in, out);

// Define inputs
input in;

// Define outputs
output out;
reg out;

// Single state

specify
    // Output delays spec params
    specparam delay_state0_in_out = 3.2;

    // No critical timings spec params

    // Define output delays
    (in => out) = delay_state0_in_out;

    // No critical timing assertions

endspecify

initial begin
    // No state
    out = 0; // All outputs start at 0
end

always @(posedge in or negedge in)
begin if($time>2)
    out = !out;
end

endmodule
