# #############################################################################
# CMake  ======================================================================
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/Modules/")
# #############################################################################
# snapkit  ====================================================================
# -----------------------------------------------------------------------------
set(SNAPKIT_PACKAGE     "snapkit")
set(SNAPKIT_CURRENT     "0")
set(SNAPKIT_REVISION    "0")
set(SNAPKIT_AGE         "0")
set(SNAPKIT_BUGREPORT   "hanepjiv <hanepjiv@gmail.com>")
set(SNAPKIT_URL         "https://")
# -----------------------------------------------------------------------------
if(${SNAPKIT_CURRENT} LESS ${SNAPKIT_AGE})
  message(FATAL_ERROR
    "SNAPKIT_AGE `${SNAPKIT_AGE}' is greater than the current interface number `${SNAPKIT_CURRENT}'.")
endif()
# -----------------------------------------------------------------------------
string(TOUPPER ${SNAPKIT_PACKAGE} SNAPKIT_PACKAGE_UPPER)
math(EXPR SNAPKIT_MAJOR "${SNAPKIT_CURRENT}-${SNAPKIT_AGE}")
set(SNAPKIT_VERSION "${SNAPKIT_MAJOR}.${SNAPKIT_AGE}.${SNAPKIT_REVISION}")
set(SNAPKIT_SOVERSION "${SNAPKIT_MAJOR}")
# -----------------------------------------------------------------------------
project(${SNAPKIT_PACKAGE}
  VERSION ${SNAPKIT_VERSION})
# #############################################################################
# include  ====================================================================
# -----------------------------------------------------------------------------
include(FindPkgConfig)
include(FindThreads)
include(CCxxFlags)
# #############################################################################
# options  ====================================================================
# -----------------------------------------------------------------------------
option(SNAPKIT_ENABLE_TEST "Test feature." OFF)
# #############################################################################
# flags  ======================================================================
# -----------------------------------------------------------------------------
set(SNAPKIT_C_CXX_FLAGS                 "")
set(SNAPKIT_C_CXX_FLAGS_DEBUG           "-DSNAPKIT_DEBUG")
set(SNAPKIT_C_CXX_FLAGS_RELWITHDEBINFO  "-DSNAPKIT_DEBUG")
set(SNAPKIT_C_CXX_FLAGS_RELEASE         "-DNDEBUG")
set(SNAPKIT_C_CXX_FLAGS_MINSIZEREL      "-DNDEBUG")
set(SNAPKIT_C_FLAGS                     "")
set(SNAPKIT_C_FLAGS_DEBUG               "")
set(SNAPKIT_C_FLAGS_RELWITHDEBINFO      "")
set(SNAPKIT_C_FLAGS_RELEASE             "")
set(SNAPKIT_C_FLAGS_MINSIZEREL          "")
set(SNAPKIT_CXX_FLAGS                   "")
set(SNAPKIT_CXX_FLAGS_DEBUG             "")
set(SNAPKIT_CXX_FLAGS_RELWITHDEBINFO    "")
set(SNAPKIT_CXX_FLAGS_RELEASE           "")
set(SNAPKIT_CXX_FLAGS_MINSIZEREL        "")
set(SNAPKIT_LD_FLAGS                    "")
# -----------------------------------------------------------------------------
if (CMAKE_COMPILER_IS_GNUCC OR
    CMAKE_C_COMPILER_ID STREQUAL "Clang")       # GCC or Clang  ===============
  set(SNAPKIT_C_CXX_FLAGS               "${SNAPKIT_C_CXX_FLAGS} -fno-asm -fno-builtin")
  set(SNAPKIT_C_FLAGS                   "${SNAPKIT_C_FLAGS} -std=c99")
  set(SNAPKIT_CXX_FLAGS                 "${SNAPKIT_CXX_FLAGS} -std=c++11 -fexceptions -frtti")
endif()
# -----------------------------------------------------------------------------
if (CMAKE_COMPILER_IS_GNUCC)                    # GCC  ========================

elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang")    # Clang  ======================

elseif(CMAKE_C_COMPILER_ID STREQUAL "Intel")    # Intel  ======================
  message(FATAL_ERROR "Intel is not yet supported.")
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")     # MSVC  =======================
  message(FATAL_ERROR "MSVC is not yet supported.")
endif()
# -----------------------------------------------------------------------------
set(SNAPKIT_USER_C_CXX_FLAGS "${SNAPKIT_C_CXX_FLAGS}"  CACHE STRING "")
set(SNAPKIT_USER_C_CXX_FLAGS_DEBUG "${SNAPKIT_C_CXX_FLAGS_DEBUG}"  CACHE STRING "")
set(SNAPKIT_USER_C_CXX_FLAGS_RELWITHDEBINFO "${SNAPKIT_C_CXX_FLAGS_RELWITHDEBINFO}"  CACHE STRING "")
set(SNAPKIT_USER_C_CXX_FLAGS_RELEASE "${SNAPKIT_C_CXX_FLAGS_RELEASE}"  CACHE STRING "")
set(SNAPKIT_USER_C_CXX_FLAGS_MINSIZEREL "${SNAPKIT_C_CXX_FLAGS_MINSIZEREL}"  CACHE STRING "")
set(SNAPKIT_USER_C_FLAGS "${SNAPKIT_C_FLAGS}"  CACHE STRING "")
set(SNAPKIT_USER_C_FLAGS_DEBUG "${SNAPKIT_C_FLAGS_DEBUG}"  CACHE STRING "")
set(SNAPKIT_USER_C_FLAGS_RELWITHDEBINFO "${SNAPKIT_C_FLAGS_RELWITHDEBINFO}"  CACHE STRING "")
set(SNAPKIT_USER_C_FLAGS_RELEASE "${SNAPKIT_C_FLAGS_RELEASE}"  CACHE STRING "")
set(SNAPKIT_USER_C_FLAGS_MINSIZEREL "${SNAPKIT_C_FLAGS_MINSIZEREL}"  CACHE STRING "")
set(SNAPKIT_USER_CXX_FLAGS "${SNAPKIT_CXX_FLAGS}"  CACHE STRING "")
set(SNAPKIT_USER_CXX_FLAGS_DEBUG "${SNAPKIT_CXX_FLAGS_DEBUG}"  CACHE STRING "")
set(SNAPKIT_USER_CXX_FLAGS_RELWITHDEBINFO "${SNAPKIT_CXX_FLAGS_RELWITHDEBINFO}"  CACHE STRING "")
set(SNAPKIT_USER_CXX_FLAGS_RELEASE "${SNAPKIT_CXX_FLAGS_RELEASE}"  CACHE STRING "")
set(SNAPKIT_USER_CXX_FLAGS_MINSIZEREL "${SNAPKIT_CXX_FLAGS_MINSIZEREL}"  CACHE STRING "")
# -----------------------------------------------------------------------------
if    ("None" STREQUAL CMAKE_BUILD_TYPE OR NOT CMAKE_BUILD_TYPE)
elseif("Debug" STREQUAL CMAKE_BUILD_TYPE)
  set(SNAPKIT_C_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_DEBUG} ${SNAPKIT_USER_C_FLAGS} ${SNAPKIT_USER_C_FLAGS_DEBUG}")
  set(SNAPKIT_CXX_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_DEBUG} ${SNAPKIT_USER_CXX_FLAGS} ${SNAPKIT_USER_CXX_FLAGS_DEBUG}")
elseif("RelWithDebInfo" STREQUAL CMAKE_BUILD_TYPE)
  set(SNAPKIT_C_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_RELWITHDEBINFO} ${SNAPKIT_USER_C_FLAGS} ${SNAPKIT_USER_C_FLAGS_RELWITHDEBINFO}")
  set(SNAPKIT_CXX_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_RELWITHDEBINFO} ${SNAPKIT_USER_CXX_FLAGS} ${SNAPKIT_USER_CXX_FLAGS_RELWITHDEBINFO}")
