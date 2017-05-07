/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file declspec.h
 *  @brief declspec.h
 *
 *  declspec.h
 *
 *  Copyright 2016 hanepjiv
 *
 *  @author hanepjiv <hanepjiv@gmail.com>
 *  @copyright The MIT License (MIT) / Apache License Version 2.0
 *  @since 2016/01/09
 *  @date 2017/05/07
 */

#ifndef SNAPKIT_DECLSPEC_H_
#define SNAPKIT_DECLSPEC_H_

/* ######################################################################### */
/* ========================================================================= */
#if defined(__GNUC__)
# if __GNUC__ >= 4
#  define SNAPKIT_DECLSPEC_EXPORTS __attribute__ ((visibility("default")))
#  define SNAPKIT_DECLSPEC_IMPORTS
# elif __GNUC__ >= 2
#  define SNAPKIT_DECLSPEC_EXPORTS __declspec(dllexport)
#  define SNAPKIT_DECLSPEC_IMPORTS
# endif
#elif defined(_WINDOWS)
#  define SNAPKIT_DECLSPEC_EXPORTS __declspec(dllexport)
#  define SNAPKIT_DECLSPEC_IMPORTS __declspec(dllimport)
#else
# define SNAPKIT_DECLSPEC_EXPORTS
# define SNAPKIT_DECLSPEC_IMPORTS
#endif

#endif  /* SNAPKIT_DECLSPEC_H_ */
