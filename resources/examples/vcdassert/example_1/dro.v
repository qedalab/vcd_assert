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
reg out_state;
integer state;

assign out = out_state;

specify
    specparam delay_state1_reset_out = 5.5;
    specparam ct_state0_set_reset    = 2.5;
    specparam ct_state0_reset_set    = 2.5;
    specparam ct_state1_set_reset    = 2.5;

    if (state ) (reset => out) = delay_state1_reset_out;
   
    $hold(reset, posedge set &&& (state == 0) , ct_state0_set_reset);
    $hold(reset, negedge set &&& (state == 0) , ct_state0_set_reset);

    $hold(reset, posedge set &&& (state == 1) , ct_state1_set_reset);
    $hold(reset, negedge set &&& (state == 1) , ct_state1_set_reset);

    $hold(set, posedge reset &&& (state == 0) , ct_state0_reset_set);
    $hold(set, negedge reset &&& (state == 0) , ct_state0_reset_set);

endspecify

initial begin
    state = 0;
    out_state = 0;
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
	    // Note output is before state change for output delay to kick in
        if (out == 0)
        begin
            out_state =  1;
        end
        else
            out_state = 0;
        end
    endcase
end

endmodule
