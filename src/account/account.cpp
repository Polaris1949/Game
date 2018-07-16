#include "account.h"
#include <utility>

namespace roco
{

account::account()
    : _M_id(), _M_name(), _M_pwd()
{}

account::account(std::size_t __id)
    : _M_id(__id), _M_name(), _M_pwd()
{
    this->from_file(std::move(accfile(__id)));
}

account::account(std::size_t __id, const std::string& __name, \
    const std::string& __pwd)
    : _M_id(__id), _M_name(__name), _M_pwd(__pwd)
{}

std::size_t account::id() const
{
    return this->_M_id;
}

std::string account::name() const
{
    return this->_M_name;
}

std::string account::pwd() const
{
    return this->_M_pwd;
}

bool account::from_file(accfile&& __f)
{
    if (!__f)
    {
        this->_M_id = 0;
        this->_M_name = "?bad accfile";
        return false;
    }

    this->_M_id = __f.id();
    __f >> (this->_M_name) >> (this->_M_pwd);
    return true;
}

bool account::to_file(accfile&& __f) const
{
    __f.close();
    __f.open(this->_M_id, accfile::openmode::out);
    if (!__f.is_open()) return false;

    __f << (this->_M_name) << ' ' << (this->_M_pwd);
    return true;
}

account& account::operator >> (accfile&& __f)
{
    this->from_file(std::move(__f));
    return *this;
}

account& account::operator << (accfile&& __f)
{
    this->to_file(std::move(__f));
    return *this;
}

}
