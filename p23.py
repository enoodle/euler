#! /usr/bin/python

from math import sqrt
import time


LAST_KNOWN = 28123

if __name__ == "__main__":
        t = time.clock()
        
        ''' find all abundant numbers smaller than LAST_KNOWN '''
        primes_list = [2]
        dev_sum_list = [0,1] # holds the sum of all devidors.
        abundant_list = [] # list of all abundant numbers below LAST_KNOWN
        for i in xrange(3,LAST_KNOWN+1):
                j = 0
                p = primes_list[j]
                found_dev = False
                while p <= sqrt(i) and j < len(primes_list) and not found_dev: # search for a prime devidor
                        if float(i)/float(p) == i/p: # if p devides i then 
                                found_dev = True
                                ''' calculate i's sum of all devidors based on (i/p)'s sum: '''
                                j = 1
                                while float(i)/float(p**(j+1)) == int(i/(p**(j+1))):
                                        j+=1
                                        # print 'j = ' , j , ' i = ' , i , ' p = ' , p
                                dev_sum_list.append( (dev_sum_list[(i/(p**j))-1] + i/(p**j)  ) * ( (p**(j+1)-1)/(p-1) ) - i ) 
                                if dev_sum_list[i-1] > i: # if i turns out to be abundant then add it to the list
                                        abundant_list.append(i)
                        else:
                                j+=1
                                p = primes_list[j]
                if not found_dev: # if couldn't find any prime devidor then this number is also prime
                        primes_list.append(i)
                        dev_sum_list.append(1) # a prime number only devidors are 1 and himself.
        print 'Finished finding abundant numbers. it took ' , time.clock()-t , ' seconds'
        print len(abundant_list)
        print max(abundant_list)

        ''' make a list of all numbers that can be written as sum of two abundant numbers '''
        sq = set([])
        for i in xrange(0,len(abundant_list)):
                sq = sq.union(set([abundant_list[i]+j for j in abundant_list[i:] if ((abundant_list[i]+j) < LAST_KNOWN) ]))
        # print sq

        ''' return the sum of all numbers that cant '''
        print 'The answer is: ', sum(set(range(1,LAST_KNOWN)).difference(sq))
        print 'Finished everything. it took ' , time.clock()-t , ' seconds'
