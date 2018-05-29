set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(grammar)
add_subdirectory(data)

add_executable(unit_vcd
  ${UNIT_GRAMMAR_SRC}
  ${UNIT_DATA_SRC}
  enums.cpp
  ../unit_main.cpp
)

target_link_libraries(unit_vcd libvcd_assert)
