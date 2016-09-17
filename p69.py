#! /usr/bin/python

def devisable(n,ls):
        for i in ls:
                if n%i==0:
                        return 1
                if i**2>n:
                        return 0
        return 0

def p_69(max_n):
        i=1
        n=3
        primes_list = [2]
        prod = 2;

        while prod<max_n:
                if not devisable(n,primes_list):
                        primes_list.append(n)
                        if prod*n >= max_n:
                                return prod
                        prod *=n
                        print n
                n+=2
        return prod



if __name__ == "__main__":
        print p_69(10**9)
