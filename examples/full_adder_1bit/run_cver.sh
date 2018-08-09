#!/bin/sh

mkdir -p cver_out
cd cver_out
cver +maxerrors 0 +define+begin_time=20             \
  +sdf_annotate ../../examples_cell_library_typ.sdf \
  ../tb_full_adder_1bit_success.v                   \
  -v ../full_adder_1bit.v                           \
  -v ../../examples_cell_library.v                  \
  -v ../../splitter_8bit/*.v                        \
  -l out.txt
