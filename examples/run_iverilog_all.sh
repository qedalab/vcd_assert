#!/bin/sh

# cd ./basic_and_fail/; ./run_iverilog.sh; cd ..
# cd ./basic_and_success/; ./run_iverilog.sh; cd ..
cd ./basic_dro_success/; ./run_iverilog.sh; cd ..
cd ./basic_dro_fail/; ./run_iverilog.sh; cd ..
cd ./basic_jtl/; ./run_iverilog.sh; cd ..
# cd ./basic_ndro_success/; ./run_iverilog.sh; cd ..
# cd ./basic_ndro_fail/; ./run_iverilog.sh; cd ..
cd ./basic_splitter/; ./run_iverilog.sh; cd ..
cd ./basic_xor_fail/; ./run_iverilog.sh; cd ..
cd ./basic_xor_success/; ./run_iverilog.sh; cd ..
