/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file begin.h
 *  @brief begin.h
 *
 *  begin.h
 *
 *  Copyright %%YEAR%% %%AUTHOR%%
 *
 *  @author %%AUTHOR%% <%%MAIL_NAME%%@%%MAIL_DOMAIN%%>
 *  @copyright The MIT License (MIT) / Apache License Version 2.0
 *  @since %%TODAY%%
 *  @date %%TODAY%%
 */

#ifndef SNAPKIT_BEGIN_H_
#define SNAPKIT_BEGIN_H_

/* ######################################################################### */
/* ========================================================================= */
#include "./call.h"
#ifndef SNAPKIT_CALL
# define SNAPKIT_CALL SNAPKIT_CALL_CDECL
#endif /* SNAPKIT_CALL */
/* ========================================================================= */
#include "./declspec.h"
#ifndef SNAPKIT_DECLSPEC
# if defined(SNAPKIT_EXPORTS)
#  define SNAPKIT_DECLSPEC SNAPKIT_DECLSPEC_EXPORTS
# else
#  define SNAPKIT_DECLSPEC SNAPKIT_DECLSPEC_IMPORTS
# endif
#endif /* SNAPKIT_DECLSPEC */

#endif  /* SNAPKIT_BEGIN_H_ */
