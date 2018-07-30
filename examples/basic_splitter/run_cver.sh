#!/bin/sh

mkdir -p cver_out
cd cver_out
cver +maxerrors 0 +sdf_annotate ../*.sdf ../tb_splitter.v -v ../splitter.v -l out.txt
