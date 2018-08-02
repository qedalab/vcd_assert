set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

# configure_file(${CMAKE_SOURCE_DIR}/examples  ${CMAKE_BINARY_DIR}/examples COPYONLY)
file(COPY ${CMAKE_SOURCE_DIR}/examples DESTINATION ${CMAKE_BINARY_DIR})

add_custom_target(
  iverilog_examples
  ALL
  COMMAND ./run_iverilog_all.sh
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/
)

# #Basic and fail
# add_test(
#   NAME basic_and_fail
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_and_fail/iverilog_out/
#   COMMAND vcd_assert tb_basic_and.vcd --node tb_basic_and --sdf ../and.sdf
# )

# # Basic and succeed
# add_test(
#   NAME basic_and_success
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_and_success/iverilog_out/
#   COMMAND vcd_assert tb_basic_and.vcd --node tb_basic_and --sdf ../and.sdf
# )

############## NO TIMING CHEKCS + NO VERILOG
# Basic jtl
add_test(
  NAME basic_jtl
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_jtl/iverilog_out/
  COMMAND vcd_assert tb_basic_jtl.vcd --node tb_basic_jtl --sdf ../jtl.sdf
)
# Basic splitter
add_test(
  NAME basic_splitter
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_splitter/iverilog_out/
  COMMAND vcd_assert tb_basic_splitter.vcd --node tb_basic_splitter --sdf ../splitter.sdf
)

############## EXTERNALLY SUPPLIED SDF WITH CELLINSTANCE <path>
# Basic dro fail
add_test(
  NAME basic_dro_fail
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_dro_fail/iverilog_out/
  COMMAND vcd_assert tb_basic_dro.vcd --node tb_basic_dro --sdf ../dro.sdf
)

# Basic dro succeed
add_test(
  NAME basic_dro_success
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_dro_success/iverilog_out/
  COMMAND vcd_assert tb_basic_dro.vcd --node tb_basic_dro --sdf ../dro.sdf
)

############## EXTERNALLY SUPPLIED SDF WITH CELLINSTANCE <*>
# Basic xor fail
add_test(
  NAME basic_xor_fail
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_xor_fail/iverilog_out/
  COMMAND vcd_assert tb_basic_xor.vcd --node tb_basic_xor --sdf ../xor.sdf
)

# Basic xor succeed
add_test(
  NAME basic_xor_success
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_xor_success/iverilog_out/
  COMMAND vcd_assert tb_basic_xor.vcd --node tb_basic_xor --sdf ../xor.sdf
)

############## VERILOG SDF WITH CELLINSTANCE <path>
# Basic and fail
add_test(
  NAME basic_and_fail
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_and_fail/iverilog_out/
  COMMAND vcd_assert tb_basic_and.vcd ../tb_and.v ../and.v -t tb_basic_and 
)

# Basic and succeed
add_test(
  NAME basic_and_success
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_and_success/iverilog_out/
  COMMAND vcd_assert tb_basic_and.vcd ../tb_and.v ../and.v -t tb_basic_and 
)

############## VERILOG SDF WITH CELLINSTANCE <*>
# Basic ndro fail
add_test(
  NAME basic_ndro_fail
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_ndro_fail/iverilog_out/
  COMMAND vcd_assert tb_basic_ndro.vcd ../tb_ndro.v ../ndro.v -t tb_basic_ndro
)

# Basic ndro succeed
add_test(
  NAME basic_ndro_success
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_ndro_success/iverilog_out/
  COMMAND vcd_assert tb_basic_ndro.vcd ../tb_ndro.v ../ndro.v -t tb_basic_ndro 
)

############## COMPLEX EXAMPLE (SMALL) 
# Full adder 1bit fail
# add_test(
#   NAME full_adder_1bit_fail
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/full_adder_1bit_fail/iverilog_out/
#   COMMAND vcd_assert tb_full_adder_1bit.vcd ../tb_full_adder_1bit.v ../full_adder_1bit.v  ../../examples_cell_library.v -t tb_full_adder_1bit
# )

# Full adder 1bit succeed
add_test(
  NAME full_adder_1bit
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/full_adder_1bit_success/iverilog_out/
  COMMAND vcd_assert tb_full_adder_1bit.vcd ../tb_full_adder_1bit.v ../full_adder_1bit.v ../../examples_cell_library.v -t tb_full_adder_1bit
)

# Failing tests
set_tests_properties(
  basic_dro_fail
  # basic_xor_fail # case cant be supported without verilog.
  basic_and_fail
  basic_ndro_fail
  PROPERTIES WILL_FAIL TRUE
)

add_subdirectory(unit)
add_subdirectory(bench)
