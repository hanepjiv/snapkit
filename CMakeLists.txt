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
# snapkit  ====================================================================
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/Modules/")
include(FindPkgConfig)
include(FindThreads)
include(CCxxFlags)
include(SnapkitOptions)
# ------------------------------------------------------------------------------
set(SNAPKIT_PACKAGE "snapkit")
string(TOUPPER ${SNAPKIT_PACKAGE} SNAPKIT_PACKAGE_UPPER)
# ##############################################################################
# version ======================================================================
# ------------------------------------------------------------------------------
set(SNAPKIT_CURRENT  "0")
set(SNAPKIT_REVISION "0")
set(SNAPKIT_AGE    "0")
# ------------------------------------------------------------------------------
if(${SNAPKIT_CURRENT} LESS ${SNAPKIT_AGE})
  message(FATAL_ERROR
    "SNAPKIT_AGE `${SNAPKIT_AGE}' is greater than the current interface number `${SNAPKIT_CURRENT}'.")
endif()
math(EXPR SNAPKIT_MAJOR "${SNAPKIT_CURRENT}-${SNAPKIT_AGE}")
# ------------------------------------------------------------------------------
set(SNAPKIT_RELEASE "${SNAPKIT_MAJOR}.${SNAPKIT_AGE}.${SNAPKIT_REVISION}")
set(SNAPKIT_SOVERSION "${SNAPKIT_MAJOR}")
# ##############################################################################
# flags  =======================================================================
# ------------------------------------------------------------------------------
set(SNAPKIT_C_CXX_FLAGS_DEBUG "-DSNAPKIT_DEBUG")
set(SNAPKIT_C_CXX_FLAGS_RELEASE "-DNDEBUG")
set(SNAPKIT_C_CXX_FLAGS "-fno-asm -fno-builtin")
set(SNAPKIT_C_FLAGS "${SNAPKIT_C_CXX_FLAGS} -std=c99")
set(SNAPKIT_CXX_FLAGS "${SNAPKIT_C_CXX_FLAGS} -std=c++11 -fexceptions -frtti")
# ------------------------------------------------------------------------------
if    ("None" STREQUAL CMAKE_BUILD_TYPE OR NOT CMAKE_BUILD_TYPE)
elseif("Debug" STREQUAL CMAKE_BUILD_TYPE OR "RelWithDebInfo" STREQUAL CMAKE_BUILD_TYPE)
  set(SNAPKIT_C_FLAGS "${SNAPKIT_C_CXX_FLAGS_DEBUG} ${SNAPKIT_C_FLAGS}")
  set(SNAPKIT_CXX_FLAGS "${SNAPKIT_C_CXX_FLAGS_DEBUG} ${SNAPKIT_CXX_FLAGS}")
elseif("Release" STREQUAL CMAKE_BUILD_TYPE OR "MinSizeRel" STREQUAL CMAKE_BUILD_TYPE)
  set(SNAPKIT_C_FLAGS "${SNAPKIT_C_CXX_FLAGS_RELEASE} ${SNAPKIT_C_FLAGS}")
  set(SNAPKIT_CXX_FLAGS "${SNAPKIT_C_CXX_FLAGS_RELEASE} ${SNAPKIT_CXX_FLAGS}")
endif()
# ##############################################################################
# root  ========================================================================
# ------------------------------------------------------------------------------
set(abs_top_srcdir "${CMAKE_CURRENT_SOURCE_DIR}")
# ##############################################################################
# programs =====================================================================
# ------------------------------------------------------------------------------
if (NOT (CMAKE_C_COMPILER_ID STREQUAL CMAKE_CXX_COMPILER_ID))
  message(FATAL_ERROR "Requires C_COMPILER(${CMAKE_C_COMPILER_ID}) == CXX_COMPILER(${CMAKE_CXX_COMPILER_ID})")
