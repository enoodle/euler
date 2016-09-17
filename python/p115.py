#! /usr/bin/python

dic = {}
def func(n):
        if n==0:
                return 1
        if n < 0 :
                return 0
        try:
                return dic[n]
        except:
                pass
        s = 0
        s+=func(n-1)
        for i in xrange(50,n+1):
                if n-i>0:
                        s+=func(n-i-1)
                else:
                        s+=1
        dic[n] = s
        return s

n = 50
while func(n)<10**6:
        n+=1
print n

