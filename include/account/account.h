#ifndef _ROCO_ACCOUNT_H
#define _ROCO_ACCOUNT_H 1

#include <iostream>
#include <string>
#include <fstream>
#include "accfile.h"

namespace roco
{

class account;
class user; // from "user.h"

class account
{
    std::size_t _M_id;
    std::string _M_name;
    std::string _M_pwd;

public:
    account();
    account(std::size_t __id);
    account(std::size_t __id, const std::string& __name, \
        const std::string& __pwd);

    std::size_t id() const;
    std::string name() const;
    std::string pwd() const;

    bool from_file(accfile&& __f);
    bool to_file(accfile&& __f) const;
    account& operator >> (accfile&& __f);
    account& operator << (accfile&& __f);

    friend std::ostream& operator << (std::ostream& __out, \
        const account& __x);

private:
    friend class user;
};

}

#endif