endif()
# ##############################################################################
# libraries ====================================================================
# boost ------------------------------------------------------------------------
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.55.0 REQUIRED COMPONENTS)
# ltdl -------------------------------------------------------------------------
find_path(LTDL_INCLUDE_DIR ltdl.h)
find_library(LTDL_LIBRARIES NAMES ltdl)
# Thread  ----------------------------------------------------------------------
set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads)
set(SNAPKIT_THREAD_LIBS ${CMAKE_THREAD_LIBS_INIT})
# ##############################################################################
# dirs  ========================================================================
# ------------------------------------------------------------------------------
set(prefix ${CMAKE_INSTALL_PREFIX})
set(exec_prefix "\${prefix}")
set(libdir "\${exec_prefix}/lib")
set(includedir "\${prefix}/include")
# ------------------------------------------------------------------------------
set(SNAPKIT_INCLUDE_DIRS "")
list(APPEND SNAPKIT_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR})
list(APPEND SNAPKIT_INCLUDE_DIRS ${abs_top_srcdir}/include)
list(APPEND SNAPKIT_INCLUDE_DIRS ${LUA_INCLUDE_DIR})
list(APPEND SNAPKIT_INCLUDE_DIRS ${Boost_INCLUDE_DIR})
list(APPEND SNAPKIT_INCLUDE_DIRS ${LTDL_INCLUDE_DIR})
list(REMOVE_DUPLICATES SNAPKIT_INCLUDE_DIRS)
list(REMOVE_ITEM SNAPKIT_INCLUDE_DIRS "")
# ------------------------------------------------------------------------------
set(SNAPKIT_LIBRARY_DIRS "")
list(APPEND SNAPKIT_LIBRARY_DIRS ${CMAKE_CURRENT_BINARY_DIR}/src)
list(APPEND SNAPKIT_LIBRARY_DIRS ${LUA_LIBRARY_DIR})
list(APPEND SNAPKIT_LIBRARY_DIRS ${Boost_LIBRARY_DIR})
list(APPEND SNAPKIT_LIBRARY_DIRS ${LTDL_LIBRARY_DIR})
list(REMOVE_DUPLICATES SNAPKIT_LIBRARY_DIRS)
list(REMOVE_ITEM SNAPKIT_LIBRARY_DIRS "")
# ------------------------------------------------------------------------------
set(SNAPKIT_LIBRARIES "")
list(APPEND SNAPKIT_LIBRARIES ${LUA_LIBRARIES})
list(APPEND SNAPKIT_LIBRARIES ${LTDL_LIBRARIES})
list(APPEND SNAPKIT_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
list(APPEND SNAPKIT_LIBRARIES ${CMAKE_DL_LIBS})
list(REMOVE_DUPLICATES SNAPKIT_LIBRARIES)
list(REMOVE_ITEM SNAPKIT_LIBRARIES "")
# ##############################################################################
# extra ========================================================================
# ------------------------------------------------------------------------------
configure_file(${abs_top_srcdir}/config.h.in config.h @ONLY)
configure_file(${abs_top_srcdir}/snapkit.pc.in snapkit.pc @ONLY)
configure_file(${abs_top_srcdir}/Doxyfile.in Doxyfile @ONLY)
# ##############################################################################
# for uninstall ================================================================
# ------------------------------------------------------------------------------
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in cmake_uninstall.cmake
  IMMEDIATE @ONLY
  )
add_custom_target(uninstall
  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
  )
# ##############################################################################
# pkgconfig ====================================================================
# ------------------------------------------------------------------------------
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/snapkit.pc
  DESTINATION lib/pkgconfig)
# ##############################################################################
# test =========================================================================
# ------------------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ============================================================================
  # ----------------------------------------------------------------------------
  enable_testing()
  # checks  ====================================================================
  # splint  --------------------------------------------------------------------
  find_program(SPLINT splint)
  if(NOT SPLINT)
    message(FATAL_ERROR "Test feature requires splint.")
  endif()
  message(STATUS "${SPLINT}")
  configure_file(${abs_top_srcdir}/tools/et-splint/splint.sh.in
    tools/et-splint/splint.sh @ONLY)
  set(SPLINT_FLAGS "")
  set(SPLINT_FLAGS "${SPLINT_FLAGS} -DSNAPKIT_EXPORTS")
  foreach(loop_var IN LISTS SNAPKIT_INCLUDE_DIRS)
    set(SPLINT_FLAGS "${SPLINT_FLAGS} -I ${loop_var}")
  endforeach()
  set(SPLINT_SH /bin/env sh ${CMAKE_CURRENT_BINARY_DIR}/tools/et-splint/splint.sh
   )
  # cpplint  -------------------------------------------------------------------
  find_program(PYTHON2 python2)
  if(NOT PYTHON2)
    message(FATAL_ERROR "Test feature requires python2.")
  endif()
  message(STATUS "${PYTHON2}")
  configure_file(${abs_top_srcdir}/tools/et-cpplint/cpplint.sh.in
    tools/et-cpplint/cpplint.sh @ONLY)
  set(CPPLINT "python2 ${abs_top_srcdir}/tools/et-cpplint/cpplint.py"
   )
  set(CPPLINT_FLAGS "")
  set(CPPLINT_SH /bin/env sh ${CMAKE_CURRENT_BINARY_DIR}/tools/et-cpplint/cpplint.sh
   )
  # LD_LIBRARY_PATH  -----------------------------------------------------------
  set(LD_LIBRARY_PATH "")
  foreach(loop_var IN LISTS SNAPKIT_LIBRARY_DIRS)
    set(LD_LIBRARY_PATH "${LD_LIBRARY_PATH}:${loop_var}")
  endforeach()
  # environment  ---------------------------------------------------------------
  set(TEST_ENV "")
  list(APPEND TEST_ENV "LD_LIBRARY_PATH=${LD_LIBRARY_PATH}")
  list(APPEND TEST_ENV "TOP_SRCDIR=${abs_top_srcdir}")
  list(APPEND TEST_ENV "TOP_BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  list(APPEND TEST_ENV "SPLINT=${SPLINT} ${SPLINT_FLAGS} -DSNAPKIT_EXPORTS")
  list(APPEND TEST_ENV "CPPLINT=${CPPLINT} ${CPPLINT_FLAGS}")
endif()
# ##############################################################################
# subdirectory =================================================================
# ------------------------------------------------------------------------------
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(test)
