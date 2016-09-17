#! /usr/bin/python


def SumOfDiggitsPowers(n,b):
        kth_digg = lambda n,k: (n / (10**(k-1))) % 10
        ln = 0
        while  n / (10**ln) > 0 :
                ln+=1
        s=0
        for i in xrange(1,ln+1):
                s+=kth_digg(n,i) ** b
        return s

s=0
for i in xrange(1,1000000):
        if i == SumOfDiggitsPowers(i,5):
                s+=i
print s-1

