set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

# set(UNIT_TYPES_SRC
#   ${DIR}/delayfile.cpp
#   PARENT_SCOPE
# )

target_sources(libsdf PRIVATE
  ${DIR}/delayfile.cpp
)