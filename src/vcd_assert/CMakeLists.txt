set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libvcd_assert PRIVATE
  ${DIR}/basic_timing_checker.cpp
  ${DIR}/conditional.cpp
  ${DIR}/edge_type.cpp
  ${DIR}/event.cpp
  ${DIR}/state.cpp
  ${DIR}/timing_checker.cpp
  ${DIR}/triggered_timing_checker.cpp
  )

add_executable(vcd_assert
  ${DIR}/vcd_assert.cpp
)

target_add_warnings(vcd_assert)
target_link_libraries(vcd_assert
  libvcd_assert
  CLI11::CLI11
  fmt::fmt
)
