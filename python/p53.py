#! /usr/bin/python

def az(n): # n!
        if n<=1:
                return 1
        return n*az(n-1)

def nCr(n,r): # n!/(r!*(n-r)!)
        return az(n)/((az(r))*(az(n-r)))

def p53sol(n):
        if n<=22:
                return 0
        sum = 0
        for i in xrange(23,n+1):
                j = 4
                while nCr(i,j)<10**6:
                        j+=1
#                print "j = ",j," ",
                sum += 2*(i/2+i%2-j)
                if not i%2:
                        sum+=1
#                print "sum = ",sum
        return sum


if __name__ == "__main__":
        print p53sol(100)
