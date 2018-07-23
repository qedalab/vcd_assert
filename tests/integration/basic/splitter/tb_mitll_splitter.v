// ---------------------------------------------------------------------------
// Verilog testbench file, created with TimEx v1.00.02
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module tb_mitll_splitter;
   reg in = 0;
   initial
      begin
         $dumpfile("tb_mitll_splitter.vcd");
         $dumpvars;
         // Now in state 0
         #20 in = !in;
         // Now in state 0
      end

   initial
      begin
         $display("\t\ttime,\tin,\tout1,\tout2");
         $monitor("%d,\t%b,\t%b,\t%b",$time,in,out1,out2);
      end

   mitll_splitter DUT (in, out1, out2);

   initial
      #30 $finish;
endmodule
