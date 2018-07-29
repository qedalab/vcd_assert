set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/array_append.cpp
  ${DIR}/bag.cpp
  ${DIR}/name_index_map.cpp
  ${DIR}/dependent_value.cpp
  ${DIR}/filesystem.cpp
  ${DIR}/name_index_map.cpp
  ${DIR}/static_string.cpp
  ${DIR}/tag.cpp
  )
