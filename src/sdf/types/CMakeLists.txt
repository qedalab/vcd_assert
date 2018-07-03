set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libsdf PRIVATE
  ${DIR}/delayfile.cpp
  ${DIR}/delayfile_reader.cpp
  )