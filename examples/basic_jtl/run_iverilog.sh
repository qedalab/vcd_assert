#!/bin/sh

mkdir -p iverilog_out
cd iverilog_out
iverilog -gspecify -s tb_basic_jtl -o run ../tb_jtl.v ../jtl.v
vvp ./run
