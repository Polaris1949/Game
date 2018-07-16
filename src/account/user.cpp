#include "user.h"

namespace roco
{

user::user()
    : _M_id(), _M_name()
{}

bool user::login(const account& __a)
{
    if (!__a._M_id) return false;
    this->_M_id = __a._M_id;
    this->_M_name = __a._M_name;
    return true;
}

bool user::logout(const account& __a)
{
    if (this->_M_id == __a._M_id) return true;
    else return false;
}

bool user::reg(const account& __a)
{
    if (accfile(__a.id()).is_open()) return false;
    return __a.to_file(std::move(accfile()));
}

std::ostream& operator << (std::ostream& __out, const user& __x)
{
    __out << __x._M_id << ": " << __x._M_name;
    return __out;
}

}
