#! /usr/bin/python

"""
NOT SOLVED

"""


from p76 import part

if __name__ == "__main__":
	i=100
	print part(i)
	while (part(i)+1) % 10**6 != 0:
	        i+=1
	        if i%10**3 == 0:
	                print i
	print i
