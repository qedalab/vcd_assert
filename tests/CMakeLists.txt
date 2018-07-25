set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(DRO_SOURCE ${DIR}/integration/basic/dro/dro.v ${DIR}/integration/basic/dro/tb_dro.v)
create_vcd_from_verilog(basic_dro tb_dro "${DRO_SOURCE}")

add_custom_target(
  vcd_integration_examples
  ALL
  DEPENDS
    ${CMAKE_BINARY_DIR}/vcd/basic_dro/output.vcd
)

add_test(NAME integration_dro COMMAND vcd_assert ${CMAKE_BINARY_DIR}/vcd/basic_dro/output.vcd)

add_subdirectory(unit)
add_subdirectory(bench)
