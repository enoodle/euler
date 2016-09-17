#! /usr/bin/python

from primes import list_of_primes
from math import sqrt

def add_single_solution(sol, n , max_n, divisors):
    s = sum(divisors)
    k = len(divisors) + n - s
    if k not in sol and k < max_n:
        sol[k] = n

def add_solutions_aux(sol, n, max_n, unused, divisors):
    if len(unused) == 0:
        add_single_solution(sol, n, max_n, divisors)
    else:
        p = unused.pop()
        for i in range(len(divisors)):
            divisors[i] *= p
            add_solutions_aux(sol, n, max_n, unused, divisors)
            divisors[i] /= p
        divisors.append(p)
        add_solutions_aux(sol, n, max_n, unused, divisors)
        divisors.pop()
        unused.append(p)

def add_solutions(sol, n, max_n, factors):
    return add_solutions_aux(sol, n, max_n, factors, list())

def p88(max_n):
    lop = list_of_primes(int(sqrt(max_n))+1)

    sol = {}
    factors_list = [[],[1,],[2,],[3,]]

    for i in xrange(4,2*max_n+1):
        p = next((p for p in lop if i%p == 0), None)
        if p:
            pred = i/p
            factors_list.append(factors_list[pred] + [p,])
            add_solutions(sol, i, max_n, factors_list[-1])
        else:
            factors_list.append([i,])

        if len(sol) == max_n-1:
            return sum(set(sol.values()))

    return None


if __name__ == "__main__":
    print p88(12)
    print p88(12000)
