#! /usr/bin/python

max = 0

def is_prime(n):
        if n%2==0:
                return 0
        for i in xrange(3,n+1,2):
                if n%i==0:
                        return 0
                if i**2>n:
                        return 1

def make_prime_pandigit_list(n,num):
        if len(num)==n:
                num.reverse()
                num = int("".join([str(i) for i in num]))
                if is_prime(num) and num>globals()["max"]:
                        print num
                        globals()["max"] = num
                return
        else:
                for it in [i for i in xrange(1,n+1) if not i in num]:
                        num.append(it)
                        make_prime_pandigit_list(n,num)
                        num.pop()


def p41():

        for i in [1,3,7]:
                make_prime_pandigit_list(7,[i])

        print max

if __name__ == "__main__":
        p41()

