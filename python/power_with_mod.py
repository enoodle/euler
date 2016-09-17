#! /usr/bin/python

def pow_mod(b,a,m):
        if 0 == a:
                return 1
        half_mod = pow_mod(b,a/2,m)
        if 0 == (a%2):
                return (half_mod**2) % m
        else:
                return ((half_mod**2)*b) % m

if __name__ == "__main__":
        pass
