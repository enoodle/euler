#! /usr/bin/python

def egcd(m,n):
        '''
        returns a couple (k1,k2) such that m*k1 + n*k2 = gcd(m,n)
        '''
        #print "egcd(" , m , "," , n , ")"
        if m< n:
                return egcd(n,m)
        (k,r) = divmod(m,n)
        #print "k = " , k , " , r = " , r
        if 0 == r:
                return (0,1)
        (kn,kr) = egcd(n,r)
        #print "return (" , kr , "," , kn-k*kr , ")"
        return (kr,kn-k*kr)

def gcd(m,n):
        if hasattr(n,'__iter__'):
                if len(n) == 1:
                        return gcd(m,n[0])
                else:
                        return gcd(gcd(m,n[0]),n[1:])
        (k1,k2) = egcd(m,n)
        #print k1 , " " , k2
        return max(m,n)*k1+min(m,n)*k2

def lcm(m,n):
        if not hasattr(n,'__iter__'):
                return m*n/gcd(m,n)
        else:
                if len(n) == 1:
                        return lcm(m,n[0])
                return lcm(lcm(m,n[0]),n[1:])
