#include "../primes.h"

#include <iostream>

using namespace std;

int main(){

    vector<int> primes = sundaram(100);
    for (unsigned int i = 0; i < primes.size(); ++i){
        cout << primes[i] << endl;
    }

    vector<int> phi = eulers_totient(1000);
    int i = 10;
    cout << "phi("  << i << ") = " << phi[i] << endl;

    primes = sundaram(10000000);

    cout << "sundaram 10^7 size = " << primes.size() << endl;

    phi = eulers_totient(10000000);

    cout << "phi 10^7" << endl;


    return 0;
}
