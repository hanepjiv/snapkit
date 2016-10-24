# ##############################################################################
# subdirectory =================================================================
# ------------------------------------------------------------------------------
add_subdirectory(snapkit)
# ==============================================================================
# tests  -----------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ----------------------------------------------------------------------------
  set(SNAPKIT_INCLUDE_TEST_EXE)
  # splint  --------------------------------------------------------------------
  if(SPLINT)
    add_test(include-splint ${SPLINT_SH})
    list(APPEND SNAPKIT_INCLUDE_TEST_EXE include-splint)
  endif()
  # cpplint  -------------------------------------------------------------------
  if(PYTHON)
    add_test(include-cpplint ${CPPLINT_SH})
    list(APPEND SNAPKIT_INCLUDE_TEST_EXE include-cpplint)
  endif()
  # environment  ---------------------------------------------------------------
  set(TEST_ENV_ "${TEST_ENV}")
  list(APPEND TEST_ENV_ "SRCDIR=${CMAKE_CURRENT_SOURCE_DIR}")
  list(APPEND TEST_ENV_ "BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  set_tests_properties(${SNAPKIT_INCLUDE_TEST_EXE}
    PROPERTIES ENVIRONMENT "${TEST_ENV_}")
endif()
