set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_vcd PRIVATE
  ${DIR}/enums.cpp
  ${DIR}/header.cpp
  ${DIR}/header_reader.cpp
  ${DIR}/scope.cpp
  ${DIR}/simulation_time.cpp
  ${DIR}/time_scale.cpp
  ${DIR}/var_id_code.cpp
  ${DIR}/variable.cpp
  )
