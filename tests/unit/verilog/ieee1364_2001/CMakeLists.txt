# add_subdirectory(actions)
add_subdirectory(grammar)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_verilog PRIVATE
  ${DIR}/design.cpp
)
