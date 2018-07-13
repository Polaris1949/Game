#ifndef _ROCO_ACCFILE_HPP
#define _ROCO_ACCFILE_HPP 1

#include <fstream>

namespace roco
{

class accfile;

class accfile
{
    std::size_t _M_id;
    std::fstream _M_file;

public:
    enum class openmode : unsigned char
    { def, in, out };

    accfile();
    accfile(std::size_t __id);
    std::size_t id() const;
    void open();
    void open(std::size_t __id);
    void open(std::size_t __id, openmode __mode);
    void close();
    bool is_open() const;
    explicit operator bool() const;
    template<typename _T> accfile& operator >> (_T& __x);
    template<typename _T> accfile& operator << (const _T& __x);

private:
    static std::ios_base::openmode _S_file_openmode(openmode __mode);
    void _M_basic_open(std::size_t __id, openmode __mode);
    void _M_check();
};

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

template<typename _T>
accfile& accfile::operator >> (_T& __x)
{
    this->_M_file >> __x;
    return *this;
}

template<typename _T>
accfile& accfile::operator << (const _T& __x)
{
    this->_M_file << __x;
    return *this;
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
    this->_M_file.open(std::string("./data/") + std::to_string(__id),
        _S_file_openmode(__mode));
    this->_M_id = __id;
}

void accfile::_M_check()
{
    if (!this->is_open()) this->_M_id = 0;
}

}

#endif
