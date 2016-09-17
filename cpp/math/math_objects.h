#ifndef __MATH_OBJECTS__H_
#define __MATH_OBJECTS__H_

#include <iostream>
#include "base_definitions.h"
#include "sequence.h"
#include "gcd.h"

/* Fraction of two integers.
 *
 * Always balanced.
 */
template <typename T>
class Fraction{
    public:
        Fraction(T numerator, T denumerator);

        inline T numerator() const {return n;}
        inline T denumerator() const {return d;}

        bool operator<(Fraction<T> f2);
        bool operator>(Fraction<T> f2);
        bool operator==(Fraction<T> f2);
        bool operator!=(Fraction<T> f2);

        Fraction<T> operator*(Fraction<T> f2);
        Fraction<T> operator/(Fraction<T> f2);
        Fraction<T> operator+(Fraction<T> f2);
        Fraction<T> operator-(Fraction<T> f2);

    private:
        T n,d;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Fraction<T>& f);

bool are_permutes(int a, int b);




/* 
 * -------------------------------------------
 * ---- Template implementations -------------
 * -------------------------------------------
 */
template <typename T>
Fraction<T>::Fraction(T numerator, T denumerator) : 
    n(numerator), d(denumerator) {

    egcd_res<T> res = egcd(n,d);
    if (res.s.y == 0)
        throw std::domain_error("Fraction: devision by zero."); // TODO
    if (res.s.y == 1){ n = -res.t.y; d = 1; }
    if (res.s.y > 0){ n = -res.t.y; d = res.s.y; }
    else {  n = res.t.y; d = -res.s.y; }
}

template <typename T>
bool Fraction<T>::operator<(Fraction<T> f2){
    return (n * f2.denumerator()) < (f2.numerator() * d);
}
template <typename T>
bool Fraction<T>::operator>(Fraction<T> f2){
    return (n * f2.denumerator()) > (f2.numerator() * d);
}
template <typename T>
bool Fraction<T>::operator==(Fraction<T> f2){
    return (n == f2.numerator()) && (d == f2.denumerator());
}
template <typename T>
bool Fraction<T>::operator!=(Fraction<T> f2){
    return (n != f2.numerator()) || (d != f2.denumerator());
}

template <typename T>
Fraction<T> Fraction<T>::operator+(Fraction<T> f2){
    return Fraction<T>( (n * f2.denumerator()) + (f2.numerator() * d), 
            d * f2.denumerator());
}
template <typename T>
Fraction<T> Fraction<T>::operator-(Fraction<T> f2){
    return Fraction<T>( (n * f2.denumerator()) - (f2.numerator() * d), 
            d * f2.denumerator());
}
template <typename T>
Fraction<T> Fraction<T>::operator/(Fraction<T> f2){
    return Fraction<T>(n * f2.denumerator(), d * f2.numerator());
}
template <typename T>
Fraction<T> Fraction<T>::operator*(Fraction<T> f2){
    return Fraction<T>(n * f2.numerator(), d * f2.denumerator());
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Fraction<T>& f){
    return os << "(" << f.numerator() << " / " << f.denumerator() << ")";
}


#endif // __MATH_OBJECTS__H_
