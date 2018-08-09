`ifndef decoder_2dr4sr_and_
`define decoder_2dr4sr_and_

`timescale 1ps/1ps
`include "../basic/basic_and_success/basic_and.v"

// AND based 2-bit dual rail input to 4 bit single rail output,  one hot decoder. 
module decoder_2dr4sr_and
  #(parameter
      warning_file = "", //set this to an actual file from top level tb.  
      SIZE = 2
    )(
      input [(SIZE)-1:0][1:0]     in,
      output [(2**SIZE)-1:0]      out,
      input                       clk
    );

basic_and and_hot_0(
  .in({in[0][1],in[1][1]}), //LSB_neg MSB_neg
  .clk(clk),
  .out(out[0])
);
basic_and and_hot_1(
  .in({in[0][0],in[1][1]}), //LSB_pos MSB_neg
  .clk(clk),
  .out(out[1])
);
basic_and and_hot_2(
  .in({in[0][1],in[1][0]}), //LSB_neg MSB_pos
  .clk(clk),
  .out(out[2])
);
basic_and and_hot_3(
  .in({in[0][0],in[1][0]}), //LSB_pos MSB_pos
  .clk(clk),
  .out(out[3])
);

endmodule // decoder_2dr4sr_and
`endif // decoder_2dr4sr_and_

