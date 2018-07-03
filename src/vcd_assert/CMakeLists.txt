set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libvcd_assert PRIVATE
  ${DIR}/timing_checker.cpp
  )
