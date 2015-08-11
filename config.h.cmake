/** -*- coding:utf-8; mode:c; -*-
 *  @file config.h.in
 *  @brief config.h.in
 *
 *  config.h.in
 *
 *  Copyright 2015 hanepjiv
 *
 *  @author hanepjiv <hagumo@gmail.com>
 *  @since 2015/08/08
 *  @date 2015/08/11
 */


#ifndef @SNAPKIT_PACKAGE_UPPER@_CONFIG_H_
#define @SNAPKIT_PACKAGE_UPPER@_CONFIG_H_

#define PACKAGE                 "@SNAPKIT_PACKAGE@"
#define PACKAGE_BUGREPORT       "@SNAPKIT_BUGREPORT@"
#define PACKAGE_NAME            "@SNAPKIT_PACKAGE@"
#define PACKAGE_STRING          "@SNAPKIT_PACKAGE@ @SNAPKIT_RELEASE@"
#define PACKAGE_TARNAME         "@SNAPKIT_PACKAGE@"
#define PACKAGE_URL             "@SNAPKIT_URL@"
#define PACKAGE_VERSION         "@SNAPKIT_RELEASE@"
#define VERSION                 "@SNAPKIT_RELEASE@"

#if @Boost_FOUND@
#  define HAVE_BOOST 1
#else
#  undef HAVE_BOOST
#endif

#endif  /* @SNAPKIT_PACKAGE_UPPER@_CONFIG_H_ */
