#! /usr/bin/python

from primes import list_of_primes
from math import sqrt


def helper(d, max_n, lop, power):
    for p in lop:
        left_over = max_n - p**power
        if left_over > 0:
            if power == 2:
                d[left_over] = 1
            else:
                helper(d, left_over, lop, power-1)


def p87(max_n):

    lop = list_of_primes(int(sqrt(max_n))+1)

    d = {}

    helper(d, max_n, lop, 4)

    return len(d)



if __name__ == "__main__":
    print p87(50)
    print p87(50*10**6)
