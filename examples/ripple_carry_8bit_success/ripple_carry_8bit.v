`timescale 1ps/100fs
module ripple_carry_8bit #(begin_time,t) (cin, a, b, clk, sum, cout);

  input cin, 
        [7:0] a, 
        [7:0] b, 
        clk;

  output sum, 
         cout;
  // wire sum, cout;

  wire [7:0] clk_internal;
  
  wire internal_1,
       internal_2,
       internal_3,
       internal_4,
       internal_5,
       internal_6,
       internal_7,
       internal_8,
       internal_9,
       internal_10,
       internal_11,
       internal_12,
       internal_13,
       internal_14;

  // Start of clock tree: level 0
  splitter_8bit #(begin_time,t) clk_splitter (.in(clk), .out(clk_internal));

  assign cin= net[0]; 

  tb_full_adder_1bit #(begin_time,t) add_0 (net[0],clk_internal[0],a[0],sum[0],net[1]);
  tb_full_adder_1bit #(begin_time,t) add_1 (net[1],clk_internal[1],a[1],sum[1],net[2]);
  tb_full_adder_1bit #(begin_time,t) add_2 (net[2],clk_internal[2],a[2],sum[2],net[3]);
  tb_full_adder_1bit #(begin_time,t) add_3 (net[3],clk_internal[3],a[3],sum[3],net[4]);
  tb_full_adder_1bit #(begin_time,t) add_4 (net[4],clk_internal[4],a[4],sum[4],net[5]);
  tb_full_adder_1bit #(begin_time,t) add_5 (net[5],clk_internal[5],a[5],sum[5],net[6]);
  tb_full_adder_1bit #(begin_time,t) add_6 (net[6],clk_internal[6],a[6],sum[6],net[7]);
  tb_full_adder_1bit #(begin_time,t) add_7 (net[7],clk_internal[7],a[7],sum[7],net[8]);

  assign cout = net[8];

endmodule

