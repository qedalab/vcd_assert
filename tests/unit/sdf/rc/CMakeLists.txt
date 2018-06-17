set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

# set(UNIT_RC_SRC
#   ${DIR}/sdf_example_1_sdf.raw
#   ${DIR}/sdf_example_2_sdf.raw
#   ${DIR}/sdf_example_3_sdf.raw
#   ${DIR}/sdf_example_4_sdf.raw
#   PARENT_SCOPE
# )


target_sources(libsdf PRIVATE
  ${DIR}/sdf_example_1_sdf.raw
  ${DIR}/sdf_example_2_sdf.raw
  ${DIR}/sdf_example_3_sdf.raw
  ${DIR}/sdf_example_4_sdf.raw
)