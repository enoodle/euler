#! /usr/bin/python

def devisable(n,ls):
        for i in ls:
                if n%i==0:
                        return 1
                if i**2>n:
                        return 0
        return 0

def p7():
        i=1
        n=3
        list_of_primes = [2]

        while i<10001:
                if not devisable(n,list_of_primes):
                        list_of_primes.append(n)
                        i+=1
                n+=2

        print n-2


if __name__ == "__main__":
        p7()

