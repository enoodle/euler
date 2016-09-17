#! /usr/bin/python

dic = {}
def fac(n):
        if n == 0 :
                return 1
        try:
                return dic[n]
        except:
                pass
        dic[n] = n * fac(n-1)
        return dic[n]

def choose(n,k):
        return fac(n)/(fac(k)*fac(n-k))


num_of_diggits = 100
print choose(10+num_of_diggits,10) + choose(10+num_of_diggits-1,9) - 10*num_of_diggits - 2
