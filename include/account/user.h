#ifndef _ROCO_USER_H
#define _ROCO_USER_H 1

#include "account.h"

namespace roco
{

class user;

std::ostream& operator << (std::ostream& __out, const user& __x);

class user
{
    std::size_t _M_id;
    std::string _M_name;

public:
    user();

    bool login(const account& __a);
    bool logout(const account& __a);

    bool reg(const account& __a);

    friend std::ostream& operator << (std::ostream& __out, const user& __x);
};

}

#endif
