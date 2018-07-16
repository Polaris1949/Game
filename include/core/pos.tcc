namespace roco
{

template<typename _Tp>
position<_Tp>::
position()
    : x(), y()
{}

template<typename _Tp>
position<_Tp>::
position(_Tp __x)
    : x(__x), y()
{}

template<typename _Tp>
position<_Tp>::
position(_Tp __x, _Tp __y)
    : x(__x), y(__y)
{}

}
