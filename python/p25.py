#! /usr/bin/python


memtable = {}

def ficonachi(n):
        if n==1:
                return 1
        if n==2:
                return 1
        try:
                return memtable[n]
        except:
                memtable[n] = ficonachi(n-1) + ficonachi(n-2)
                return memtable[n]

num = 0
i = 1
while ( len(str(num)) < 1000 ):
        num = ficonachi(i)
        i+=1
print i-1
