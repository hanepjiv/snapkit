# ##############################################################################
# The MIT License (MIT)
#
# Copyright (c) <2016> hanepjiv <hanepjiv@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ==============================================================================
# settings ---------------------------------------------------------------------
add_definitions(-DHAVE_CONFIG_H)
include_directories(${SNAPKIT_INCLUDE_DIRS})
link_directories(${SNAPKIT_LIBRARY_DIRS})
# ==============================================================================
# examples ---------------------------------------------------------------------
set(example00_SRCS
  example00.cc
  )
add_executable(example00 ${example00_SRCS})
target_link_libraries(example00 ${SNAPKIT_LIBRARIES})
set_target_properties(example00
  PROPERTIES
  COMPILE_FLAGS "${SNAPKIT_CXX_FLAGS}"
  )
# ==============================================================================
# tests ------------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ----------------------------------------------------------------------------
  set(SNAPKIT_EXAMPLE_TEST_EXE)
  # splint  --------------------------------------------------------------------
  if(SPLINT)
    add_test(example-splint ${SPLINT_SH})
    list(APPEND SNAPKIT_EXAMPLE_TEST_EXE example-splint)
  endif()
  # cpplint  -------------------------------------------------------------------
  if(PYTHON)
    add_test(example-cpplint ${CPPLINT_SH})
    list(APPEND SNAPKIT_EXAMPLE_TEST_EXE example-cpplint)
  endif()
  # environment  ---------------------------------------------------------------
  set(TEST_ENV_ "${TEST_ENV}")
  list(APPEND TEST_ENV_ "SRCDIR=${CMAKE_CURRENT_SOURCE_DIR}")
  list(APPEND TEST_ENV_ "BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  set_tests_properties(${SNAPKIT_EXAMPLE_TEST_EXE}
    PROPERTIES ENVIRONMENT "${TEST_ENV_}")
endif()
