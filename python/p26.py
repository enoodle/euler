#! /usr/bin/python


def alientefrom10(n):
        while n % 5 == 0 :
                n/=5
        while n % 2 == 0 :
                n/=2
        return n

def get_cycle_brute(n):
        a = 10%n
        d = 1
        while 1 != a:
                a = (a*10)%n
                d += 1
        return d

if __name__ == "__main__":

        import gcd
        import time

        t = time.clock()

        pl = [] # primes list
        '''  information in the form of : [prime factorization , cycle length of 1/n ]  
        when prime factorization is a list of [prime factor , number of times it is a factor ] '''
        infos = {} 

        ''' iterate on all possible numbers:
                factorize them and use that to find their cycle
        '''
        for n in xrange(2,1001):
                found_dev = False
                i = 0
                if n%1000 == 0:
                        print n
                while i < len(pl) and pl[i]**2 <= n and not found_dev:
                        p = pl[i]
                        if float(n)/float(p) == n/p:
                                ''' p is a prime factor of n:'''
                                found_dev = True
                                ls = [] # ls would be n's prime factorization
                                b = False
                                for l2 in infos[n/p][0]:
                                        if l2[0] == p:
                                                ls.append([p,l2[1]+1])
                                                b = True
                                        else:
                                                ls.append(l2)
                                if not b:
                                        ls.append([p,1])
                                if p in [2,5]:
                                        infos[n] = [ ls  , infos[n/p][1]  ]
                                else:
                                        if len(ls) == 1:
                                                if ls[0][0] not in [3, 487]:
                                                        ''' d = p**(k-1)*Tp '''
                                                        d = ls[0][0]*(ls[0][1]-1)*infos[ls[0][0]][1]
                                                else:
                                                        ''' dlog :( '''
                                                        d = get_cycle_brute(ls[0][0]**ls[0][1])
                                                        
                                        else:
                                                ls_to_lcm = [infos[a**b][1] for (a,b) in ls]
                                                d = gcd.lcm(ls_to_lcm[0],ls_to_lcm[1:])
                                        infos[n] = [ls, d]
                        i+=1
                if not found_dev:
                        pl.append(n)
                        ''' should find it's cycle length d
                        it is the smallest d s.t. 10**d == 1 (mod n) - dlog'''
                        d = 1
                        if n not in [5,2]:
                                d = get_cycle_brute(n)
                        infos[n] = [[[n,1]], d]

        ''' find the index with the maximum cycle length, could be done inside the main loop '''
        m = 0
        ind = 0
        for (k,d) in infos.items():
                if d[1] > m:
                        ind = k
                        m = d[1]
        print 'the number with largest recurring cycle is: ', ind , ' and the cycle is: ' , m
        print 'time elapsed: ' , time.clock() - t , ' [s] '
