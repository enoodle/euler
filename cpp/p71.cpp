#include <iostream>
#include "math/math_objects.h"

erez_int p71(int max_d){
    Fraction<erez_int> closest_so_far(1,7), target(3,7);

    for(int i = 2; i < max_d; ++i){
        int num = (i*3)/7;
        Fraction<erez_int> f = Fraction<erez_int>(num,i);

        if ((f != target) && ((target-f) < (target-closest_so_far))){
            closest_so_far = f;
        }

    }

    return closest_so_far.numerator();
}

int main(){
    std::cout << p71(1000000) << std::endl;
}
