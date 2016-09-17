#! /usr/bin/python

def devisable(n,ls):
        for i in ls:
                if n%i==0:
                        return 1
                if i**2>n:
                        return 0
        return 0

def p10():
        n=3
        list_of_primes = [2]

        while n<10**6:
                if not devisable(n,list_of_primes):
                        list_of_primes.append(n)
                n+=2

        print sum(list_of_primes)


if __name__ == "__main__":
        p10()

