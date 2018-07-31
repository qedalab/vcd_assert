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


# Basic dro fail
add_test(
  NAME basic_dro_fail
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_dro_fail/iverilog_out/
  COMMAND vcd_assert tb_basic_dro.vcd --node tb_basic_dro --sdf ../dro.sdf
)

# # Basic dro succeed
# add_test(
#   NAME basic_dro_success
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_dro_success/iverilog_out/
#   COMMAND vcd_assert tb_basic_dro.vcd --node tb_basic_dro --sdf ../dro.sdf
# )

# # Basic and fail
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

# # Basic jtl fail
# add_test(
#   NAME basic_jtl_fail
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_jtl_fail/iverilog_out/
#   COMMAND vcd_assert tb_basic_jtl.vcd --node tb_basic_jtl --sdf ../jtl.sdf
# )

# # Basic jtl succeed
# add_test(
#   NAME basic_jtl_success
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_jtl_success/iverilog_out/
#   COMMAND vcd_assert tb_basic_jtl.vcd --node tb_basic_jtl --sdf ../jtl.sdf
# )

# # Basic ndro fail
# add_test(
#   NAME basic_ndro_fail
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_ndro_fail/iverilog_out/
#   COMMAND vcd_assert tb_basic_ndro.vcd --node tb_basic_ndro --sdf ../ndro.sdf
# )

# # Basic ndro succeed
# add_test(
#   NAME basic_ndro_success
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_ndro_success/iverilog_out/
#   COMMAND vcd_assert tb_basic_ndro.vcd --node tb_basic_ndro --sdf ../ndro.sdf
# )

# # Basic splitter fail
# add_test(
#   NAME basic_splitter_fail
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_splitter_fail/iverilog_out/
#   COMMAND vcd_assert tb_basic_splitter.vcd --node tb_basic_splitter --sdf ../splitter.sdf
# )

# # Basic splitter succeed
# add_test(
#   NAME basic_splitter_success
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_splitter_success/iverilog_out/
#   COMMAND vcd_assert tb_basic_splitter.vcd --node tb_basic_splitter --sdf ../splitter.sdf
# )

# # Basic xor fail
# add_test(
#   NAME basic_xor_fail
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_xor_fail/iverilog_out/
#   COMMAND vcd_assert tb_basic_xor.vcd --node tb_basic_xor --sdf ../xor.sdf
# )

# # Basic xor succeed
# add_test(
#   NAME basic_xor_success
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_xor_success/iverilog_out/
#   COMMAND vcd_assert tb_basic_xor.vcd --node tb_basic_xor --sdf ../xor.sdf
# )


# Failing tests
set_tests_properties(
  basic_dro_fail
  # basic_and_fail
  # basic_jtl_fail
  # basic_ndro_fail
  # basic_splitter_fail
  # basic_xor_fail
  PROPERTIES WILL_FAIL TRUE
)

add_subdirectory(unit)
add_subdirectory(bench)