elseif("Release" STREQUAL CMAKE_BUILD_TYPE)
  set(SNAPKIT_C_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_RELEASE} ${SNAPKIT_USER_C_FLAGS} ${SNAPKIT_USER_C_FLAGS_RELEASE}")
  set(SNAPKIT_CXX_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_RELEASE} ${SNAPKIT_USER_CXX_FLAGS} ${SNAPKIT_USER_CXX_FLAGS_RELEASE}")
elseif("MinSizeRel" STREQUAL CMAKE_BUILD_TYPE)
  set(SNAPKIT_C_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_MINSIZEREL} ${SNAPKIT_USER_C_FLAGS} ${SNAPKIT_USER_C_FLAGS_MINSIZEREL}")
  set(SNAPKIT_CXX_FLAGS "${SNAPKIT_USER_C_CXX_FLAGS} ${SNAPKIT_USER_C_CXX_FLAGS_MINSIZEREL} ${SNAPKIT_USER_CXX_FLAGS} ${SNAPKIT_USER_CXX_FLAGS_MINSIZEREL}")
endif()
# #############################################################################
# root  =======================================================================
# -----------------------------------------------------------------------------
set(abs_top_srcdir "${CMAKE_CURRENT_SOURCE_DIR}")
# #############################################################################
# programs ====================================================================
# -----------------------------------------------------------------------------
if (NOT (CMAKE_C_COMPILER_ID STREQUAL CMAKE_CXX_COMPILER_ID))
  message(FATAL_ERROR "Requires C_COMPILER(${CMAKE_C_COMPILER_ID}) == CXX_COMPILER(${CMAKE_CXX_COMPILER_ID})")
endif()
# #############################################################################
# dirs  =======================================================================
# -----------------------------------------------------------------------------
set(prefix ${CMAKE_INSTALL_PREFIX})
set(exec_prefix "\${prefix}")
set(libdir "\${exec_prefix}/lib")
set(includedir "\${prefix}/include")
set(datadir "\${exec_prefix}/share")
set(mandir "\${datadir}/man")
# -----------------------------------------------------------------------------
set(SNAPKIT_INCLUDE_DIRS "")
list(APPEND SNAPKIT_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR})
list(APPEND SNAPKIT_INCLUDE_DIRS ${abs_top_srcdir}/include)
# -----------------------------------------------------------------------------
set(SNAPKIT_LIBRARY_DIRS "")
list(APPEND SNAPKIT_LIBRARY_DIRS ${CMAKE_CURRENT_BINARY_DIR}/src)
# -----------------------------------------------------------------------------
set(SNAPKIT_LIBRARIES "")
# #############################################################################
# libraries  ==================================================================
# boost  ----------------------------------------------------------------------
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.56.0 REQUIRED COMPONENTS)
list(APPEND SNAPKIT_INCLUDE_DIRS        ${Boost_INCLUDE_DIR})
list(APPEND SNAPKIT_LIBRARY_DIRS        ${Boost_LIBRARY_DIR})
# ltdl  -----------------------------------------------------------------------
find_path(LTDL_INCLUDE_DIR ltdl.h)
find_library(LTDL_LIBRARIES NAMES ltdl)
list(APPEND SNAPKIT_INCLUDE_DIRS        ${LTDL_INCLUDE_DIR})
list(APPEND SNAPKIT_LIBRARY_DIRS        ${LTDL_LIBRARY_DIR})
list(APPEND SNAPKIT_LIBRARIES           ${LTDL_LIBRARIES})
list(APPEND SNAPKIT_LIBRARIES           ${CMAKE_DL_LIBS})
# Thread  ---------------------------------------------------------------------
set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads)
set(SNAPKIT_THREAD_LIBS                 ${CMAKE_THREAD_LIBS_INIT})
list(APPEND SNAPKIT_LIBRARIES           ${CMAKE_THREAD_LIBS_INIT})
# #############################################################################
# dirs cleanup  ===============================================================
# -----------------------------------------------------------------------------
list(REMOVE_DUPLICATES  SNAPKIT_INCLUDE_DIRS)
list(REMOVE_ITEM        SNAPKIT_INCLUDE_DIRS "")
# -----------------------------------------------------------------------------
list(REMOVE_DUPLICATES  SNAPKIT_LIBRARY_DIRS)
list(REMOVE_ITEM        SNAPKIT_LIBRARY_DIRS "")
# -----------------------------------------------------------------------------
list(REMOVE_DUPLICATES  SNAPKIT_LIBRARIES)
list(REMOVE_ITEM        SNAPKIT_LIBRARIES "")
# #############################################################################
# extra  ======================================================================
# -----------------------------------------------------------------------------
configure_file(${abs_top_srcdir}/config.h.cmake config.h @ONLY)
configure_file(${abs_top_srcdir}/snapkit.pc.in snapkit.pc @ONLY)
configure_file(${abs_top_srcdir}/Doxyfile.in Doxyfile @ONLY)
# #############################################################################
# uninstall  ==================================================================
# -----------------------------------------------------------------------------
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in cmake_uninstall.cmake
  IMMEDIATE @ONLY
  )
