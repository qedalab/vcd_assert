set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_vcd PRIVATE
  ${DIR}/scope.cpp
  ${DIR}/var.cpp
  ${DIR}/time_scale.cpp
  ${DIR}/header.cpp
  )
