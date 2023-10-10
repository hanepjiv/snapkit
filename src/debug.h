/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file debug.h
 *  @brief debug.h
 *
 *  debug.h
 *
 *  Copyright %%YEAR%% %%AUTHOR%%
 *
 *  @author %%AUTHOR%% <%%MAIL_NAME%%@%%MAIL_DOMAIN%%>
 *  @copyright The MIT License (MIT) / Apache License Version 2.0
 *  @since %%TODAY%%
 *  @date 2023/10/10
 */

#ifndef SNAPKIT_DEBUG_H_
#define SNAPKIT_DEBUG_H_

/* ///////////////////////////////////////////////////////////////////////// */
/* ========================================================================= */
#define SNAPKIT_VERBOSITY_DEBUG                 (0x00)
#define SNAPKIT_VERBOSITY_INFO                  (0x3F)
#define SNAPKIT_VERBOSITY_WARNING               (0x7F)
#define SNAPKIT_VERBOSITY_ERROR                 (0xBF)
#define SNAPKIT_VERBOSITY_CRITICAL              (0xFF)
/* ------------------------------------------------------------------------- */
#define SNAPKIT_VERBOSITY_ALL                   SNAPKIT_VERBOSITY_DEBUG
#define SNAPKIT_VERBOSITY_DEFAULT               SNAPKIT_VERBOSITY_INFO
#define SNAPKIT_VERBOSITY_QUIET                 SNAPKIT_VERBOSITY_CRITICAL
/* ------------------------------------------------------------------------- */
#if !defined(SNAPKIT_VERBOSITY)
# define SNAPKIT_VERBOSITY                      SNAPKIT_VERBOSITY_DEFAULT
#endif
/* ///////////////////////////////////////////////////////////////////////// */
/* ========================================================================= */
#ifdef __cplusplus
# include <cstdio>
# include <cstdlib>
# include <cstdarg>
# define SNAPKIT_USING_NAMESPACE_STD using namespace std
#else  /* !__cplusplus */
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# define SNAPKIT_USING_NAMESPACE_STD
#endif  /* !__cplusplus */
/* ========================================================================= */
#define SNAPKIT_TRACE_ALWAYS_II(d, line)                                        \
  do {                                                                  \
    SNAPKIT_USING_NAMESPACE_STD;                                        \
    (void) fputs(PACKAGE_STRING ": " __FILE__ "(" #line "): " d "\n",   \
                 stderr);                                               \
    (void) fflush(stderr);                                              \
  } while (0)
#define SNAPKIT_TRACE_ALWAYS_I(d, line) SNAPKIT_TRACE_ALWAYS_II(d, line)
#define SNAPKIT_TRACE_ALWAYS(d)         SNAPKIT_TRACE_ALWAYS_I(d, __LINE__)
/* ========================================================================= */
#if ((defined(__cplusplus) && (__cplusplus >= 201103L)) ||              \
     (defined(__STDC__) &&                                              \
      defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)))
# define SNAPKIT_TRACEF_ALWAYS_II(line, fmt, ...)                       \
  do {                                                                  \
    SNAPKIT_USING_NAMESPACE_STD;                                        \
    fprintf(stderr, __FILE__ "(" #line ") %s: " fmt "\n", __func__,     \
            __VA_ARGS__);                                               \
    (void) fflush(stderr);                                              \
  } while (0)
# define SNAPKIT_TRACEF_ALWAYS_I(line, fmt, ...)                \
  SNAPKIT_TRACEF_ALWAYS_II(line, fmt, __VA_ARGS__)
# define SNAPKIT_TRACEF_ALWAYS(fmt, ...)                \
  SNAPKIT_TRACEF_ALWAYS_I(__LINE__, fmt, __VA_ARGS__)
#endif  /* defined(__STDC__) && ... */
/* ========================================================================= */
#define SNAPKIT_ASSERT_ALWAYS_II(c, t, d)       \
  do { if (!(c)) {                              \
      SNAPKIT_TRACE_ALWAYS(t ": " d);           \
      abort();                                  \
    }                                           \
  } while (0)
