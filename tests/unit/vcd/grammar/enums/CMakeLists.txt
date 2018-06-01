set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_vcd PRIVATE
  ${DIR}/scope_type.cpp
  ${DIR}/time.cpp
  ${DIR}/value.cpp
  ${DIR}/var_type.cpp
  )
