#! /usr/bin/python

from int2bin import int2bin

list = []

def is_palindrom(n):
        for i in xrange(len(n)):
                if n[i] != n[-i-1]:
                        return 0
        return 1

if __name__ == "__main__":
        for i in xrange(1,10**6+1):
                if is_palindrom(str(i)) and is_palindrom(int2bin(i)):
                        list.append(i)
                if i%(10**5)==0:
                        print i
        print sum(list)
