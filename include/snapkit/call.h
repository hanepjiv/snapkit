/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file call.h
 *  @brief call.h
 *
 *  call.h
 *
 *  Copyright %%YEAR%% %%AUTHOR%%
 *
 *  @author %%AUTHOR%% <%%MAIL_NAME%%@%%MAIL_DOMAIN%%>
 *  @copyright The MIT License (MIT) / Apache License Version 2.0
 *  @since %%TODAY%%
 *  @date %%TODAY%%
 */

#ifndef SNAPKIT_CALL_H_
#define SNAPKIT_CALL_H_

/* ######################################################################### */
/* ========================================================================= */
#ifndef SNAPKIT_CALL_CDECL
# if defined(_WINDOWS) && !defined(__GNUC__)
#  define SNAPKIT_CALL_CDECL __cdecl
# else
#  define SNAPKIT_CALL_CDECL
# endif
#endif  /* CALL_CDECL */

#endif  /* SNAPKIT_CALL_H_ */
