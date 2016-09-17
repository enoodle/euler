#include <iostream>
#include "math/pcf.h"

using namespace std;


int p66(int D_max){
    int best_D = 2;
    erez_int max_min_x = 3;
    int next_square = 2;
    for (int D = 2; D <= D_max; ++D){
        if (next_square * next_square == D){
            ++next_square;
            continue;
        }
        int alpha = next_square-1;

        //  gcf(beta_seq, alpha_seq);
        SquareRootPCF pcf(D, alpha);
        erez_int x,y;
        do{
            Fraction<erez_int> f = pcf.next();
            x = f.numerator();
            y = f.denumerator();
        } while ( ((x*x) - (D*y*y)) != 1);

        if (x > max_min_x){
            max_min_x = x;
            best_D = D;
        }

    }

    return best_D;
}

int main(){
    std::cout << p66(10) << std::endl;
    std::cout << p66(1000) << std::endl;
    return 0;
}
