#! /usr/bin/python

dic = {}
def factorial(n):
        if n == 0:
                return 1
        try:
                return dic[n]
        except:
                pass
        dic[n]  = n*factorial(n-1)
        return dic[n]


def SumOfDiggitsFactorial(n):
        kth_digg = lambda n,k: (n / (10**(k-1))) % 10
        ln = 0
        while  n / (10**ln) > 0 :
                ln+=1
        s = 0
        for i in xrange(1,ln+1):
                s+=factorial(kth_digg(n,i))
        return s

print SumOfDiggitsFactorial(145)
s = 0
for i in xrange(1,10**7):
        if i == SumOfDiggitsFactorial(i):
                s+=i
print s-3