#define SNAPKIT_ASSERT_ALWAYS_I(c, t, d)               SNAPKIT_ASSERT_ALWAYS_II(c,t,d)
#define SNAPKIT_ASSERT_ALWAYS(c, d)            SNAPKIT_ASSERT_ALWAYS_I(c,#c,d)
/* ///////////////////////////////////////////////////////////////////////// */
/* ========================================================================= */
#if (defined(DEBUG) && !defined(SNAPKIT_DEBUG))
# define SNAPKIT_DEBUG
#endif
/* ========================================================================= */
#if (defined(NDEBUG) && defined(SNAPKIT_DEBUG))
# undef SNAPKIT_DEBUG
#endif
/* ///////////////////////////////////////////////////////////////////////// */
/* ========================================================================= */
#ifdef SNAPKIT_DEBUG
/* ========================================================================= */
# define SNAPKIT_TRACE(d)                       SNAPKIT_TRACE_ALWAYS(d)
/* ------------------------------------------------------------------------- */
# define SNAPKIT_TRACE_VERBOSITY_II(l, d)                               \
  do { if (SNAPKIT_VERBOSITY <= (l)) { SNAPKIT_TRACE(d); } } while (0)
# define SNAPKIT_TRACE_VERBOSITY_I(l, d)                SNAPKIT_TRACE_VERBOSITY_II(l, d)
# define SNAPKIT_TRACE_VERBOSITY(l, d)          SNAPKIT_TRACE_VERBOSITY_I(l, d)
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_DEBUG)
#   define SNAPKIT_TRACE_DEBUG_II(d)            SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_DEBUG_I(d)             SNAPKIT_TRACE_DEBUG_II(d)
#   define SNAPKIT_TRACE_DEBUG(d)               SNAPKIT_TRACE_DEBUG_I(d)
# else
#   define SNAPKIT_TRACE_DEBUG(d)               ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_INFO)
#   define SNAPKIT_TRACE_INFO_II(d)             SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_INFO_I(d)              SNAPKIT_TRACE_INFO_II(d)
#   define SNAPKIT_TRACE_INFO(d)                SNAPKIT_TRACE_INFO_I(d)
# else
#   define SNAPKIT_TRACE_INFO(d)                ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_WARNING)
#   define SNAPKIT_TRACE_WARNING_II(d)          SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_WARNING_I(d)           SNAPKIT_TRACE_WARNING_II(d)
#   define SNAPKIT_TRACE_WARNING(d)             SNAPKIT_TRACE_WARNING_I(d)
# else
#   define SNAPKIT_TRACE_WARNING(d)             ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_ERROR)
#   define SNAPKIT_TRACE_ERROR_II(d)            SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_ERROR_I(d)             SNAPKIT_TRACE_ERROR_II(d)
#   define SNAPKIT_TRACE_ERROR(d)               SNAPKIT_TRACE_ERROR_I(d)
# else
#   define SNAPKIT_TRACE_ERROR(d)               ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_CRITICAL)
#   define SNAPKIT_TRACE_CRITICAL_II(d)         SNAPKIT_TRACE(d)
#   define SNAPKIT_TRACE_CRITICAL_I(d)          SNAPKIT_TRACE_CRITICAL_II(d)
#   define SNAPKIT_TRACE_CRITICAL(d)            SNAPKIT_TRACE_CRITICAL_I(d)
# else
#   define SNAPKIT_TRACE_CRITICAL(d)            ((void)(0))
# endif
/* ========================================================================= */
# if ((defined(__cplusplus) && (__cplusplus >= 201103L)) ||             \
      (defined(__STDC__) &&                                             \
       defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)))
#   define SNAPKIT_TRACEF(fmt, ...) SNAPKIT_TRACEF_ALWAYS_I(fmt, __VA_ARGS__)
/* ------------------------------------------------------------------------- */
#   define SNAPKIT_TRACEF_VERBOSITY_II(l, fmt, ...)                     \
  do {                                                                  \
    if (SNAPKIT_VERBOSITY <= (l)) { SNAPKIT_TRACEF(fmt, __VA_ARGS__); } \
  } while (0)
