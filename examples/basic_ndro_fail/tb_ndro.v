// Adapted from timEx generated files for vcd_assert testing
`timescale 1ps/100fs
module tb_basic_ndro;
  reg set = 0;
  reg reset = 0;
  reg clk = 0;

  initial begin
      `ifndef IVERILOG_WORKAROUND
      $sdf_annotate("../ndro.sdf", tb_basic_ndro);
      `endif
      $dumpfile("tb_basic_ndro.vcd");
      $dumpvars;

      #20 set = !set;
      #10 set = !set;
      #10 reset = !reset;
      #10 reset = !reset;
      #10 set = !set;
      #10 clk = !clk;
      #2 reset = !reset; // timing violation
      #10 $finish;
  end

  initial begin
      $display("\t\ttime,\tset,\treset,\tclk,\tout");
      $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,set,reset,clk,out);
  end

  basic_ndro DUT (set, reset, clk, out);
endmodule
