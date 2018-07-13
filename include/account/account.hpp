#ifndef _ROCO_ACCOUNT_HPP
#define _ROCO_ACCOUNT_HPP 1

#include <iostream>
#include <string>
#include <fstream>
#include "accfile.hpp"
#include "user.hpp"

namespace roco
{

class account;

//[[deprecated]] account login(std::size_t __id, std::string __pwd);

class account
{
    std::size_t _M_id;
    std::string _M_name;
    std::string _M_pwd;

public:
    account();
    [[deprecated]] account(std::size_t __id, std::string __name);

    std::size_t id() const;
    std::string name() const;
    std::string pwd() const;

    bool from_file(accfile& __f);
    bool to_file(accfile& __f) const;
    account& operator >> (accfile& __f);
    account& operator << (accfile& __f);

    bool login(user& __u, const std::string& __pwd);
    bool logout(user& __u);

    friend std::ostream& operator << (std::ostream& __out, const account& __x);

private:
    friend account login(std::size_t __id, std::string __pwd);
};

account::account()
    : _M_id(), _M_name(), _M_pwd()
{}

account::account(std::size_t __id, std::string __name)
    : _M_id(__id), _M_name(__name)
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

bool account::from_file(accfile& __f)
{
    if (!__f)
    {
        this->_M_id = 0;
        this->_M_name = "bad accfile";
        return false;
    }

    this->_M_id = __f.id();
    __f >> (this->_M_name) >> (this->_M_pwd);
    return true;
}

bool account::to_file(accfile& __f) const
{
    __f.close();
    __f.open(this->_M_id);
    if (!__f) return false;

    __f << (this->_M_name) << ' ' << (this->_M_pwd);
    return true;
}

account& account::operator >> (accfile& __f)
{
    this->from_file(__f);
    return *this;
}

account& account::operator << (accfile& __f)
{
    this->to_file(__f);
    return *this;
}

bool account::login(user& __u, const std::string& __pwd)
{
    if (__pwd != this->_M_pwd) return false;
    __u._M_id = this->_M_id;
    __u._M_name = this->_M_name;
    return true;
}
/*
account login(std::size_t __id, std::string __pwd)
{
    std::ifstream fin(std::string("./data/") + std::to_string(__id));
    if (!fin.is_open()) return account(0, "<Bad userid>");
    std::string tmp1, tmp2;
    fin >> tmp1 >> tmp2;
    if (tmp2 == __pwd) return account(__id, tmp1);
    return account(0, "<Bad password>");
}
*/
}

#endif
