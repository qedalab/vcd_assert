set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libvcd PRIVATE
  ${DIR}/header_reader.cpp
  ${DIR}/header.cpp
  ${DIR}/scope.cpp
  ${DIR}/var_id_code.cpp
  ${DIR}/variable.cpp
  )