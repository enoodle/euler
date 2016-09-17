#include "math/primes.h"
#include <iostream>
#include <algorithm>

using namespace std;


erez_int p72(int max_n){
    erez_int s = 0;
    for(int phi : eulers_totient(max_n)){
        s = s+phi;
    }

    return s;
}


int main(int argc, char** argv){
    if (argc == 2){
        string s(argv[1]);
        cout << p72(stoi(s)) << endl;
    }
    else{
        std::cout << p72(1000000) << std::endl;
    }
    return 0;
}

