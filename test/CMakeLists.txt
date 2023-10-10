# =============================================================================
# settings --------------------------------------------------------------------
add_definitions(-DHAVE_CONFIG_H)
include_directories(${SNAPKIT_INCLUDE_DIRS})
link_directories(${SNAPKIT_LIBRARY_DIRS})
# =============================================================================
# tests -----------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ---------------------------------------------------------------------------
  set(SNAPKIT_TEST_TEST_EXE)
  # splint  -------------------------------------------------------------------
  if(SPLINT)
    add_test(test-splint ${SPLINT_SH})
    list(APPEND SNAPKIT_TEST_TEST_EXE test-splint)
  endif()
  # cpplint  ------------------------------------------------------------------
  add_test(NAME test-cpplint COMMAND ${CPPLINT}
    ${CPPLINT_FLAGS}
    "--repository=${CMAKE_SOURCE_DIR}"
    "--root=test"
    "${CMAKE_CURRENT_SOURCE_DIR}"
  )
  list(APPEND SNAPKIT_TEST_TEST_EXE test-cpplint)
  # ---------------------------------------------------------------------------
  set(test00_SRCS
    test00.cc
    )
  add_executable(test00 ${test00_SRCS})
  target_link_libraries(test00 ${SNAPKIT_LIBRARIES})
  set_target_properties(test00
    PROPERTIES
    COMPILE_FLAGS       "${SNAPKIT_CXX_FLAGS}"
    LINK_FLAGS          "${SNAPKIT_LD_FLAGS}"
    )
  add_test(test-test00 test00)
  list(APPEND SNAPKIT_TEST_TEST_EXE test-test00)
  # environment  --------------------------------------------------------------
  set(TEST_ENV_ "${TEST_ENV}")
  list(APPEND TEST_ENV_ "SRCDIR=${CMAKE_CURRENT_SOURCE_DIR}")
  list(APPEND TEST_ENV_ "BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  set_tests_properties(${SNAPKIT_TEST_TEST_EXE}
    PROPERTIES ENVIRONMENT "${TEST_ENV_}")
endif()
