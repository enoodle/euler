#! /usr/bin/python

j = 1
i = 3
n = 317584931803
while i < n :
        if n%i == 0:
                n/=i
                j = i
                print i, " " , n
        else:
                i = i + 2

print "n = ",n
print "i = " , i
print "you are looking for this: j=",j
