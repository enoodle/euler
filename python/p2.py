#! /usr/bin/python

def p2():
        sum=0
        a=1
        b=c=0
        while (a+b)<=10**6:
                a=a+b
                c=b
                b=a-b
                if a%2==0:
                        sum+=a
        print sum


if __name__ == "__main__":
        p2()

