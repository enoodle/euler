#include "math/primes.h"
#include "math/gcd.h"
#include <iostream>

using namespace std;

erez_int g(int a, int n, int b, int m){
    erez_int d = gcd(n,m);
    if (a%d != b%d){ return 0; }

    vector<erez_int> ai;
    vector<erez_int> ni;

    ai.push_back(0);
    erez_int c = (b-a)/d;
    c = c % (m/d);
    if (c < 0) { c = (m/d) + c;}
    ai.push_back(c);

    ni.push_back(n/d);
    ni.push_back(m/d);

    erez_int y = chinese_reminder<erez_int>(ai, ni); 

    return (a + d*y) % lcm<erez_int>(n,m);
}


erez_int p531(int min_n, int max_n){

    erez_int s = 0;
    vector<int> tot = eulers_totient(max_n);
    for (int n = min_n; n < max_n-1; ++n){
        for (int m = n+1; m < max_n; ++m){
            s += g(tot[n],n, tot[m], m);
        }
    }

    return s;
}


int main(int argc, char** argv){
    cout << g(2,4,4,6) << endl;
    cout << g(3,4,4,6) << endl;
    if (argc == 3){
        string s1(argv[1]);
        string s2(argv[2]);
        cout << p531(stoi(s1), stoi(s2)) << endl;
    }
    else{
        std::cout << p531(1000000,1005000) << std::endl;
    }
    return 0;
}


