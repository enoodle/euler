#! /usr/bin/python

def int2bin(n):
        str = ""
        while n > 0:
                if n%2==0:
                        str = "0"+ str
                        n/=2
                else:
                        str = "1" + str
                        n= (n-1)/2
        return str
