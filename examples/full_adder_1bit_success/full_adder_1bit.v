`timescale 1ps/100fs
module full_adder_1bit (cin, a, b, clk, sum, cout);

  input cin, a, b, clk;

  output sum, cout;
  wire sum, cout;

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
  splitter_8bit clk_splitter (.in(clk), .out(clk_internal));

  // Basic adder
  basic_dro dff_1 (cin, clk_internal[0], internal_1);
  basic_dro dff_2 (internal_3, clk_internal[6], sum);
  basic_dro dff_3 (internal_12, clk_internal[5], internal_13);
  basic_splitter splitter_1 (internal_1, internal_2, internal_4);
  basic_splitter splitter_2 (a, internal_8, internal_10);
  basic_splitter splitter_3 (b, internal_9, internal_11);
  basic_splitter splitter_4 (internal_7, internal_5, internal_6);
  basic_xor xor_1 (internal_2, internal_5, clk_internal[1], internal_3);
  basic_xor xor_2 (internal_8, internal_9, clk_internal[2], internal_7);
  basic_and and_1 (internal_10, internal_11, clk_internal[4], internal_12);
  basic_and and_2 (internal_4, internal_6, clk_internal[3], internal_14);
  // basic_or or_1 (internal_13, internal_14, clk_internal[7], cout);
endmodule

