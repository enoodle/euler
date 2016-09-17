#! /usr/bin/python

dict = {0:1}

def f117(n):
        if n == 0:
                return 1
        if n < 0:
                return 0
        try:
                return dict[n]
        except:
                dict[n] = f117(n-1)+f117(n-2)+f117(n-3)+f117(n-4)
        return dict[n]

if __name__ == "__main__":
        print f117(50)
