#include "math/math_objects.h"
#include "math/gcd.h"


#include <iostream>
#include <string>

using namespace std;

int p73(int max_d){

    int count = 0;
    for(int d = 4; d <= max_d; ++d){
        for (int n = d/3 + 1; 2*n < d ; ++n){
            if (gcd<int>(n,d) == 1){
                ++count;
            }
        }
    }

    return count;
}




int main(int argc, char** argv){
    if (argc == 2){
        string s(argv[1]);
        cout << p73(stoi(s)) << endl;
    }
    else{
        cout << p73(12000) << endl;
    }
    return 0;
}
