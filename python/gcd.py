#! /usr/bin/python


def gcd(a,b):
    if b>a: return gcd(b,a)
    while b > 0:
        a,b = b, a%b

    return a

def egcd(a,b):
    r = (a,b)
    s = (1,0)
    t = (0,1)
    while r[1] > 0:
        q = r[0]/r[1]
        r = (r[1], r[0] - q*r[1])
        s = (s[1], s[0] - q*s[1])
        t = (t[1], t[0] - q*t[1])

    return r,s,t


if __name__ == "__main__":
    print reduce(gcd, [30,90,15,20])
    r,s,t = egcd(2*5*7,7*2)
    print r[0]
