#include "textbox.h"
#include <iostream>

namespace roco
{

box_res::box_res()
    : v(good)
{}

box_res::box_res(e __v)
    : v(__v)
{}

bool box_res::operator!() const noexcept
{
    return v;
}

box_res::operator bool() const noexcept
{
    return !v;
}

void textboxin(pos_t __p, std::string& __s)
{
    pol::console.locate(__p.y, __p.x);
    pol::console.show_cursor();
    std::cin >> __s;
    pol::console.hide_cursor();
}

box_res textboxin_ex(pos_t __p, std::string& __s)
{
    __s.clear();
    pol::console.locate(__p.y, __p.x);
    pol::console.show_cursor();

    getch_b();
    char __ch = 0;

    while (__ch = getch_f())
    {
        if (__ch == '\n') break;
        if (__ch == 127)
        {
            if (!__s.empty())
            {
                __s.pop_back();
                std::cout << '\b';
                std::cout.flush();
                pol::console.clear_line_after();
            }
            continue;
        }
        if (__ch == 2)
        {
            getch_e();
            pol::console.hide_cursor();
            return box_res(box_res::interrupt);
        }
        __s += __ch;
        std::cout << __ch;
    }

    getch_e();
    pol::console.hide_cursor();
    return box_res(box_res::good);
}

void textboxout(pos_t __p, const std::string& __s)
{
    pol::console.locate(__p.y, __p.x);
    std::cout << __s;
}

void numboxin(pos_t __p, unsigned& __n)
{
    std::string __tmp;
    textboxin(__p, __tmp);
    __n = stoi_ex(__tmp);
}

box_res numboxin_ex(pos_t __p, unsigned& __n)
{
    std::string __tmp;
    box_res __res = textboxin_ex(__p, __tmp);
    __n = stoi_ex(__tmp);
    return __res;
}

void numboxout(pos_t __p, const unsigned& __n)
{
    pol::console.locate(__p.y, __p.x);
    std::cout << __n;
}

void pwdboxin(pos_t __p, std::string& __s)
{
    __s.clear();
    pol::console.locate(__p.y, __p.x);
    pol::console.show_cursor();
    getch_b();
    char __ch;
    bool __echo = false;

    while (__ch = getch_f())
    {
        if (__ch == 127)
        {
            if (!__s.empty())
            {
                __s.pop_back();
                std::cout << '\b';
                std::cout.flush();
                pol::console.clear_line_after();
            }
            continue;
        }
        if (__ch == 5)
        {
            if (__echo)
            {
                __echo = false;
                pol::console.locate(__p.y, __p.x);
                std::cout << std::string(__s.size(), '*');
            }
            else
            {
                __echo = true;
                pol::console.locate(__p.y, __p.x);
                std::cout << __s;
            }
            std::cout.flush();
            continue;
        }
        if (__ch == '\n') break;
        __s += __ch;
        if (__echo) std::cout << __ch;
        else std::cout << '*';
        std::cout.flush();
    }

    getch_e();
    pol::console.hide_cursor();
}

void pwdboxout(pos_t __p, const std::string& __s)
{
    pol::console.locate(__p.y, __p.x);
    getch_b();
    char __ch;
    bool __echo = false;
    std::cout << __s;

    while (__ch = getch_f())
    {
        if (__ch == 5)
        {
            if (__echo)
            {
                __echo = false;
                pol::console.locate(__p.y, __p.x);
                std::cout << std::string(__s.size(), '*');
            }
            else
            {
                __echo = true;
                pol::console.locate(__p.y, __p.x);
                std::cout << __s;
            }
            std::cout.flush();
            continue;
        }
        if (__ch == '\n') break;
    }

    getch_e();
}

}
