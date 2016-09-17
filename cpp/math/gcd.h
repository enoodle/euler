#ifndef __GCD_H__
#define __GCD_H__

#include "base_definitions.h"
#include <vector>
using std::vector;

template <typename T>
T gcd(T a, T b){

    if (b*b > a*a)
        return gcd(b,a);

    while (b != 0){
        T r = a%b;
        a = b;
        b = r;
    }
    return a;
}

template <typename T> T lcm(T x, T y){
    return x*y/gcd(x,y);
}

template <typename T>
class egcd_res{
    public:
        egcd_res(point<T> r, point<T> s, point<T> t):
            r(r), s(s), t(t) {}
        point<T> r,s,t;
};

/* Extended Euclides Algorithm
 *
 * r.x is the gcd of a and b
 * Bezout Coefficients are s.x * a  t.x * b = 1
 */
template <typename T>
egcd_res<T> egcd(T a, T b){

    point<T> r(a,b), s(1,0), t(0,1);
    
    while (r.y != 0){
        T q = r.x / r.y;
        r = point<T>( r.y, r.x-q*r.y );
        s = point<T>( s.y, s.x-q*s.y );
        t = point<T>( t.y, t.x-q*t.y );
    }

    return egcd_res<T>(r,s,t);
}

template <typename T>
T pow(T a, T b){
    if (0 == b) { return 1;}
    if (1 == b) { return a;}
    T t = pow(a,b/2);
    t = t*t;
    if (b%2 == 1) { t *= a ; }
    return t;
}

// Assumes ni are co-prime
template <typename T>
T chinese_reminder(vector<T> ai, vector<T> ni){
    T N = 1;
    for (T n_i : ni) { N*=n_i; }


    vector<T> ei;
    for (T n_i : ni){
        egcd_res<T> res = egcd(n_i, T(N/n_i));
        ei.push_back(res.t.x*N/n_i);
    }

    T x = 0;
    for (unsigned int i = 0; i < ai.size(); ++i){
        x += ei[i]*ai[i];
    }

    x = x%N;
    return (x<0) ? (N+x) : x;
}
#endif // __GCD_H__
