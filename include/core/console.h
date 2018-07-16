// Console support for linux-like system -*- C++ -*-

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

/** @file console
 *  This is a Polaris C++ Library header.
 */

// Written by Jingyu Zhao.

#ifndef _POL_CONSOLE_H
#define _POL_CONSOLE_H 1

#include "version.h"

#if __linux__ || __CYGWIN__

#include <string>
#include <iostream>

namespace polaris
{

class console_t
{
    std::string _M_data;

    void _M_do() const;

public:
    console_t();
    ~console_t() noexcept;

    void clear();
    void purge();
    void highlight();
    void underline();
    void coruscate();
    void reverse_display();
    void blank();
    void clear_screen();
    void foreground_color(int __x);
    void background_color(int __x);
    void locate(int __x, int __y);
    void clear_line_after();
    void save_cursor();
    void recover_cursor();
    void show_cursor();
    void hide_cursor();
};

extern console_t console;

}

#else
#error unsupported system
#endif

#endif /* _POL_CONSOLE_H */
