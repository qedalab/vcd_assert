// ---------------------------------------------------------------------------
// Automatically extracted verilog file, created with TimEx v1.01.00
// Timing description and structural design for IARPA-BAA-14-03.
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// (c) 2016-2017 Stellenbosch University
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module mitll_splitter (in, out1, out2);

input
  in;

output
  out1, out2;

reg
  out1, out2;

parameter
   delay_state0_in_out1 = 5.0,
   delay_state0_in_out2 = 5.0;

reg
   errorsignal_;

integer
   outfile,
   cell_state; // internal state of the cell

initial
   begin
      errorsignal_in = 0;
      cell_state = 0; // Startup state
      out1 = 0; // All outputs start at 0
      out2 = 0; // All outputs start at 0
   end

always @(posedge in or negedge in) // execute at positive and negative edges of input
   begin
      if ($time>4) // arbitrary steady-state time)
         begin
            if (errorsignal_in == 1'b1)  // A critical timing is active for this input
               begin
                  outfile = $fopen("errors.txt", "a");
                  $fdisplay(outfile, "Violation of critical timing in module %m; %0d ps.\n", $stime);
                  $fclose(outfile);
                  out1 <= 1'bX;  // Set all outputs to unknown
                  out2 <= 1'bX;  // Set all outputs to unknown
               end
            if (errorsignal_in == 0)
               begin
                  case (cell_state)
                     0: begin
                           out1 <= #(delay_state0_in_out1) !out1;
                           out2 <= #(delay_state0_in_out2) !out2;
                        end
                  endcase
               end
         end
   end

endmodule
