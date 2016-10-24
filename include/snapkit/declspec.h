/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file declspec.h
 *  @brief declspec.h
 *
 *  declspec.h
 *
 *  Copyright 2016 hanepjiv
 *
 *  @author hanepjiv <hanepjiv@gmail.com>
 *  @copyright The MIT License (MIT)
 *  @since 2016/01/09
 *  @date 2016/05/11
 */

#ifndef SNAPKIT_DECLSPEC_H_
#define SNAPKIT_DECLSPEC_H_

/* ######################################################################### */
/* ========================================================================= */
#if defined(__GNUC__)
# if __GNUC__ >= 4
#  define DECLSPEC_EXPORTS __attribute__ ((visibility("default")))
#  define DECLSPEC_IMPORTS
# elif __GNUC__ >= 2
#  define DECLSPEC_EXPORTS __declspec(dllexport)
#  define DECLSPEC_IMPORTS
# endif
#elif defined(_WINDOWS)
#  define DECLSPEC_EXPORTS __declspec(dllexport)
#  define DECLSPEC_IMPORTS __declspec(dllimport)
#else
# define DECLSPEC_EXPORTS
# define DECLSPEC_IMPORTS
#endif

#endif  /* SNAPKIT_DECLSPEC_H_ */
