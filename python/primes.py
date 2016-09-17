#! /usr/bin/python

import math

def sundaram(max_n):
    lop = [2,]
    potential = range(max_n/2 + 1)

    for j in xrange(max_n/2):
        for i in xrange(1,j+1):
            if (i+j+2*i*j) >= len(potential): break
            potential[i+j+2*i*j] = 0

    for i in potential:
        if i: lop.append(2*i+1)

    return lop


def list_of_primes(max_n):
    base = sundaram(int(math.sqrt(max_n)))

    extra = []

    for j in xrange(base[-1], max_n+1, 2):
        if not any( (j%p == 0) for p in base):
            extra.append(j)

    return base + extra


def eulers_totient(max_n, lop = None):
    max_n += 1
    if not lop: lop = list_of_primes(int(math.sqrt(max_n)))

    tot = range(max_n)

    for i in xrange(max_n):
        p = next((p for p in lop if i%p == 0), None)
        if p:
            pred = i/p
            tot[i] = tot[pred] * p if (pred % p == 0) else tot[pred] * (p-1)

    return tot





if __name__ == "__main__":
    lop = list_of_primes(100)
    print lop
    print len(lop)
    print eulers_totient(36)[-1]
