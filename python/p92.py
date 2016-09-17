#! /usr/bin/python

def GetNextInChain(n):
        s = 0
        while n>0:
                n,digit = divmod(n,10)
                s += digit**2
        return s


GetsToOne = [1,44,32,13,10,]
GetsTo89 = [89,145,42,20,4,16,37,58]
for i in xrange(1,10**3):
        ls = [i]
        while i != 1 and i !=89:
                if i in GetsToOne:
                        i = 1
                        GetsToOne.extend(ls[:-1])
                elif i in GetsTo89:
                        i = 89
                        GetsTo89.extend(ls[:-1])
                else:
                        i = GetNextInChain(i)
                        ls.append(i)
        if ls[-1] == 1:
                GetsToOne.extend(ls[:-1])
        if ls[-1] == 89:
                GetsTo89.extend(ls[:-1])

GetsTo89.sort()
GetsToOne.sort()
c = 0

for i in xrange(10**3,10**7):
        irep = GetNextInChain(i)
        if irep in GetsTo89:
                c+=1

print len(GetsTo89)+c
