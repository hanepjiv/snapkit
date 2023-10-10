# =============================================================================
# settings --------------------------------------------------------------------
add_definitions(-DHAVE_CONFIG_H)
include_directories(${SNAPKIT_INCLUDE_DIRS})
link_directories(${SNAPKIT_LIBRARY_DIRS})
# =============================================================================
# examples --------------------------------------------------------------------
set(example00_SRCS
  example00.cc
  )
add_executable(example00 ${example00_SRCS})
target_link_libraries(example00 ${SNAPKIT_LIBRARIES})
set_target_properties(example00
  PROPERTIES
  COMPILE_FLAGS         "${SNAPKIT_CXX_FLAGS}"
  LINK_FLAGS            "${SNAPKIT_LD_FLAGS}"
  )
# =============================================================================
# tests -----------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ---------------------------------------------------------------------------
  set(SNAPKIT_EXAMPLE_TEST_EXE)
  # splint  -------------------------------------------------------------------
  if(SPLINT)
    add_test(example-splint ${SPLINT_SH})
    list(APPEND SNAPKIT_EXAMPLE_TEST_EXE example-splint)
  endif()
  # cpplint  ------------------------------------------------------------------
  add_test(NAME example-cpplint COMMAND ${CPPLINT}
    ${CPPLINT_FLAGS}
    "--repository=${CMAKE_SOURCE_DIR}"
    "--root=example"
    "${CMAKE_CURRENT_SOURCE_DIR}"
  )
  list(APPEND SNAPKIT_EXAMPLE_TEST_EXE example-cpplint)
  # environment  --------------------------------------------------------------
  set(TEST_ENV_ "${TEST_ENV}")
  list(APPEND TEST_ENV_ "SRCDIR=${CMAKE_CURRENT_SOURCE_DIR}")
  list(APPEND TEST_ENV_ "BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  set_tests_properties(${SNAPKIT_EXAMPLE_TEST_EXE}
    PROPERTIES ENVIRONMENT "${TEST_ENV_}")
endif()
