#! /usr/bin/python

c = 0
for i in xrange(1,10):
        j = 1
        n = i**j
        while len(str(n)) >= j or j < 11:
                if len(str(n)) == j:
                        c+=1
                j+=1
                n = i**j
print c
