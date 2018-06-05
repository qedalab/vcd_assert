set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/file.cpp
  ${DIR}/cstring.cpp
  ${DIR}/memory.cpp
  )
