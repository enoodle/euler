#! /usr/bin/python

list = []

from proper_devisors import get_proper_devisors

for i in range(1,10000):
        # get the sum of the proper devisors:
        sopd = sum(get_proper_devisors(i))
        if i == sum(get_proper_devisors(sopd)):
                if not i in list and i != sopd:
                        list.append(i)
                if not sopd in list and i !=sopd:
                        list.append(sopd)
                print i , sopd

print sum(list)
