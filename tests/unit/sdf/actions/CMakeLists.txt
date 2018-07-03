set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_sdf PRIVATE
  ${DIR}/base.cpp
  ${DIR}/time_scale.cpp
  ${DIR}/delayfile.cpp
  )
