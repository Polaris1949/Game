#ifndef _ROCO_USER_HPP
#define _ROCO_USER_HPP 1

namespace roco
{

class account; // from "account.hpp"
class user;

std::ostream& operator << (std::ostream& __out, const user& __x);

class user
{
    std::size_t _M_id;
    std::string _M_name;

public:
    user();

    friend std::ostream& operator << (std::ostream& __out, const user& __x);

private:
    friend class account;
};

user::user()
    : _M_id(), _M_name()
{}

std::ostream& operator << (std::ostream& __out, const user& __x)
{
    __out << __x._M_id << ": " << __x._M_name;
    return __out;
}

}

#endif
