#! /usr/bin/python


import prime_factorization 

def bin_counter(n):
        ls = map(lambda x:int(x),("0 "*n).split())
        while 0 in ls:
                yield ls
                i = 0
                while ls[i]==1:
                        ls[i]=0
                        i+=1
                ls[i]=1
        yield ls

def uniqe(ls):
        ls.sort()
        ls2=[]
        for i in xrange(len(ls)-1):
                if ls[i]!=ls[i+1]:
                        ls2.append(ls[i])
        return ls2

def permutes(ls1):
        ''' takes a list of integers and returns
        a list of all different multiplications possible'''
        ls = [i for i in ls1]
        n = len(ls)
        g = bin_counter(n)
        g.next()
        b = 1
        while b==1:
                try:
                        cur = g.next()
                        m = 1
                        for i in xrange(n):
                                if cur[i]==1:
                                        m*=ls[i]
                        ls.append(m)
                except StopIteration:
                        b=0
        return uniqe(ls)


def get_proper_devisors2(n):
        ls = prime_factorization.factorization(n)
        return permutes(ls)

def get_proper_devisors(n):
        list = [1]
        for i in xrange(1,n/2+1):
                if n%i == 0:
                        list.append(i)
        return list

if __name__ == "__main__":
        pass
