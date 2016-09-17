#! /usr/bin/python

def is_bouncy(n):
        kth_dig = lambda n,k: (n / (10**(k-1))) % 10
        ln = 0
        while  n / (10**ln) > 0 :
                ln+=1
        t = 1
        while t< ln and kth_dig(n,t) == kth_dig(n,t+1):
                t+=1
        if kth_dig(n,t) > kth_dig(n,t+1):
                for i in xrange(t,ln):
                        if kth_dig(n,i) < kth_dig(n,i+1):
                                return 1
        else:
                for i in xrange(t,ln):
                        if kth_dig(n,i) > kth_dig(n,i+1):
                                return 1
        return 0

s= 0.0
i = 1.0
while s/i < 0.99 :
        i+=1
        s+=is_bouncy(int(i))
print s
print i
