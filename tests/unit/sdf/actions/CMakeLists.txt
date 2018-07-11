set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_sdf PRIVATE
  ${DIR}/base.cpp
  ${DIR}/time_scale.cpp
  ${DIR}/timing_check.cpp
  ${DIR}/timing.cpp
  ${DIR}/values.cpp
  # ${DIR}/delayfile.cpp
  )
