/** -*- mode:c; coding:utf-8-unix; -*-
 *  @file config.h.in
 *  @brief config.h.in
 *
 *  config.h.in
 *
 *  Copyright %%YEAR%% %%AUTHOR%%
 *
 *  @author %%AUTHOR%% <%%MAIL_NAME%%@%%MAIL_DOMAIN%%>
 *  @copyright The MIT License (MIT) / Apache License Version 2.0
 *  @since %%TODAY%%
 *  @date %%TODAY%%
 */

#ifndef @SNAPKIT_PACKAGE_UPPER@_CONFIG_H_
#define @SNAPKIT_PACKAGE_UPPER@_CONFIG_H_

#define PACKAGE                 "@SNAPKIT_PACKAGE@"
#define PACKAGE_BUGREPORT       "@SNAPKIT_BUGREPORT@"
#define PACKAGE_NAME            "@SNAPKIT_PACKAGE@"
#define PACKAGE_STRING          "@SNAPKIT_PACKAGE@ @SNAPKIT_VERSION@"
#define PACKAGE_TARNAME         "@SNAPKIT_PACKAGE@"
#define PACKAGE_URL             "@SNAPKIT_URL@"
#define PACKAGE_VERSION         "@SNAPKIT_VERSION@"
#define VERSION                 "@SNAPKIT_VERSION@"

#if @Boost_FOUND@
#  define HAVE_BOOST 1
#else
#  undef HAVE_BOOST
#endif

#endif  /* @SNAPKIT_PACKAGE_UPPER@_CONFIG_H_ */
