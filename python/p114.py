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
        for i in xrange(3,n+1):
                if n-i>0:
                        s+=func(n-i-1)
                else:
                        s+=1
        dic[n] = s
        return s

print func(50)

