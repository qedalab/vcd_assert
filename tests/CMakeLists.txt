set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

############## NO TIMING CHEKCS + NO VERILOG
example_as_test(
  NAME basic_jtl
  SCRIPT run_iverilog.sh
  DIR examples/basic_jtl
  VCD tb_basic_jtl.vcd
  SDF jtl.sdf
  VERILOG tb_jtl.v jtl.v
  ARGS --node tb_basic_jtl --sdf ../jtl.sdf
)

example_as_test(
  NAME basic_splitter
  SCRIPT run_iverilog.sh
  DIR examples/basic_splitter
  VCD tb_basic_splitter.vcd
  SDF splitter.sdf
  VERILOG tb_splitter.v splitter.v
  ARGS --node tb_basic_splitter --sdf ../splitter.sdf
)

############## EXTERNALLY SUPPLIED SDF WITH CELLINSTANCE <path>
# Basic dro fail
example_as_test(
  NAME basic_dro_fail
  SCRIPT run_iverilog.sh
  DIR examples/basic_dro_fail
  VCD tb_basic_dro.vcd
  SDF dro.sdf
  VERILOG dro.v tb_dro.v
  ARGS --node tb_basic_dro --sdf ../dro.sdf
)

# Basic dro succeed
example_as_test(
  NAME basic_dro_success
  SCRIPT run_iverilog.sh
  DIR examples/basic_dro_success
  VCD tb_basic_dro.vcd
  SDF dro.sdf
  VERILOG dro.v tb_dro.v
  ARGS -node tb_basic_dro --sdf ../dro.sdf
)

############## EXTERNALLY SUPPLIED SDF WITH CELLINSTANCE <*>
# Basic xor fail
example_as_test(
  NAME basic_xor_fail
  SCRIPT run_iverilog.sh
  DIR examples/basic_xor_fail
  VCD tb_basic_xor.vcd
  SDF xor.sdf
  VERILOG tb_xor.v xor.v
  VERILOG_AS_ARGS
  ARGS -t tb_basic_xor --node tb_basic_xor --sdf ../xor.sdf
)

# Basic xor succeed
example_as_test(
  NAME basic_xor_success
  SCRIPT run_iverilog.sh
  DIR examples/basic_xor_success
  VCD tb_basic_xor.vcd
  SDF xor.sdf
  VERILOG tb_xor.v xor.v
  VERILOG_AS_ARGS
  ARGS -t tb_basic_xor --node tb_basic_xor --sdf ../xor.sdf
)

############## VERILOG SDF WITH CELLINSTANCE <path>
# Basic and fail
example_as_test(
  NAME basic_and_fail
  SCRIPT run_iverilog.sh
  DIR examples/basic_and_fail
  VCD tb_basic_and.vcd
  SDF and.sdf
  VERILOG tb_and.v and.v
  VERILOG_AS_ARGS
  ARGS -t tb_basic_and 
)

# Basic and success
example_as_test(
  NAME basic_and_success
  SCRIPT run_iverilog.sh
  DIR examples/basic_and_success
  VCD tb_basic_and.vcd
  SDF and.sdf
  VERILOG tb_and.v and.v
  VERILOG_AS_ARGS
  ARGS -t tb_basic_and
)

############## VERILOG SDF WITH CELLINSTANCE <*>

# Basic ndro fail
example_as_test(
  NAME basic_ndro_fail
  SCRIPT run_iverilog.sh
  DIR examples/basic_ndro_fail
  VCD tb_basic_ndro.vcd
  SDF ndro.sdf
  VERILOG ndro.v tb_ndro.v
  VERILOG_AS_ARGS
  ARGS -t tb_basic_ndro 
)

# Basic ndro success
example_as_test(
  NAME basic_ndro_success
  SCRIPT run_iverilog.sh
  DIR examples/basic_ndro_success
  VCD tb_basic_ndro.vcd
  SDF ndro.sdf
  VERILOG ndro.v tb_ndro.v
  VERILOG_AS_ARGS
  ARGS -t tb_basic_ndro
)

############## COMPLEX EXAMPLE (SMALL)

# One bit adder succeed
example_as_test(
  NAME one_bit_adder_success
  SCRIPT run_iverilog.sh
  DIR examples/one_bit_adder_success
  VCD tb_one_bit_adder.vcd
  SDF and.sdf dro.sdf or.sdf xor.sdf splitter.sdf
  VERILOG tb_one_bit_adder.v one_bit_adder.v and.v dro.v or.v splitter.v xor.v
  VERILOG_AS_ARGS
  ARGS -t tb_one_bit_adder --sdf ../and.sdf --sdf ../dro.sdf --sdf ../or.sdf --sdf ../splitter.sdf --sdf ../xor.sdf
)

example_as_test(
  NAME one_bit_adder_fail
  SCRIPT run_iverilog.sh
  DIR examples/one_bit_adder_fail
  VCD tb_one_bit_adder.vcd
  SDF and.sdf dro.sdf or.sdf xor.sdf splitter.sdf
  VERILOG tb_one_bit_adder.v one_bit_adder.v and.v dro.v or.v splitter.v xor.v
  VERILOG_AS_ARGS
  ARGS -t tb_one_bit_adder --sdf ../and.sdf --sdf ../dro.sdf --sdf ../or.sdf --sdf ../splitter.sdf --sdf ../xor.sdf
)

# Failing tests
set_tests_properties(
  basic_dro_fail
  basic_xor_fail
  basic_and_fail
  basic_ndro_fail
  one_bit_adder_fail
  PROPERTIES WILL_FAIL TRUE
)

add_subdirectory(unit)
add_subdirectory(bench)
