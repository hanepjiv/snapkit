/** -*- coding:utf-8; -*-
 *  @file debug.h
 *  @brief debug.h
 *
 *  debug.h
 *
 *  Copyright 2016 hanepjiv
 *
 *  @author hanepjiv <hanepjiv@gmail.com>
 *  @since 2016/01/09
 *  @date 2016/01/10
 */


/* ########################################################################## */
/*
  The MIT License (MIT)

  Copyright (c) <2016> hanepjiv <hanepjiv@gmail.com>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/


#ifndef SNAPKIT_DEBUG_H_
#define SNAPKIT_DEBUG_H_


/* ////////////////////////////////////////////////////////////////////////// */
/* ========================================================================== */
#if (defined(DEBUG) && !defined(SNAPKIT_DEBUG))
# define SNAPKIT_DEBUG
#endif
/* ========================================================================== */
#if (defined(NDEBUG) && defined(SNAPKIT_DEBUG))
# undef SNAPKIT_DEBUG
#endif
/* ========================================================================== */
#define SNAPKIT_VERBOSITY_00              (0x00)
#define SNAPKIT_VERBOSITY_01              (0x3F)
#define SNAPKIT_VERBOSITY_02              (0x7F)
#define SNAPKIT_VERBOSITY_03              (0xBF)
#define SNAPKIT_VERBOSITY_04              (0xFF)
/* -------------------------------------------------------------------------- */
#define SNAPKIT_VERBOSITY_DEBUG           SNAPKIT_VERBOSITY_00
#define SNAPKIT_VERBOSITY_INFO            SNAPKIT_VERBOSITY_01
#define SNAPKIT_VERBOSITY_WARNING         SNAPKIT_VERBOSITY_02
#define SNAPKIT_VERBOSITY_ERROR           SNAPKIT_VERBOSITY_03
#define SNAPKIT_VERBOSITY_CRITICAL        SNAPKIT_VERBOSITY_04
/* -------------------------------------------------------------------------- */
#define SNAPKIT_VERBOSITY_ALL             SNAPKIT_VERBOSITY_DEBUG
#define SNAPKIT_VERBOSITY_DEFAULT         SNAPKIT_VERBOSITY_WARNING
#define SNAPKIT_VERBOSITY_QUIET           SNAPKIT_VERBOSITY_CRITICAL
    /* ////////////////////////////////////////////////////////////////////////// */
#ifdef SNAPKIT_DEBUG
/* -------------------------------------------------------------------------- */
# if !defined(SNAPKIT_VERBOSITY)
#   define SNAPKIT_VERBOSITY              SNAPKIT_VERBOSITY_DEFAULT
# endif
/* ========================================================================== */
# ifdef __cplusplus
#   include <cstdio>
#   include <cstdlib>
#   include <cstdarg>
#   define SNAPKIT_USING_NAMESPACE_STD using namespace std
# else  /* !__cplusplus */
#   include <stdio.h>
#   include <stdlib.h>
#   include <stdarg.h>
#   define SNAPKIT_USING_NAMESPACE_STD
# endif  /* !__cplusplus */
/* ========================================================================== */
# define SNAPKIT_TRACE__(d)                                     \
  do {                                                          \
    SNAPKIT_USING_NAMESPACE_STD;                                \
    fprintf(stderr, "%s(%i) : " d "\n", __FILE__, __LINE__);    \
    (void)fflush(stderr);                                       \
  } while (0)
# define SNAPKIT_TRACE_(d) SNAPKIT_TRACE__(d)
# define SNAPKIT_TRACE(d) SNAPKIT_TRACE_(d)
/* -------------------------------------------------------------------------- */
# define SNAPKIT_TRACE_VERBOSITY__(l, d)                                \
  do { if (SNAPKIT_VERBOSITY <= (l)) { SNAPKIT_TRACE(d); } } while (0)
