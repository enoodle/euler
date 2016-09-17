#ifndef __PRIMES__H_
#define __PRIMES__H_

#include "math_objects.h"

#include <vector>
using std::vector;

#include <map>
using std::map;

/* List of all primes up to max_p using sudaram siev.
 */
vector<int> sundaram(int max_p);

/* List of all primes up to max_p using variety of methods.
 * Suppose to be the fastest here.
 */
vector<int> list_of_primes(int max_p);

/* List of values of eulers totient function for
 * all numbers up to max_n
 */
vector<int> eulers_totient(int max_n);
vector<int> eulers_totient(int max_n, const vector<int>& primes);

typedef vector<std::pair<int,int> > factors_list;

/*
 * returns a vector of pairs
 * each pair represents a prime factor with its power in the second place
 * the prime factors are ordered smallest first.
 */
factors_list
factorize_with_lop(int n, vector<int> &lop);

class FactorizeMemoized{
    public:
        FactorizeMemoized(int max_n);
        FactorizeMemoized(int max_n, vector<int>& lop);

        factors_list factor(int n);
    private:
        int max_n;
        vector<int> lop;
        map<int, factors_list > memo;
};

#endif //__PRIMES__H_
