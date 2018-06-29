set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_vcd PRIVATE
  ${DIR}/comment.cpp
  ${DIR}/date.cpp
  ${DIR}/enums.cpp
  ${DIR}/scope.cpp
  ${DIR}/simulation_time.cpp
  ${DIR}/time_scale.cpp
  ${DIR}/value_change.cpp
  ${DIR}/variable.cpp
  ${DIR}/version.cpp
  )
