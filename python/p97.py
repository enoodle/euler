#! /usr/bin/python

class digit10() : 
        def __init__(self,n):
                self.n = n
        def _normalize(self):
                while self.n >= 10**10:
                        self.n-=10**10
        def __add__(self,n): 
                self.n +=n
                self._normalize()
                return self
        def __mul__(self,n):
                self.n *= n
                self._normalize()
                return self
        def __pow__(self,n):
                t = self.n
                for i in xrange(n-1):
                        self.n *= t
                        self._normalize()
                return self
        def __str__(self):
                return str(self.n)


num = digit10(2)
num = num**7830457
num = num*28433
num = num+1
print str(num)
