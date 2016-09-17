#include "math_objects.h"
#include "gcd.h"

bool are_permutes(int a, int b){
    int digits[10] = {0};

    while( a > 0){
        ++digits[a%10];
        --digits[b%10];
        a /= 10;
        b /= 10;
        // no leading zeros
        if (((a == 0) && (b != 0)) || ((a != 0) && (b == 0)))
            return false;
    }

    for (int i = 0; i < 10; ++i){
        if (digits[i] != 0){
            return false;
        }
    }

    return true;
}
