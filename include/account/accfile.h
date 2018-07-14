#ifndef _ROCO_ACCFILE_H
#define _ROCO_ACCFILE_H 1

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

}

#endif
