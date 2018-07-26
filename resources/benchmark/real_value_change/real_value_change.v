module real_value_change;

`define num_events 1000000
real clock = 0;

initial begin
  $dumpfile("real_value_change.vcd");
  $dumpvars(1, clock);

  #`num_events $finish();
end

always begin
 #1 clock = clock + 1;
end

endmodule
