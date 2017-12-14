# =============================================================================
# settings --------------------------------------------------------------------
add_definitions(-DHAVE_CONFIG_H)
include_directories(${SNAPKIT_INCLUDE_DIRS})
link_directories(${SNAPKIT_LIBRARY_DIRS})
# =============================================================================
# snapkit  --------------------------------------------------------------------
add_library(snapkit SHARED
  snapkit.cc
  )
target_link_libraries(snapkit
  )
set_target_properties(snapkit
  PROPERTIES
  OUTPUT_NAME snapkit
  VERSION ${SNAPKIT_VERSION}
  SOVERSION ${SNAPKIT_SOVERSION}
  COMPILE_FLAGS         "-DSNAPKIT_EXPORTS ${SNAPKIT_CXX_FLAGS}"
  LINK_FLAGS            "${SNAPKIT_LD_FLAGS}"
  )
# -----------------------------------------------------------------------------
install(TARGETS
  snapkit
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
# =============================================================================
# tests  ----------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ---------------------------------------------------------------------------
  set(SNAPKIT_SRC_TEST_EXE)
  # splint  -------------------------------------------------------------------
  if(SPLINT)
    add_test(src-splint ${SPLINT_SH})
    list(APPEND SNAPKIT_SRC_TEST_EXE src-splint)
  endif()
  # cpplint  ------------------------------------------------------------------
  if(PYTHON)
    add_test(src-cpplint ${CPPLINT_SH})
    list(APPEND SNAPKIT_SRC_TEST_EXE src-cpplint)
  endif()
  # environment  --------------------------------------------------------------
  set(TEST_ENV_ "${TEST_ENV}")
  list(APPEND TEST_ENV_ "SRCDIR=${CMAKE_CURRENT_SOURCE_DIR}")
  list(APPEND TEST_ENV_ "BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  set_tests_properties(${SNAPKIT_SRC_TEST_EXE}
    PROPERTIES ENVIRONMENT "${TEST_ENV_}")
endif()
