set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(grammar)
add_subdirectory(rc)

add_executable(unit_sdf
  ${UNIT_GRAMMER_SRC}
  ${UNIT_RC_SRC}
  ../unit_main.cpp
)

target_link_libraries(unit_sdf parse)
