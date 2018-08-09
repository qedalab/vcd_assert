`ifndef and_based_decoder_
`define and_based_decoder_

`timescale 1ps/1ps

module0 tb_decoder_2dr4sr_and
  #(parameter
    SIZE = 2,
    t_test = 3 
    )();
reg [(SIZE)-1:0]                in_data;
reg [(SIZE)-1:0]                in_negative;
wire reg [(2**SIZE)-1:0]        out_data;
// wire reg [(2**SIZE)-1:0]       out_clk;
wire reg                        out_clk;

decoder_dualrail_adp2 #(SIZE,t_hold,t_out,t_setup,pulse_width,warning_file,tuning_delay,t_read,min_input_delay,0,splitter_delay) UT(
  .in_data(in_data),
  .in_not(in_negative),
  .out_data(out_data),
  .out_clk(out_clk)
  );


initial begin
  $dumpfile($sformatf("tb_decoder_4bit.vcd"));
  $dumpvars;
  // $monitor("a_in=%b,b_in=%b,sel_in=%b,sel_state=%b,output=%b", a_in , b_in,sel_in,sel_state,out);
  in_data[0] <= 0;
  in_data[1] <= 0;
  in_negative = 0;
  #(runtime)
  $finish;
end

initial begin
  #6
  in_negative[0] = 1;
  in_negative[1] = 1;
  in_negative = #(pulse_width) 0;
  #(period)

  in_data[0] = 1;
  in_data[0] <= #(pulse_width) 0;

  in_negative[1] = 1;
  in_negative[1] <= #(pulse_width) 0;
  #(period)

  in_data[1] = 1;
  in_data[1] <= #(pulse_width)0;

  in_negative[0] = 1;
  in_negative[0] <= #(pulse_width) 0;
  #(period)

  in_data[0] = 1;
  in_data[0] <= #(pulse_width) 0;
  in_data[1] = 1;
  in_data[1] <= #(pulse_width)  0;
  // #(period)
  //
  // in_data[0] = 1;
  // in_data[0] <= #(pulse_width) 0;
  // in_data[1]  = 1;
  // in_data[1] <= #(pulse_width) 0;

end
endmodule

`endif // and_based_decoder_
