#! /usr/bin/python

from collections import deque
import heapq

class PythagoreanTriplet(object):
    def __init__(self, a,b,c, ):
        self.a = a
        self.b = b
        self.c = c
        self.values = [a,b,c]

    def check(self,):
        return self.a**2 + self.b**2 == self.c**2

    def perimeter(self):
        return sum(self.values)

    def __str__(self):
        return '(' + ' , '.join(str(x) for x in self.values) + ')'


class PythagoreanTree(object):
    generatinMatrices = [((1,-2,2),(2,-1,2),(2,-2,3)),
                        ((1,2,2),(2,1,2),(2,2,3)),
                        ((-1,2,2),(-2,1,2),(-2,2,3))]
    def __init__(self,pred = lambda x : True, 
                 first = PythagoreanTriplet( 3,4,5 ),
                 cmp_key = None):
        self.q = []
        self.cmp_key = cmp_key if cmp_key else \
                lambda pt : pt.perimeter()
        heapq.heappush(self.q, (self.cmp_key(first), first))
        self.pred = pred

    def __iter__(self):
        return self

    def __next__(self):
        return self.next()

    def top(self):
        return self.q[0][1]

    def next(self):
        if len(self.q) == 0: raise StopIteration()
        k, pt = heapq.heappop(self.q)
        for gm in PythagoreanTree.generatinMatrices:
            cand =PythagoreanTriplet(*[ 
                sum([ x*y for x,y in zip(pt.values, line) ]) 
                for line in gm ])
            if self.pred(cand): 
                heapq.heappush(self.q, (self.cmp_key(cand),cand))
        return pt


if __name__ == "__main__":
    pg = PythagoreanTree(cmp_key = lambda pt : max(pt.values))
    for k in range(10):
        print pg.next()
