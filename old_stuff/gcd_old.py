#! /usr/bin/python

def gcd(m,n):
        if m< n:
                return gcd(n,m)
        r = m % n
        if 0 == r:
                return n
        else:
                return gcd(n,r)