# define SNAPKIT_TRACE_VERBOSITY_(l, d) SNAPKIT_TRACE_VERBOSITY__(l, d)
# define SNAPKIT_TRACE_VERBOSITY(l, d) SNAPKIT_TRACE_VERBOSITY_(l, d)
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_DEBUG)
#   define SNAPKIT_TRACE_DEBUG__(d) SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_DEBUG_(d) SNAPKIT_TRACE_DEBUG__(d)
#   define SNAPKIT_TRACE_DEBUG(d) SNAPKIT_TRACE_DEBUG_(d)
# else
#   define SNAPKIT_TRACE_DEBUG(d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_INFO)
#   define SNAPKIT_TRACE_INFO__(d) SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_INFO_(d) SNAPKIT_TRACE_INFO__(d)
#   define SNAPKIT_TRACE_INFO(d) SNAPKIT_TRACE_INFO_(d)
# else
#   define SNAPKIT_TRACE_INFO(d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_WARNING)
#   define SNAPKIT_TRACE_WARNING__(d) SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_WARNING_(d) SNAPKIT_TRACE_WARNING__(d)
#   define SNAPKIT_TRACE_WARNING(d) SNAPKIT_TRACE_WARNING_(d)
# else
#   define SNAPKIT_TRACE_WARNING(d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_ERROR)
#   define SNAPKIT_TRACE_ERROR__(d) SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_ERROR_(d) SNAPKIT_TRACE_ERROR__(d)
#   define SNAPKIT_TRACE_ERROR(d) SNAPKIT_TRACE_ERROR_(d)
# else
#   define SNAPKIT_TRACE_ERROR(d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_CRITICAL)
#   define SNAPKIT_TRACE_CRITICAL__(d) SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_CRITICAL_(d) SNAPKIT_TRACE_CRITICAL__(d)
#   define SNAPKIT_TRACE_CRITICAL(d) SNAPKIT_TRACE_CRITICAL_(d)
# else
#   define SNAPKIT_TRACE_CRITICAL(d) (void)(0)
# endif
/* ========================================================================== */
# if ((defined(__cplusplus) && (__cplusplus >= 201103L)) ||             \
      (defined(__STDC__) &&                                             \
       defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)))
#   define SNAPKIT_TRACEF__(fmt, ...)                   \
  do {                                                  \
    SNAPKIT_USING_NAMESPACE_STD;                        \
    fprintf(stderr, "%s(%i) %s : " fmt "\n",            \
            __FILE__, __LINE__, __func__, __VA_ARGS__); \
    (void)fflush(stderr);                               \
  } while (0)
#   define SNAPKIT_TRACEF_(fmt, ...) SNAPKIT_TRACEF__(fmt, __VA_ARGS__)
#   define SNAPKIT_TRACEF(fmt, ...) SNAPKIT_TRACEF_(fmt, __VA_ARGS__)
/* -------------------------------------------------------------------------- */
#   define SNAPKIT_TRACEF_VERBOSITY__(l, fmt, ...)                      \
  do {                                                                  \
    if (SNAPKIT_VERBOSITY <= (l)) { SNAPKIT_TRACEF(fmt, __VA_ARGS__); } \
  } while (0)
#   define SNAPKIT_TRACEF_VERBOSITY_(l, fmt, ...)       \
  SNAPKIT_TRACEF_VERBOSITY__(l, fmt, __VA_ARGS__)
#   define SNAPKIT_TRACEF_VERBOSITY(l, fmt, ...)        \
  SNAPKIT_TRACEF_VERBOSITY_(l, fmt, __VA_ARGS__)
/* -------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_DEBUG)
#     define SNAPKIT_TRACEF_DEBUG__(fmt, ...)   \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_DEBUG_(fmt, ...)    \
  SNAPKIT_TRACEF_DEBUG__(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_DEBUG(fmt, ...)     \
  SNAPKIT_TRACEF_DEBUG_(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_DEBUG(fmt, ...) (void)(0)
#   endif
/* -------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_INFO)
#     define SNAPKIT_TRACEF_INFO__(fmt, ...)    \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_INFO_(fmt, ...)     \
    SNAPKIT_TRACEF_INFO__(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_INFO(fmt, ...)      \
  SNAPKIT_TRACEF_INFO_(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_INFO(fmt, ...) (void)(0)
#   endif
/* -------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_WARNING)
#     define SNAPKIT_TRACEF_WARNING__(fmt, ...) \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_WARNING_(fmt, ...)  \
    SNAPKIT_TRACEF_WARNING__(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_WARNING(fmt, ...)   \
  SNAPKIT_TRACEF_WARNING_(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_WARNING(fmt, ...) (void)(0)
#   endif
/* -------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_ERROR)
#     define SNAPKIT_TRACEF_ERROR__(fmt, ...)   \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_ERROR_(fmt, ...)    \
  SNAPKIT_TRACEF_ERROR__(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_ERROR(fmt, ...)     \
  SNAPKIT_TRACEF_ERROR_(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_ERROR(fmt, ...) (void)(0)
#   endif
/* -------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                           \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_CRITICAL)
#     define SNAPKIT_TRACEF_CRITICAL__(fmt, ...)        \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_CRITICAL_(fmt, ...) \
  SNAPKIT_TRACEF_CRITICAL__(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_CRITICAL(fmt, ...)  \
  SNAPKIT_TRACEF_CRITICAL_(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_CRITICAL(fmt, ...) (void)(0)
#   endif
# endif  /* defined(__STDC__) && ... */
/* ========================================================================== */
# define SNAPKIT_ASSERT__(c, t, d)              \
  do { if (!(c)) {                              \
      SNAPKIT_USING_NAMESPACE_STD;              \
      SNAPKIT_TRACE_CRITICAL(t ": " d);         \
      abort();                                  \
    }                                           \
  } while (0)
