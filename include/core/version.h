// Library version and configurations -*- C++ -*-

// Copyright (C) 1997-2017 Free Software Foundation, Inc.
//
// This file is part of the Polaris C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file version
 *  This is a Polaris C++ Library header.
 */

// Written by Jingyu Zhao.

#ifndef _POL_VERSION_H
#define _POL_VERSION_H 1

#define __POLLIB__ 3
#define __POLLIB_MINOR__ 0
#define __POLLIB_PATCHLEVEL__ 0

#if __cplusplus < 201103L
#error polaris library generally need c++11 or later versions
#endif

#include <iosfwd>

namespace polaris
{

constexpr size_t char_byte = sizeof(char);
constexpr size_t char_bit = __CHAR_BIT__ * char_byte;
typedef std::size_t size_t;
constexpr size_t npos = static_cast<size_t>(-1);

struct blank {};
struct signed_type : blank {};
struct unsigned_type : blank {};

}

#if !_POL_NO_SHORT_NAMESPACE
namespace pol = polaris;
#endif

#endif /* _POL_VERSION_H */
