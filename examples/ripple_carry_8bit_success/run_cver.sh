#!/bin/sh

mkdir -p cver_out
cd cver_out
cver +maxerrors 0 +define+begin_time=20 +sdf_annotate ../dro.sdf +sdf_annotate ../and.sdf +sdf_annotate ../or.sdf +sdf_annotate ../xor.sdf ../tb_one_bit_adder.v -v ../dro.v -v ../and.v -v ../or.v -v ../xor.v -v ../one_bit_adder.v -v ../splitter.v -l out.txt
