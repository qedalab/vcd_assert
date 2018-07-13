set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_sdf PRIVATE
  # ${DIR}/base.cpp
  ${DIR}/cell.cpp
  ${DIR}/timing.cpp
  ${DIR}/values.cpp
  ${DIR}/timing_check.cpp
  ${DIR}/timing_spec.cpp
  ${DIR}/delayfile.cpp
  ${DIR}/delayfile_reader.cpp
)