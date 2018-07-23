set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_vcd PRIVATE
  ${DIR}/header.cpp
  ${DIR}/identifier_code.cpp
  ${DIR}/scope.cpp
  ${DIR}/time_scale.cpp
  ${DIR}/value_change.cpp
  ${DIR}/var.cpp
  )
