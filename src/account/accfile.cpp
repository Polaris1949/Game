#include "accfile.h"
#include "config.h"

namespace roco
{

accfile::accfile()
    : _M_id(), _M_file()
{}

accfile::accfile(std::size_t __id)
    : _M_id(__id)
{
    this->open();
}

std::size_t accfile::id() const
{
    return this->_M_id;
}

void accfile::open()
{
    this->_M_basic_open(this->_M_id, openmode::def);
    this->_M_check();
}

void accfile::open(std::size_t __id)
{
    this->_M_basic_open(__id, openmode::def);
    this->_M_check();
}

void accfile::open(std::size_t __id, openmode __mode)
{
    this->_M_basic_open(__id, __mode);
    this->_M_check();
}

void accfile::close()
{
    this->_M_file.close();
    this->_M_id = 0;
}

bool accfile::is_open() const
{
    return this->_M_file.is_open();
}

accfile::operator bool() const
{
    return this->is_open();
}

std::ios_base::openmode accfile::_S_file_openmode(openmode __mode)
{
    switch (__mode)
    {
        default:            return std::ios_base::in | std::ios_base::out;
        case openmode::in:  return std::ios_base::in;
        case openmode::out: return std::ios_base::out | std::ios_base::trunc;
    }
}

void accfile::_M_basic_open(std::size_t __id, openmode __mode)
{
    this->_M_file.open(std::string(_ROCO_DIR_VAR_ACC "/")
        + std::to_string(__id) + _ROCO_FE_ADB, _S_file_openmode(__mode));
    this->_M_id = __id;
}

void accfile::_M_check()
{
    if (!this->is_open()) this->_M_id = 0;
}

}
