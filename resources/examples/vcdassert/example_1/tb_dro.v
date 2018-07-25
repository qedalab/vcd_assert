// ---------------------------------------------------------------------------
// Verilog testbench file, created with TimEx v1.00.02
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// ---------------------------------------------------------------------------
include <dro.v>;
`timescale 1ps/100fs
module tb_dro;
   reg set = 0;
   reg reset = 0;

   initial
      begin
         $sdf_annotate("../../dro.sdf", tb_dro);
         $dumpfile("tb_dro_example_1.vcd");
         $dumpvars;

         #10 set = !set;
         #10 set = !set;
         #2.4 reset = !reset; //should cause timing violation
         #10 reset = !reset;
      end

   initial
      begin
         $display("\t\ttime,\tset,\treset,\tout");
         $monitor("\t\t%0t,\t%b,\t%b,\t%b",$realtime,set,reset,out);
      end

   dro DUT (set, reset, out);

   initial
      #50 $finish;
endmodule
