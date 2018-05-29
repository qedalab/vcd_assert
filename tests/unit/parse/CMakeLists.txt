set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(control)
add_subdirectory(grammar)
add_subdirectory(input)
add_subdirectory(internal)
add_subdirectory(test)

add_executable(unit_parse
  ${UNIT_CONTROL_SRC}
  ${UNIT_GRAMMAR_SRC}
  ${UNIT_INPUT_SRC}
  ${UNIT_INTERNAL_SRC}
  ${UNIT_TEST_SRC}
  ../unit_main.cpp
)

target_link_libraries(unit_parse libvcd_assert)
