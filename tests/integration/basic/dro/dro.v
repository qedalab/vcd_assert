// ---------------------------------------------------------------------------
// Automatically extracted verilog file, created with TimEx v1.01.00
// Timing description and structural design for IARPA-BAA-14-03.
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// (c) 2016-2017 Stellenbosch University
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module dro (set, reset, out);

input set, reset;
output out;

reg out;

reg state;

specify
    specparam delay_state1_reset_out = 5.5;
    specparam ct_state0_set_reset    = 2.5;
    specparam ct_state0_reset_set    = 2.5;
    specparam ct_state1_set_reset    = 2.5;

    if (state == 1) (reset => out) = delay_state1_reset_out;
   
    $hold( posedge set &&& ~state , reset  , ct_state0_set_reset);
    $hold( negedge set &&& ~state , reset  , ct_state0_set_reset);

    $hold( posedge set &&& state , reset , ct_state1_set_reset);
    $hold( negedge set &&& state , reset , ct_state1_set_reset);

    $hold( posedge reset &&& ~state , set , ct_state0_reset_set);
    $hold( negedge reset &&& ~state , set , ct_state0_reset_set);

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
