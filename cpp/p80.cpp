#include "math/math_objects.h"
#include <iostream>
#include <boost/numeric/conversion/converter.hpp>
typedef boost::numeric::converter<erez_float, erez_int> i2fconv;

using namespace std;

erez_int sum_of_digits_after_point(erez_float f, int len);

// s - return value will be square root of s
// k - number of steps
erez_float babylon_sqrt(int s, int k);

erez_float babylon_sqrt(int s, int k){
    erez_float sf = i2fconv::convert(s);
    erez_float x = sf/2.0;
    for (int i = 0 ; i < k; ++i){
        x = 0.5*(x + (sf/x));
    }

    return x;
}


erez_int sum_of_digits_after_point(erez_float fl, int len){
    erez_float f = fl - fl.convert_to<int>();
    erez_int sum = fl.convert_to<int>();
    for (int i = 0; i < len-1; ++i){ // first digit from before the point.
        f*=10;
        erez_int d = f.convert_to<int>();
        sum += d;
        f-=i2fconv::convert(d);
    }

    return sum;
}

erez_int p80(int max_n){
    erez_int sum = 0;
    int next_square = 2;
    for (int i = 2; i <= max_n; ++i){
        if (i == (next_square*next_square)){
            ++next_square;
            continue;
        }
        sum += sum_of_digits_after_point(babylon_sqrt(i,100),100);
    }
    return sum;
}


int main(int argc, char** argv){
    if (argc == 2){
        string s(argv[1]);
        cout << p80(stoi(s)) << endl;
    }
    else{
        std::cout << p80(100) << std::endl;
    }
    return 0;
}

