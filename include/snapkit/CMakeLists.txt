# ##############################################################################
# The MIT License (MIT)
#
# Copyright (c) <2015> hanepjiv <hanepjiv@gmail.com>
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
# ##############################################################################
# subdirectory =================================================================
# ------------------------------------------------------------------------------

# ==============================================================================
# snapkit  --------------------------------------------------------------------
set(SNAPKIT_INCLUDE_SNAPKIT_SRC "${abs_top_srcdir}/include/snapkit")
set(SNAPKIT_INCLUDE_SNAPKIT_DEST "include/snapkit")
# ------------------------------------------------------------------------------
set(snapkit_HEADERS
  ${SNAPKIT_INCLUDE_SNAPKIT_SRC}/call.h
  ${SNAPKIT_INCLUDE_SNAPKIT_SRC}/declspec.h
  ${SNAPKIT_INCLUDE_SNAPKIT_SRC}/begin.h

  ${SNAPKIT_INCLUDE_SNAPKIT_SRC}/debug.h

  # here
  )
# ------------------------------------------------------------------------------
install(FILES
  ${snapkit_HEADERS}
  DESTINATION ${SNAPKIT_INCLUDE_SNAPKIT_DEST})
# ==============================================================================
# tests  -----------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ----------------------------------------------------------------------------
  set(SNAPKIT_INCLUDE_SNAPKIT_TEST_EXE)
  # splint  --------------------------------------------------------------------
  if(SPLINT)
    add_test(splint-include-snapkit ${SPLINT_SH})
    list(APPEND SNAPKIT_INCLUDE_SNAPKIT_TEST_EXE splint-include-snapkit)
  endif()
  # cpplint  -------------------------------------------------------------------
  if(PYTHON)
    add_test(cpplint-include-snapkit ${CPPLINT_SH})
    list(APPEND SNAPKIT_INCLUDE_SNAPKIT_TEST_EXE cpplint-include-snapkit)
  endif()
  # environment  ---------------------------------------------------------------
  set(TEST_ENV_ "${TEST_ENV}")
  list(APPEND TEST_ENV_ "SRCDIR=${abs_top_srcdir}/include/snapkit")
  list(APPEND TEST_ENV_ "BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  set_tests_properties(${SNAPKIT_INCLUDE_SNAPKIT_TEST_EXE}
    PROPERTIES ENVIRONMENT "${TEST_ENV_}")
endif()
