#! /usr/bin/python

def azere_spec(n):
        az=1
        for i in [i+1 for i in xrange(n)]:
                while i%10==0:
                        i/=10
                az*=i
        return az

def p5():
        num = int(azere_spec(100))
        sumod=0
        while num>0:
                sumod+=num%10
                num/=10


        print sumod


if __name__ == "__main__":
        p5()

