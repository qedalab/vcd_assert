set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libvcd_assert PRIVATE
  ${DIR}/basic_timing_checker.cpp
  ${DIR}/conditional.cpp
  ${DIR}/state.cpp
  ${DIR}/timing_checker.cpp
  )
