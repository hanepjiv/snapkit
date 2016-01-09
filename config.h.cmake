/** -*- coding:utf-8; mode:c; -*-
 *  @file config.h.in
 *  @brief config.h.in
 *
 *  config.h.in
 *
 *  Copyright 2016 hanepjiv
 *
 *  @author hanepjiv <hagumo@gmail.com>
 *  @since 2016/01/09
 *  @date 2016/01/09
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
