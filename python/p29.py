#! /usr/bin/python


list = []

for a in range(2,101):
        for b in range(2,101):
                n = a**b
                if n not in list:
                        list.append(n)
print len(list)
