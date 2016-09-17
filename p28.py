#! /usr/bin/python

def SerialGen(n):
        a = 1
        i = 4
        t = 1
        while a <=n**2:
                yield a
                i+=1
                a += 2*t
                if i % 4 == 0:
                        t+=1
                        i=0

An = SerialGen(1001)

print sum(An)
