#! /usr/bin/python

dic = {}

def fibonachi(n):
        if n == 1 or n==2:
                dic[n] = 1
        try:
                return dic[n]
        except:
                dic[n] = fibonachi(n-1) + fibonachi(n-2)
        return dic[n]


def is_double_pandigital(n):
        st = str(n)
        st1 = st[:9]
        st2 = st[-9:]
        for i in xrange(1,10):
                if str(i) not in st1 or str(i) not in st2:
                        return 0
        return 1


k = 2
while not is_double_pandigital(fibonachi(k)):
        k+=1
        if k%10000 == 0:
                print k
print k
