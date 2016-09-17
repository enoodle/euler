#! /usr/bin/python

from pythagorean import PythagoreanTree
from gcd import gcd
import heapq

def push_new_bpt(q, pt):
    a = pt.a
    b = pt.b

    if a >= b-a:
        heapq.heappush(q, (a,b))
    if b >= a-b:
        heapq.heappush(q, (b,a))

def repush_cube(q, m, ab):
    g = gcd(m,ab)
    heapq.heappush(q, (m*(g+1)/g, ab*(g+1)/g))

def cube_options(m, ab):
    def f(x):
        return ((x+1)/2) + 1 - (x%2)
    if m > ab:
        return f(ab-2)
    else:
        return f(2*m-ab)


def p86(n):
    base_triplets = PythagoreanTree(
        cmp_key = lambda pt : min(pt.values))
    q = []
    m = 0

    while n > 0:
        while len(q) == 0 or \
           q[0][0] > min(base_triplets.top().values):
            push_new_bpt(q,base_triplets.next())
        m,ab = heapq.heappop(q)
        repush_cube(q, m, ab)
        n -= cube_options(m, ab)

    return m


if __name__ == "__main__":
    print p86(10**6)
