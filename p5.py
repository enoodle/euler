#! /usr/bin/python

def devisable(n):
        for it in [i+1 for i in range(20)]:
                if n%it!=0:
                        return 0
        return 1

def azeret(n):
        az=1
        for i in [i+1 for i in range(n)]:
                az*=i
        return az

def p5():
        num = azeret(20)
        print num

        for i in range(2,21):
                while devisable(num):
                        num/=i
                num*=i

        print num


if __name__ == "__main__":
        p5()

