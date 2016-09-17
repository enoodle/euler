#! /usr/bin/python

''' NOT SOLVED '''

if __name__ == "__main__":

        import list_of_primes

        found = []
        digits = [1,3,7,9]
        l = list_of_primes.list_of_primes(100)
        w = 2
        while len(found) < 11:
                for ii in range(0,2**w):
                        n = 0
                        while ii > 0:
                                n=n*10+digits[ii%4]
                                ii/=4
                        
                w+=1

        print sum(found)
