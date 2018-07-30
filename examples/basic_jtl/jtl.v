// Adapted from TimEx generated files for vcd_assert testing
`timescale 1ps/100fs
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
begin if($time>2)
    internal_out = !internal_out;
end

endmodule
