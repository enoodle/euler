#! /usr/bin/python

dict = {1:1}

def collatz_rout_len(n):
        try:
                return dict[n]
        except:
                if n%2 == 0:
                        dict[n] = 1+collatz_rout_len(n/2)
                else:
                        dict[n] = 1+collatz_rout_len(3*n+1)
        return dict[n]

if __name__ == "__main__":
        m = 1
        looking = 1
        for i in xrange(1,10**6+1):
                if collatz_rout_len(i) > m:
                        m = collatz_rout_len(i)
                        looking = i
                if i%100000 == 0 :
                        print i
        print looking
        print m
