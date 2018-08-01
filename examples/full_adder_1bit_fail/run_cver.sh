#!/bin/sh

mkdir -p cver_out
cd cver_out
cver +maxerrors 0 \
  +define+begin_time=20 \
  +sdf_annotate ../or.sdf  \
  +sdf_annotate ../dro.sdf \
  +sdf_annotate ../and.sdf \
  +sdf_annotate ../xor.sdf \
  ../tb_full_adder_1bit.v  \
  -v ../full_adder_1bit.v  \
  -v ../or.v              \
  -v ../dro.v            \
  -v ../and.v            \
  -v ../xor.v            \
  -v ../splitter.v          \
  -v ../../splitter_8bit/splitter_8bit.v          \
  -l out.txt               
