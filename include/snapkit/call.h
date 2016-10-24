/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file call.h
 *  @brief call.h
 *
 *  call.h
 *
 *  Copyright 2016 hanepjiv
 *
 *  @author hanepjiv <hanepjiv@gmail.com>
 *  @copyright The MIT License (MIT)
 *  @since 2016/01/09
 *  @date 2016/05/11
 */

#ifndef SNAPKIT_CALL_H_
#define SNAPKIT_CALL_H_

/* ######################################################################### */
/* ========================================================================= */
#ifndef CALL_CDECL
# if defined(_WINDOWS) && !defined(__GNUC__)
#  define CALL_CDECL __cdecl
# else
#  define CALL_CDECL
# endif
#endif  /* CALL_CDECL */

#endif  /* SNAPKIT_CALL_H_ */
