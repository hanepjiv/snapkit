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
# COMPILER  ====================================================================
# None -------------------------------------------------------------------------
set(COMPILER_C_CXX_FLAGS "")
set(COMPILER_C_FLAGS "")
set(COMPILER_CXX_FLAGS "")
set(COMPILER_EXE_LINKER_FLAGS "")
set(COMPILER_MODULE_LINKER_FLAGS "")
set(COMPILER_SHARED_LINKER_FLAGS "")
set(COMPILER_STATIC_LINKER_FLAGS "")
# DEGUG ------------------------------------------------------------------------
set(COMPILER_C_CXX_FLAGS_DEBUG "")
set(COMPILER_C_FLAGS_DEBUG "")
set(COMPILER_CXX_FLAGS_DEBUG "")
set(COMPILER_EXE_LINKER_FLAGS_DEBUG "")
set(COMPILER_MODULE_LINKER_FLAGS_DEBUG "")
set(COMPILER_SHARED_LINKER_FLAGS_DEBUG "")
set(COMPILER_STATIC_LINKER_FLAGS_DEBUG "")
# RELEASE-----------------------------------------------------------------------
set(COMPILER_C_CXX_FLAGS_RELEASE "")
set(COMPILER_C_FLAGS_RELEASE "")
set(COMPILER_CXX_FLAGS_RELEASE "")
set(COMPILER_EXE_LINKER_FLAGS_RELEASE "")
set(COMPILER_MODULE_LINKER_FLAGS_RELEASE "")
set(COMPILER_SHARED_LINKER_FLAGS_RELEASE "")
set(COMPILER_STATIC_LINKER_FLAGS_RELEASE "")
# RELWITHDEBINFO ---------------------------------------------------------------
set(COMPILER_C_CXX_FLAGS_RELWITHDEBINFO "")
set(COMPILER_C_FLAGS_RELWITHDEBINFO "")
set(COMPILER_CXX_FLAGS_RELWITHDEBINFO "")
set(COMPILER_EXE_LINKER_FLAGS_RELWITHDEBINFO "")
set(COMPILER_MODULE_LINKER_FLAGS_RELWITHDEBINFO "")
set(COMPILER_SHARED_LINKER_FLAGS_RELWITHDEBINFO "")
set(COMPILER_STATIC_LINKER_FLAGS_RELWITHDEBINFO "")
# MINSIZEREL--------------------------------------------------------------------
set(COMPILER_C_CXX_FLAGS_MINSIZEREL "")
set(COMPILER_C_FLAGS_MINSIZEREL "")
set(COMPILER_CXX_FLAGS_MINSIZEREL "")
set(COMPILER_EXE_LINKER_FLAGS_MINSIZEREL "")
set(COMPILER_MODULE_LINKER_FLAGS_MINSIZEREL "")
set(COMPILER_SHARED_LINKER_FLAGS_MINSIZEREL "")
set(COMPILER_STATIC_LINKER_FLAGS_MINSIZEREL "")
# ##############################################################################
# compiler  ====================================================================
if (CMAKE_COMPILER_IS_GNUCC OR
    CMAKE_C_COMPILER_ID STREQUAL "Clang")       # GCC or Clang  ================
  # Common  --------------------------------------------------------------------
  if (UNIX)
    set(COMPILER_C_CXX_FLAGS "${COMPILER_C_CXX_FLAGS} -fPIC")
    set(COMPILER_SHARED_LINKER_FLAGS "${COMPILER_SHARED_LINKER_FLAGS} -Wl,-z,defs")
  elseif(MINGW)
    set(COMPILER_SHARED_LINKER_FLAGS "${COMPILER_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
  else()
    message(FATAL_ERROR "not yet supported.")
  endif()
  set(COMPILER_C_CXX_FLAGS "${COMPILER_C_CXX_FLAGS} -pipe -DPIC -D_REENTRANT -D_THREAD_SAFE -fvisibility=hidden -fstrict-aliasing -pedantic-errors -W -Wall -Wextra -Werror -Wstrict-aliasing=1 -Wformat=2 -Wundef -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wno-missing-field-initializers -Wno-sign-compare -Wconversion -Wfloat-equal -Wredundant-decls -Wno-unused-parameter -Wunused-result -Wmissing-declarations -Wsign-compare")
  set(COMPILER_C_FLAGS "${COMPILER_C_FLAGS} -Wbad-function-cast -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wnested-externs -Wdeclaration-after-statement")
  set(COMPILER_CXX_FLAGS "${COMPILER_CXX_FLAGS} -fvisibility-inlines-hidden -fthreadsafe-statics -Weffc++ -Woverloaded-virtual -Wsign-promo -Wsynth")
  set(COMPILER_SHARED_LINKER_FLAGS "${COMPILER_SHARED_LINKER_FLAGS} -shared")
  # Debug  ---------------------------------------------------------------------
  set(COMPILER_C_CXX_FLAGS_DEBUG "${COMPILER_C_CXX_FLAGS_DEBUG} -O0 -g -fverbose-asm")
  # Release  -------------------------------------------------------------------
  set(COMPILER_C_CXX_FLAGS_RELEASE "${COMPILER_C_CXX_FLAGS_RELEASE} -O3 -fomit-frame-pointer")
  # RelWithDebInfo  ------------------------------------------------------------
  set(COMPILER_C_CXX_FLAGS_RELWITHDEBINFO "${COMPILER_C_CXX_FLAGS_RELWITHDEBINFO} -O2 -g -fverbose-asm")
  # MinSizeRel  ----------------------------------------------------------------
  set(COMPILER_C_CXX_FLAGS_MINSIZEREL "${COMPILER_C_CXX_FLAGS_MINSIZEREL} -Os -fomit-frame-pointer")
endif()
if (CMAKE_COMPILER_IS_GNUCC)                    # GCC  =========================
  # Common  --------------------------------------------------------------------
  #  pass
  # Debug  ---------------------------------------------------------------------
  set(COMPILER_C_CXX_FLAGS_DEBUG "${COMPILER_C_CXX_FLAGS_DEBUG} -pg -ftrapv")
  set(COMPILER_EXE_LINKER_FLAGS_DEBUG "${COMPILER_EXE_LINKER_FLAGS_DEBUG} -pg")
  set(COMPILER_MODULE_LINKER_FLAGS_DEBUG "${COMPILER_MODULE_LINKER_FLAGS_DEBUG} -pg")
  # Release  -------------------------------------------------------------------
  #   pass
  # RelWithDebInfo  ------------------------------------------------------------
  set(COMPILER_C_CXX_FLAGS_RELWITHDEBINFO "${COMPILER_C_CXX_FLAGS_RELWITHDEBINFO} ${COMPILER_C_CXX_FLAGS_DEBUG}")
  set(COMPILER_EXE_LINKER_FLAGS_RELWITHDEBINFO "${COMPILER_EXE_LINKER_FLAGS_RELWITHDEBINFO} ${COMPILER_EXE_LINKER_FLAGS_DEBUG}")
  set(COMPILER_MODULE_LINKER_FLAGS_RELWITHDEBINFO "${COMPILER_MODULE_LINKER_FLAGS_RELWITHDEBINFO} ${COMPILER_MODULE_LINKER_FLAGS_RELWITHDEBINFO}")
  # MinSizeRel  ----------------------------------------------------------------
  #   pass
elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang")    # Clang  =======================
  # Common  --------------------------------------------------------------------
  set(COMPILER_C_FLAGS "${COMPILER_C_FLAGS} -fsanitize-undefined-trap-on-error")
  # Debug  ---------------------------------------------------------------------
  #   pass
  # Release  -------------------------------------------------------------------
  #   pass
  # RelWithDebInfo  ------------------------------------------------------------
  #   pass
  # MinSizeRel  ----------------------------------------------------------------
  #   pass
elseif(CMAKE_C_COMPILER_ID STREQUAL "Intel")    # Intel  =======================
  message(FATAL_ERROR "Intel is not yet supported.")
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")     # MSVC  ========================
  message(FATAL_ERROR "MSVC is not yet supported.")
endif()
# ##############################################################################
# USER  ========================================================================
# Common  ----------------------------------------------------------------------
set(USER_C_FLAGS "${COMPILER_C_CXX_FLAGS} ${COMPILER_C_FLAGS}" CACHE STRING "")
set(USER_CXX_FLAGS "${COMPILER_C_CXX_FLAGS} ${COMPILER_CXX_FLAGS}" CACHE STRING "")
set(USER_EXE_LINKER_FLAGS "${COMPILER_EXE_LINKER_FLAGS}" CACHE STRING "")
set(USER_MODULE_LINKER_FLAGS "${COMPILER_MODULE_LINKER_FLAGS}" CACHE STRING "")
set(USER_SHARED_LINKER_FLAGS "${COMPILER_SHARED_LINKER_FLAGS}" CACHE STRING "")
set(USER_STATIC_LINKER_FLAGS "${COMPILER_STATIC_LINKER_FLAGS}" CACHE STRING "")
# Debug  -----------------------------------------------------------------------
set(USER_C_FLAGS_DEBUG "${COMPILER_C_CXX_FLAGS_DEBUG} ${COMPILER_C_FLAGS_DEBUG}" CACHE STRING "")
set(USER_CXX_FLAGS_DEBUG "${COMPILER_C_CXX_FLAGS_DEBUG} ${COMPILER_CXX_FLAGS_DEBUG}" CACHE STRING "")
set(USER_EXE_LINKER_FLAGS_DEBUG "${COMPILER_EXE_LINKER_FLAGS_DEBUG}" CACHE STRING "")
set(USER_MODULE_LINKER_FLAGS_DEBUG "${COMPILER_MODULE_LINKER_FLAGS_DEBUG}" CACHE STRING "")
set(USER_SHARED_LINKER_FLAGS_DEBUG "${COMPILER_SHARED_LINKER_FLAGS_DEBUG}" CACHE STRING "")
set(USER_STATIC_LINKER_FLAGS_DEBUG "${COMPILER_STATIC_LINKER_FLAGS_DEBUG}" CACHE STRING "")
# Release  -------------------------------------------------------------------
set(USER_C_FLAGS_RELEASE "${COMPILER_C_CXX_FLAGS_RELEASE} ${COMPILER_C_FLAGS_RELEASE}" CACHE STRING "")
set(USER_CXX_FLAGS_RELEASE "${COMPILER_C_CXX_FLAGS_RELEASE} ${COMPILER_CXX_FLAGS_RELEASE}" CACHE STRING "")
set(USER_EXE_LINKER_FLAGS_RELEASE "${COMPILER_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "")
set(USER_MODULE_LINKER_FLAGS_RELEASE "${COMPILER_MODULE_LINKER_FLAGS_RELEASE}" CACHE STRING "")
set(USER_SHARED_LINKER_FLAGS_RELEASE "${COMPILER_SHARED_LINKER_FLAGS_RELEASE}" CACHE STRING "")
set(USER_STATIC_LINKER_FLAGS_RELEASE "${COMPILER_STATIC_LINKER_FLAGS_RELEASE}" CACHE STRING "")
# RelWithDebInfo  --------------------------------------------------------------
set(USER_C_FLAGS_RELWITHDEBINFO "${COMPILER_C_CXX_FLAGS_RELWITHDEBINFO} ${COMPILER_C_FLAGS_RELWITHDEBINFO}" CACHE STRING "")
set(USER_CXX_FLAGS_RELWITHDEBINFO "${COMPILER_C_CXX_FLAGS_RELWITHDEBINFO} ${COMPILER_CXX_FLAGS_RELWITHDEBINFO}" CACHE STRING "")
set(USER_EXE_LINKER_FLAGS_RELWITHDEBINFO "${COMPILER_EXE_LINKER_FLAGS_RELWITHDEBINFO}" CACHE STRING "")
set(USER_MODULE_LINKER_FLAGS_RELWITHDEBINFO "${COMPILER_MODULE_LINKER_FLAGS_RELWITHDEBINFO}" CACHE STRING "")
set(USER_SHARED_LINKER_FLAGS_RELWITHDEBINFO "${COMPILER_SHARED_LINKER_FLAGS_RELWITHDEBINFO}" CACHE STRING "")
set(USER_STATIC_LINKER_FLAGS_RELWITHDEBINFO "${COMPILER_STATIC_LINKER_FLAGS_RELWITHDEBINFO}" CACHE STRING "")
# MinSizeRel  ------------------------------------------------------------------
set(USER_C_FLAGS_MINSIZEREL "${COMPILER_C_CXX_FLAGS_MINSIZEREL} ${COMPILER_C_FLAGS_MINSIZEREL}" CACHE STRING "")
set(USER_CXX_FLAGS_MINSIZEREL "${COMPILER_C_CXX_FLAGS_MINSIZEREL} ${COMPILER_CXX_FLAGS_MINSIZEREL}" CACHE STRING "")
set(USER_EXE_LINKER_FLAGS_MINSIZEREL "${COMPILER_EXE_LINKER_FLAGS_MINSIZEREL}" CACHE STRING "")
set(USER_MODULE_LINKER_FLAGS_MINSIZEREL "${COMPILER_MODULE_LINKER_FLAGS_MINSIZEREL}" CACHE STRING "")
set(USER_SHARED_LINKER_FLAGS_MINSIZEREL "${COMPILER_SHARED_LINKER_FLAGS_MINSIZEREL}" CACHE STRING "")
set(USER_STATIC_LINKER_FLAGS_MINSIZEREL "${COMPILER_STATIC_LINKER_FLAGS_MINSIZEREL}" CACHE STRING "")
# ##############################################################################
# CMAKE  =======================================================================
# Common  ----------------------------------------------------------------------
set(CMAKE_C_FLAGS "${USER_C_FLAGS}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS "${USER_CXX_FLAGS}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS "${USER_EXE_LINKER_FLAGS}" CACHE INTERNAL "")
set(CMAKE_MODULE_LINKER_FLAGS "${USER_MODULE_LINKER_FLAGS}" CACHE INTERNAL "")
set(CMAKE_SHARED_LINKER_FLAGS "${USER_SHARED_LINKER_FLAGS}" CACHE INTERNAL "")
set(CMAKE_STATIC_LINKER_FLAGS "${USER_STATIC_LINKER_FLAGS}" CACHE INTERNAL "")
# Debug  -----------------------------------------------------------------------
set(CMAKE_C_FLAGS_DEBUG "${USER_C_FLAGS_DEBUG}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_DEBUG "${USER_C_CXX_FLAGS_DEBUG} ${USER_CXX_FLAGS_DEBUG}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${USER_EXE_LINKER_FLAGS_DEBUG}" CACHE INTERNAL "")
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${USER_MODULE_LINKER_FLAGS_DEBUG}" CACHE INTERNAL "")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${USER_SHARED_LINKER_FLAGS_DEBUG}" CACHE INTERNAL "")
set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${USER_STATIC_LINKER_FLAGS_DEBUG}" CACHE INTERNAL "")
# Release  -------------------------------------------------------------------
set(CMAKE_C_FLAGS_RELEASE "${USER_C_FLAGS_RELEASE}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_RELEASE "${USER_C_CXX_FLAGS_RELEASE} ${USER_CXX_FLAGS_RELEASE}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${USER_EXE_LINKER_FLAGS_RELEASE}" CACHE INTERNAL "")
set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${USER_MODULE_LINKER_FLAGS_RELEASE}" CACHE INTERNAL "")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${USER_SHARED_LINKER_FLAGS_RELEASE}" CACHE INTERNAL "")
set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${USER_STATIC_LINKER_FLAGS_RELEASE}" CACHE INTERNAL "")
# RelWithDebInfo  --------------------------------------------------------------
set(CMAKE_C_FLAGS_RELWITHDEBINFO "${USER_C_FLAGS_RELWITHDEBINFO}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${USER_CXX_FLAGS_RELWITHDEBINFO}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${USER_EXE_LINKER_FLAGS_RELWITHDEBINFO}" CACHE INTERNAL "")
set(CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO "${USER_MODULE_LINKER_FLAGS_RELWITHDEBINFO}" CACHE INTERNAL "")
set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "${USER_SHARED_LINKER_FLAGS_RELWITHDEBINFO}" CACHE INTERNAL "")
set(CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO "${USER_STATIC_LINKER_FLAGS_RELWITHDEBINFO}" CACHE INTERNAL "")
# MinSizeRel  ------------------------------------------------------------------
set(CMAKE_C_FLAGS_MINSIZEREL "${USER_C_FLAGS_MINSIZEREL}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${USER_CXX_FLAGS_MINSIZEREL}" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${USER_EXE_LINKER_FLAGS_MINSIZEREL}" CACHE INTERNAL "")
set(CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL "${USER_MODULE_LINKER_FLAGS_MINSIZEREL}" CACHE INTERNAL "")
set(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL "${USER_SHARED_LINKER_FLAGS_MINSIZEREL}" CACHE INTERNAL "")
set(CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL "${USER_STATIC_LINKER_FLAGS_MINSIZEREL}" CACHE INTERNAL "")
