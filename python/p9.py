#! /usr/bin/python

from math import sqrt

def p9():
        a=b=0
        c=0

        while a+b+c!=1000:
                a+=1
                b=c=0
                while a+b+c<1000:
                        b+=1
                        c=sqrt(a**2+b**2)

        print "a=",a, "b=",b, "c=",c , "abc=",a*b*c


if __name__ == "__main__":
        p9()

