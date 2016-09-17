#! /usr/bin/python

dic = {}
def part(n):
	def p(r,m):
	        try:
	                return dic[(r,m)]
	        except:
	                pass
	        if m==r:
	                return 1
	        if m==0:
	                return 0
	        if r<m:
	                return 0
	        dic[(r,m)] =  p(r-1,m-1) + p(r-m,m)
	        return dic[(r,m)]
	
	s=0
	for m in xrange(2,n+1):
	        s+= p(n,m)
	return s

if __name__ == "__main__":
        print part(100)
