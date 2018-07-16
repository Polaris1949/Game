#ifndef _ROCO_TEXTBOX_H
#define _ROCO_TEXTBOX_H 1

#include "pos.h"
#include "console.h"
#include "core.h"
#include <string>

namespace roco
{

struct box_res
{
    enum e : unsigned char
    {good, bad, interrupt};
    e v;

    box_res();
    explicit box_res(e __v);

    bool operator!() const noexcept;
    explicit operator bool() const noexcept;
};

void textboxin(pos_t __p, std::string& __s);
box_res textboxin_ex(pos_t __p, std::string& __s);
void textboxout(pos_t __p, const std::string& __s);
void numboxin(pos_t __p, unsigned& __n);
box_res numboxin_ex(pos_t __p, unsigned& __n);
void numboxout(pos_t __p, const unsigned& __n);
void pwdboxin(pos_t __p, std::string& __s);
void pwdboxout(pos_t __p, const std::string& __s);

}

#endif
