/** -*- coding:utf-8-unix; -*-
 *  @file declspec.h
 *  @brief declspec.h
 *
 *  declspec.h
 *
 *  Copyright 2016 hanepjiv
 *
 *  @author hanepjiv <hanepjiv@gmail.com>
 *  @since 2016/01/09
 *  @date 2016/01/09
 */

/* ########################################################################## */
/*
  The MIT License (MIT)

  Copyright (c) <2016> hanepjiv <hanepjiv@gmail.com>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef SNAPKIT_DECLSPEC_H_
#define SNAPKIT_DECLSPEC_H_

/* ########################################################################## */
/* ========================================================================== */
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