# define SNAPKIT_ASSERT_(c, t, d) SNAPKIT_ASSERT__(c, t, d)
# define SNAPKIT_ASSERT(c, d) SNAPKIT_ASSERT_(c, #c, d)
/* -------------------------------------------------------------------------- */
# define SNAPKIT_ASSERT_VERBOSITY__(l, c, d)                            \
    do { if (SNAPKIT_VERBOSITY <= (l)) { SNAPKIT_ASSERT(c, d); } } while (0)
# define SNAPKIT_ASSERT_VERBOSITY_(l, c, d)     \
  SNAPKIT_ASSERT_VERBOSITY__(l, c, d)
# define SNAPKIT_ASSERT_VERBOSITY(l, c, d)      \
  SNAPKIT_ASSERT_VERBOSITY_(l, c, d)
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_DEBUG)
#   define SNAPKIT_ASSERT_DEBUG__(c, d) SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_DEBUG_(c, d) SNAPKIT_ASSERT_DEBUG__(c, d)
#   define SNAPKIT_ASSERT_DEBUG(c, d) SNAPKIT_ASSERT_DEBUG_(c, d)
# else
#   define SNAPKIT_ASSERT_DEBUG(c, d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_INFO)
#   define SNAPKIT_ASSERT_INFO__(c, d) SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_INFO_(c, d) SNAPKIT_ASSERT_INFO__(c, d)
#   define SNAPKIT_ASSERT_INFO(c, d) SNAPKIT_ASSERT_INFO_(c, d)
# else
#   define SNAPKIT_ASSERT_INFO(c, d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_WARNING)
#   define SNAPKIT_ASSERT_WARNING__(c, d) SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_WARNING_(c, d) SNAPKIT_ASSERT_WARNING__(c, d)
#   define SNAPKIT_ASSERT_WARNING(c, d) SNAPKIT_ASSERT_WARNING_(c, d)
# else
#   define SNAPKIT_ASSERT_WARNING(c, d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_ERROR)
#   define SNAPKIT_ASSERT_ERROR__(c, d) SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_ERROR_(c, d) SNAPKIT_ASSERT_ERROR__(c, d)
#   define SNAPKIT_ASSERT_ERROR(c, d) SNAPKIT_ASSERT_ERROR_(c, d)
# else
#   define SNAPKIT_ASSERT_ERROR(c, d) (void)(0)
# endif
/* -------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_CRITICAL)
#   define SNAPKIT_ASSERT_CRITICAL__(c, d) SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_CRITICAL_(c, d) SNAPKIT_ASSERT_CRITICAL__(c, d)
#   define SNAPKIT_ASSERT_CRITICAL(c, d) SNAPKIT_ASSERT_CRITICAL_(c, d)
# else
#   define SNAPKIT_ASSERT_CRITICAL(c, d) (void)(0)
# endif
#else  /* SNAPKIT_DEBUG  //////////////////////////////////////////////////// */
/* ========================================================================== */
# define SNAPKIT_TRACE(d) (void)(0)
# define SNAPKIT_TRACE_VERBOSITY(l, d) (void)(0)
# define SNAPKIT_TRACE_DEBUG(d) (void)(0)
# define SNAPKIT_TRACE_INFO(d) (void)(0)
# define SNAPKIT_TRACE_WARNING(d) (void)(0)
# define SNAPKIT_TRACE_ERROR(d) (void)(0)
# define SNAPKIT_TRACE_CRITICAL(d) (void)(0)
/* ========================================================================== */
# if ((defined(__cplusplus) && (__cplusplus >= 201103L)) ||             \
      (defined(__STDC__) &&                                             \
       defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)))
#   define SNAPKIT_TRACEF(fmt, ...) (void)(0)
#   define SNAPKIT_TRACEF_VERBOSITY(l, fmt, ...) (void)(0)
#   define SNAPKIT_TRACEF_DEBUG(fmt, ...) (void)(0)
#   define SNAPKIT_TRACEF_INFO(fmt, ...) (void)(0)
#   define SNAPKIT_TRACEF_WARNING(fmt, ...) (void)(0)
#   define SNAPKIT_TRACEF_ERROR(fmt, ...) (void)(0)
#   define SNAPKIT_TRACEF_CRITICAL(fmt, ...) (void)(0)
# endif  /* defined(__STDC__) && ... */
/* ========================================================================== */
# define SNAPKIT_ASSERT(c, d) (void)(0)
# define SNAPKIT_ASSERT_VERBOSITY(l, c, d) (void)(0)
# define SNAPKIT_ASSERT_DEBUG(c, d) (void)(0)
# define SNAPKIT_ASSERT_INFO(c, d) (void)(0)
# define SNAPKIT_ASSERT_WARNING(c, d) (void)(0)
# define SNAPKIT_ASSERT_ERROR(c, d) (void)(0)
# define SNAPKIT_ASSERT_CRITICAL(c, d) (void)(0)
#endif  /* SNAPKIT_DEBUG  /////////////////////////////////////////////////// */


#endif  /* SNAPKIT_DEBUG_H_ */