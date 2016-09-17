#ifndef __BASE_DEFS__H_
#define __BASE_DEFS__H_

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/mpfr.hpp>

typedef boost::multiprecision::cpp_int erez_int;
//typedef int erez_int;

typedef boost::multiprecision::mpfr_float_1000 erez_float;

#include <vector>

template <typename T>
class point{
    public:
    point(T x, T y) : x(x), y(y) {}
    T x,y;
};

#endif // __BASE_DEFS__H_
