#include "primes.h"
#include <boost/numeric/conversion/converter.hpp>
#include <boost/math/special_functions/sqrt1pm1.hpp>
#include <algorithm>

using std::pair;

int int_sqrt(int S){
    double sss = boost::math::sqrt1pm1(S);
    return boost::numeric::converter<int, double>::convert(sss) + 2;
}

vector<int> sundaram(int N){
    vector<int> primes(1,2);
    vector<int>  potential(N/2+1,1);

    for (int j = 0; j < N/2; ++j){
        for (int i = 1 ; (i <= j) && ((i+j+2*i*j) < (N/2+1)); ++i){
            potential[i+j+2*i*j] = 0;
        }
    }

    for (unsigned int i = 1; i < potential.size(); ++i){
        if (potential[i] == 1){
            primes.push_back(2*i+1);
        }
    }

    return primes;
}

vector<int> list_of_primes(int max_p){

    vector<int> primes = sundaram(int_sqrt(max_p));
    vector<int> extra_primes;

    for (int j = primes[primes.size()-1]+2; j <= max_p; j+=2){
        if (std::none_of(primes.begin(), primes.end(), [j](int p){return j%p==0;})){
            extra_primes.push_back(j);
        }
    }

    for (int p : extra_primes)
        primes.push_back(p);
    
    return primes;
}


vector<int> eulers_totient(int max_n){
    return eulers_totient(max_n, list_of_primes(int_sqrt(max_n)));
}

vector<int> eulers_totient(int max_n, const vector<int>& primes){

    vector<int> tot(max_n,1);
    for (int i = 2; i < max_n; ++i){ tot[i] = i-1; }

    for (int i = 3; i <= max_n; ++i){
        vector<int>::const_iterator it = std::find_if(primes.begin(), primes.end(), 
                [i](int p){return i%p==0;});
        if (it != primes.end()){
            int p = *it;
            int pred = i/p;
            if (pred % p == 0){
                tot[i] = tot[pred] * p;
            } else{
                tot[i] = tot[pred] * (p-1);
            }
        }
    }

    return tot;
}


vector<std::pair<int,int> > 
factorize_with_lop(int n, vector<int> &lop){
    vector<pair<int,int> > v;
    for(int p: lop){
        if (0 == n%p){
            int j = 0;
            while (0 == n%p){
                n/=p;
                ++j;
            }
            v.push_back(pair<int,int>(p,j));
        }
    }

    return v;
}


FactorizeMemoized::FactorizeMemoized(int max_n) : 
    max_n(max_n), lop(list_of_primes(int_sqrt(max_n))), memo() {}

FactorizeMemoized::FactorizeMemoized(int max_n, vector<int>& lop) :
    max_n(max_n), lop(lop), memo() {}

factors_list
FactorizeMemoized::factor(int n){
    auto it = memo.find(n);
    if (it != memo.end() ){
        return it->second;
    }
    factors_list fl = factorize_with_lop(n, lop);
    memo.insert(pair<int, factors_list> (n, fl));
    return fl;
}
