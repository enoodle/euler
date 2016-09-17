#! /usr/bin/python

arr = []
i=0
infile = open("input11","r")
for line in infile.readlines():
        arr.append( [int(j) for j in line[:-1].split(" ")] )
infile.close()

dic = {}
for i in xrange(20):
        for j in xrange(20):
                dic[(i,j)] = arr[i][j]

class DictProtect(dict):
        def __init__(self,dic = None ):
                self.data = {}
                if dic is not None:
                        self.data = dic
        def __getitem__(self,key):
                try:
                        return self.data[key]
                except:
                        return 1



dic = DictProtect(dic)
m = 0
for i in xrange(20):
        for j in xrange(20):
                m = max(m,
                        dic[(i-3,j)]*dic[(i-2,j)]*dic[(i-1,j)]*dic[(i,j)],
                        dic[(i+3,j)]*dic[(i+2,j)]*dic[(i+1,j)]*dic[(i,j)],
                        dic[(i-3,j+3)]*dic[(i-2,j+2)]*dic[(i-1,j+1)]*dic[(i,j)],
                        dic[(i+3,j-3)]*dic[(i+2,j-2)]*dic[(i+1,j-1)]*dic[(i,j)],
                        dic[(i-3,j-3)]*dic[(i-2,j-2)]*dic[(i-1,j-1)]*dic[(i,j)],
                        dic[(i+3,j+3)]*dic[(i+2,j+2)]*dic[(i+1,j+1)]*dic[(i,j)],
                        dic[(i,j+3)]*dic[(i,j+2)]*dic[(i,j+1)]*dic[(i,j)])
print m
