`timescale 1ps/100fs
module tb_basic_dro;
    reg set = 0;
    reg reset = 0;

    initial begin
        $sdf_annotate("../dro.sdf", tb_basic_dro);
        $dumpfile("tb_basic_dro.vcd");
        $dumpvars;

        #10 set = !set;
        #10 set = !set;
        #10 reset = !reset;
        #10 reset = !reset;
    end

    initial begin
        $display("\t\ttime,\tset,\treset,\tout");
        $monitor("\t\t%0t,\t%b,\t%b,\t%b",$realtime,set,reset,out);
    end

    basic_dro DUT (set, reset, out);

    initial #50 $finish;
endmodule
