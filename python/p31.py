#! /usr/bin/python

A = {}

coin_t = [1,2,5,10,20,50,100,200]

fac_tbl = {0:1,1:1}

def factorial(n):
        if 0 == n:
                return 1
        if n in fac_tbl.keys():
                return fac_tbl[n]
        else:
                fac_tbl[n] = factorial(n-1)*n
                return fac_tbl[n]

def foo(n,m):
        ''' 
        n is the number to search
        kinds of coins we used so far
        '''
        s = 0
        if 0 == n:
                return 1
        if len(coin_t) == m:
                return 0
        c = coin_t[m]
        k = 0
        while n-k*c >= 0:
                if (n-k*c,m+1) in A.keys():
                        s+= A[(n-k*c,m+1)]
                else:
                        s+= foo(n-k*c,m+1)
                k+=1
        A[(n,m)] = s
        return s

if __name__ == "__main__":
        import time
        t = time.clock()
        print foo(200,0)
        print 'time elapsed: ' , time.clock()-t , ' [s]'
