set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_vcd_assert ../unit_main.cpp)
target_link_libraries(unit_vcd_assert libvcd_assert Catch2::Catch2)
target_add_warnings(unit_vcd_assert)
add_test(NAME unit_vcd_assert COMMAND unit_vcd_assert)

target_sources(unit_vcd_assert PRIVATE
  ${DIR}/conditional.cpp
  ${DIR}/edge_type.cpp
  ${DIR}/event.cpp
  ${DIR}/state.cpp
  ${DIR}/timing_checker.cpp
  ${DIR}/triggered_timing_checker.cpp
  )