#   define SNAPKIT_TRACEF_VERBOSITY_I(l, fmt, ...)      \
  SNAPKIT_TRACEF_VERBOSITY_II(l, fmt, __VA_ARGS__)
#   define SNAPKIT_TRACEF_VERBOSITY(l, fmt, ...)        \
  SNAPKIT_TRACEF_VERBOSITY_I(l, fmt, __VA_ARGS__)
/* ------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_DEBUG)
#     define SNAPKIT_TRACEF_DEBUG_II(fmt, ...)  \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_DEBUG_I(fmt, ...)   \
  SNAPKIT_TRACEF_DEBUG_II(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_DEBUG(fmt, ...)     \
    SNAPKIT_TRACEF_DEBUG_I(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_DEBUG(fmt, ...)     ((void)(0))
#   endif
/* ------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_INFO)
#     define SNAPKIT_TRACEF_INFO_II(fmt, ...)   \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_INFO_I(fmt, ...)    \
  SNAPKIT_TRACEF_INFO_II(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_INFO(fmt, ...)      \
  SNAPKIT_TRACEF_INFO_I(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_INFO(fmt, ...)      ((void)(0))
#   endif
/* ------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_WARNING)
#     define SNAPKIT_TRACEF_WARNING_II(fmt, ...) \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_WARNING_I(fmt, ...) \
  SNAPKIT_TRACEF_WARNING_II(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_WARNING(fmt, ...)   \
  SNAPKIT_TRACEF_WARNING_I(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_WARNING(fmt, ...)   ((void)(0))
#   endif
/* ------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                   \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_ERROR)
#     define SNAPKIT_TRACEF_ERROR_II(fmt, ...)  \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_ERROR_I(fmt, ...)   \
  SNAPKIT_TRACEF_ERROR_II(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_ERROR(fmt, ...)     \
  SNAPKIT_TRACEF_ERROR_I(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_ERROR(fmt, ...)     ((void)(0))
#   endif
/* ------------------------------------------------------------------------- */
#   if (defined(SNAPKIT_VERBOSITY) &&                           \
        SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_CRITICAL)
#     define SNAPKIT_TRACEF_CRITICAL_II(fmt, ...)       \
  SNAPKIT_TRACEF(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_CRITICAL_I(fmt, ...) \
  SNAPKIT_TRACEF_CRITICAL_II(fmt, __VA_ARGS__)
#     define SNAPKIT_TRACEF_CRITICAL(fmt, ...)  \
  SNAPKIT_TRACEF_CRITICAL_I(fmt, __VA_ARGS__)
#   else
#     define SNAPKIT_TRACEF_CRITICAL(fmt, ...) ((void)(0))
#   endif
# endif  /* defined(__STDC__) && ... */
/* ========================================================================= */
# define SNAPKIT_ASSERT(c, d)                   SNAPKIT_ASSERT_ALWAYS(c, d)
/* ------------------------------------------------------------------------- */
# define SNAPKIT_ASSERT_VERBOSITY_II(l, c, d)                           \
  do { if (SNAPKIT_VERBOSITY <= (l)) { SNAPKIT_ASSERT(c, d); } } while (0)
# define SNAPKIT_ASSERT_VERBOSITY_I(l, c, d)    \
    SNAPKIT_ASSERT_VERBOSITY_II(l, c, d)
# define SNAPKIT_ASSERT_VERBOSITY(l, c, d)      \
  SNAPKIT_ASSERT_VERBOSITY_I(l, c, d)
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_DEBUG)
#   define SNAPKIT_ASSERT_DEBUG_II(c, d)                SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_DEBUG_I(c, d)         SNAPKIT_ASSERT_DEBUG_II(c, d)
#   define SNAPKIT_ASSERT_DEBUG(c, d)           SNAPKIT_ASSERT_DEBUG_I(c, d)
# else
#   define SNAPKIT_ASSERT_DEBUG(c, d)           ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_INFO)
#   define SNAPKIT_ASSERT_INFO_II(c, d)         SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_INFO_I(c, d)          SNAPKIT_ASSERT_INFO_II(c, d)
#   define SNAPKIT_ASSERT_INFO(c, d)            SNAPKIT_ASSERT_INFO_I(c, d)
# else
#   define SNAPKIT_ASSERT_INFO(c, d)            ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_WARNING)
#   define SNAPKIT_ASSERT_WARNING_II(c, d)      SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_WARNING_I(c, d)       SNAPKIT_ASSERT_WARNING_II(c, d)
#   define SNAPKIT_ASSERT_WARNING(c, d)         SNAPKIT_ASSERT_WARNING_I(c, d)
# else
#   define SNAPKIT_ASSERT_WARNING(c, d)         ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_ERROR)
#   define SNAPKIT_ASSERT_ERROR_II(c, d)                SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_ERROR_I(c, d)         SNAPKIT_ASSERT_ERROR_II(c, d)
#   define SNAPKIT_ASSERT_ERROR(c, d)           SNAPKIT_ASSERT_ERROR_I(c, d)
# else
#   define SNAPKIT_ASSERT_ERROR(c, d)           ((void)(0))
# endif
/* ------------------------------------------------------------------------- */
# if (defined(SNAPKIT_VERBOSITY) &&                     \
      SNAPKIT_VERBOSITY <= SNAPKIT_VERBOSITY_CRITICAL)
