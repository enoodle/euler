#include "math/primes.h"
#include "math/math_objects.h"


#include <iostream>
#include <string>

using namespace std;

int p70(int max_n){

    vector<int> phi = eulers_totient(max_n);
    Fraction<erez_int> ratio(2,1);
    int best_n = 1;

    for (unsigned int i = 2 ; i <phi.size(); ++i){
        if (are_permutes(i, phi[i])){
            if (ratio > Fraction<erez_int>(i,phi[i])){
                best_n = i;
                ratio = Fraction<erez_int>(i, phi[i]);
            }
        }

    }

    return best_n;
}


int main(int argc, char** argv){
    if (argc == 2){
        string s(argv[1]);
        cout << p70(stoi(s)) << endl;
    }
    else{
        std::cout << p70(10000000) << std::endl;
    }
    return 0;
}

