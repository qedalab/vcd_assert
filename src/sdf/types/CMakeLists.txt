set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libsdf PRIVATE
  ${DIR}/base.cpp
  ${DIR}/cell.cpp
  ${DIR}/delayfile.cpp
  ${DIR}/delayfile_reader.cpp
  ${DIR}/timing_check.cpp
  )