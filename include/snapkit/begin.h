/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file begin.h
 *  @brief begin.h
 *
 *  begin.h
 *
 *  Copyright 2016 hanepjiv
 *
 *  @author hanepjiv <hanepjiv@gmail.com>
 *  @copyright The MIT License (MIT)
 *  @since 2016/01/09
 *  @date 2016/05/11
 */

#ifndef SNAPKIT_BEGIN_H_
#define SNAPKIT_BEGIN_H_

/* ######################################################################### */
/* ========================================================================= */
#include "./call.h"
#ifndef SNAPKIT_CALL
# define SNAPKIT_CALL CALL_CDECL
#endif /* SNAPKIT_CALL */
/* ========================================================================= */
#include "./declspec.h"
#ifndef SNAPKIT_DECLSPEC
# if defined(SNAPKIT_EXPORTS)
#  define SNAPKIT_DECLSPEC DECLSPEC_EXPORTS
# else
#  define SNAPKIT_DECLSPEC DECLSPEC_IMPORTS
# endif
#endif /* SNAPKIT_DECLSPEC */

#endif  /* SNAPKIT_BEGIN_H_ */
