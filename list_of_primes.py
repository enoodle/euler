#! /usr/bin/python

primes_list = [2,3]

def devisable(n,ls):
        for i in ls:
                if n%i==0:
                        return 1
                if i**2>n:
                        return 0
        return 0

def list_of_primes(max_prime):
        last_prime = primes_list[-1]
        if last_prime >= max_prime:
                return primes_list
        n= last_prime+2
        while n<max_prime:
                if not devisable(n,primes_list):
                        primes_list.append(n)
                n+=2
        return primes_list


if __name__ == "__main__":
        pass

