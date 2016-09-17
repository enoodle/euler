#! /usr/bin/python


def get_factorization(n):
        ls = []
        i = 2
        t = 0
        while i <= n:
                while n%i == 0:
                        n/=i
                        t+=1
                if t > 0:
                        ls.append((i,t)) 
                i+=1
                t = 0
        return ls

dict = {}
def GetNumberOfDevisors(n):
        try:
                return dict[n]
        except:
                pass
        ls = get_factorization(n)
        t = 1
        for (p,alfa_i) in ls:
                t*=alfa_i+1
        dict[n] =  t
        return dict[n]

def triangle(n):
        return n*(n+1)/2

def NumberOfDevisorsOfTriangle(n):
        if n%2==0:
                return GetNumberOfDevisors(n/2)*GetNumberOfDevisors(n+1)
        else:
                return GetNumberOfDevisors(n)*GetNumberOfDevisors((n+1)/2)


print NumberOfDevisorsOfTriangle(7)

i = 1
while NumberOfDevisorsOfTriangle(i) < 500:
        i+=1
print i
print triangle(i)

