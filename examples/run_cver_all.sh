#!/bin/sh

cd ./basic_and_fail/; sh ./run_cver.sh; cd ..
cd ./basic_and_success/; sh ./run_cver.sh; cd ..
cd ./basic_dro_success/; sh ./run_cver.sh; cd ..
cd ./basic_dro_fail/; sh ./run_cver.sh; cd ..
cd ./basic_jtl/; sh ./run_cver.sh; cd ..
cd ./basic_ndro_success/; sh ./run_cver.sh; cd ..
cd ./basic_ndro_fail/; sh ./run_cver.sh; cd ..
cd ./basic_splitter/; sh ./run_cver.sh; cd ..
cd ./basic_xor_fail/; sh ./run_cver.sh; cd ..
cd ./basic_xor_success/; sh ./run_cver.sh; cd ..
cd ./one_bit_adder_success/; sh ./run_cver.sh; cd ..
cd ./one_bit_adder_fail_success/; sh ./run_cver.sh; cd ..
cd ./full_adder_1bit_success; sh ./run_cver.sh; cd ..
cd ./full_adder_1bit_fail; sh ./run_cver.sh; cd ..
