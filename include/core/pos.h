#ifndef _ROCO_POS_H
#define _ROCO_POS_H 1

namespace roco
{

template<typename _Tp>
struct position
{
    _Tp x;
    _Tp y;

    position();
    explicit position(_Tp __x);
    position(_Tp __x, _Tp __y);
};

typedef position<unsigned short> pos_t;

}

#include "pos.tcc"

#endif
