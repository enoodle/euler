#! /usr/bin/python

def is_palindrom(n):
        ns = str(n)
        i=0
        j=ns.__len__()-1
        while j>i:
                if ns[i]!=ns[j]:
                        return 0
                i+=1
                j-=1
        return 1


def p4():
        n=m=1000
        max=0
        while n>0:
                n-=1
                m=n
                while m>0 and not is_palindrom(m*n):
                        m-=1
                if (max<n*m):
                        max=n*m
        print max


if __name__ == "__main__":
        p4()