#   define SNAPKIT_ASSERT_CRITICAL_II(c, d)     SNAPKIT_ASSERT(c, d)
#   define SNAPKIT_ASSERT_CRITICAL_I(c, d)      SNAPKIT_ASSERT_CRITICAL_II(c, d)
#   define SNAPKIT_ASSERT_CRITICAL(c, d)        SNAPKIT_ASSERT_CRITICAL_I(c, d)
# else
#   define SNAPKIT_ASSERT_CRITICAL(c, d)        ((void)(0))
# endif
#else  /* SNAPKIT_DEBUG //////////////////////////////////////////////////// */
/* ========================================================================= */
# define SNAPKIT_TRACE(d)                       ((void)(0))
# define SNAPKIT_TRACE_VERBOSITY(l, d)          ((void)(0))
# define SNAPKIT_TRACE_DEBUG(d)                 ((void)(0))
# define SNAPKIT_TRACE_INFO(d)                  ((void)(0))
# define SNAPKIT_TRACE_WARNING(d)               ((void)(0))
# define SNAPKIT_TRACE_ERROR(d)                 ((void)(0))
# define SNAPKIT_TRACE_CRITICAL(d)              ((void)(0))
/* ========================================================================= */
# if ((defined(__cplusplus) && (__cplusplus >= 201103L)) ||             \
      (defined(__STDC__) &&                                             \
       defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)))
#   define SNAPKIT_TRACEF(fmt, ...)             ((void)(0))
#   define SNAPKIT_TRACEF_VERBOSITY(l, fmt, ...) ((void)(0))
#   define SNAPKIT_TRACEF_DEBUG(fmt, ...)       ((void)(0))
#   define SNAPKIT_TRACEF_INFO(fmt, ...)        ((void)(0))
#   define SNAPKIT_TRACEF_WARNING(fmt, ...)     ((void)(0))
#   define SNAPKIT_TRACEF_ERROR(fmt, ...)       ((void)(0))
#   define SNAPKIT_TRACEF_CRITICAL(fmt, ...)    ((void)(0))
# endif  /* defined(__STDC__) && ... */
/* ========================================================================= */
# define SNAPKIT_ASSERT(c, d)                   ((void)(0))
# define SNAPKIT_ASSERT_VERBOSITY(l, c, d)      ((void)(0))
# define SNAPKIT_ASSERT_DEBUG(c, d)             ((void)(0))
# define SNAPKIT_ASSERT_INFO(c, d)              ((void)(0))
# define SNAPKIT_ASSERT_WARNING(c, d)           ((void)(0))
# define SNAPKIT_ASSERT_ERROR(c, d)             ((void)(0))
# define SNAPKIT_ASSERT_CRITICAL(c, d)          ((void)(0))
#endif  /* SNAPKIT_DEBUG /////////////////////////////////////////////////// */

#endif  /* SNAPKIT_DEBUG_H_ */