add_custom_target(uninstall
  ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
  )
# #############################################################################
# pkgconfig  ==================================================================
# -----------------------------------------------------------------------------
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/snapkit.pc
  DESTINATION lib/pkgconfig)
# #############################################################################
# test  =======================================================================
# -----------------------------------------------------------------------------
if(SNAPKIT_ENABLE_TEST)
  # ===========================================================================
  # ---------------------------------------------------------------------------
  enable_testing()
  # checks  ===================================================================
  # splint  -------------------------------------------------------------------
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
  set(SPLINT_SH /bin/env sh ${CMAKE_CURRENT_BINARY_DIR}/tools/et-splint/splint.sh)
  # cpplint  ------------------------------------------------------------------
  find_program(PYTHON python2)
  if(NOT PYTHON)
    message(FATAL_ERROR "Test feature requires python.")
  endif()
  message(STATUS "${PYTHON}")
  configure_file(${abs_top_srcdir}/tools/et-cpplint/cpplint.sh.in
    tools/et-cpplint/cpplint.sh @ONLY)
  set(CPPLINT "${PYTHON} ${abs_top_srcdir}/tools/et-cpplint/cpplint.py")
  set(CPPLINT_FLAGS "")
  set(CPPLINT_SH /bin/env sh ${CMAKE_CURRENT_BINARY_DIR}/tools/et-cpplint/cpplint.sh)
  # LD_LIBRARY_PATH  ----------------------------------------------------------
  set(LD_LIBRARY_PATH "")
  foreach(loop_var IN LISTS SNAPKIT_LIBRARY_DIRS)
    set(LD_LIBRARY_PATH "${LD_LIBRARY_PATH}:${loop_var}")
  endforeach()
  # environment  --------------------------------------------------------------
  set(TEST_ENV "")
  list(APPEND TEST_ENV "LD_LIBRARY_PATH=${LD_LIBRARY_PATH}")
  list(APPEND TEST_ENV "TOP_SRCDIR=${abs_top_srcdir}")
  list(APPEND TEST_ENV "TOP_BUILDDIR=${CMAKE_CURRENT_BINARY_DIR}")
  list(APPEND TEST_ENV "SPLINT=${SPLINT} ${SPLINT_FLAGS} -DSNAPKIT_EXPORTS")
  list(APPEND TEST_ENV "CPPLINT=${CPPLINT} ${CPPLINT_FLAGS}")
endif()
# #############################################################################
# subdirectory  ===============================================================
# -----------------------------------------------------------------------------
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(test)
