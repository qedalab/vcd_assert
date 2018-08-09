#!/bin/sh

mkdir -p iverilog_out
cd iverilog_out
iverilog -Dbegin_time=20 -gspecify -s tb_one_bit_adder -o run ../*.v
vvp ./run
