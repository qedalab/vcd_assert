set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libparse PRIVATE
  ${DIR}/file.cpp
  ${DIR}/cstring.cpp
  ${DIR}/memory.cpp
  )