#! /usr/bin/python


kth_digg = lambda n,k: (n / (10**(k-1))) % 10

curr = 1
number_of_diggits = 0
dns = 1
diggits_per_num = 1
i = 0
while i <= 6:
        if number_of_diggits + diggits_per_num >= 10**(i):
                dns *= kth_digg(curr,diggits_per_num - 10**(i) + number_of_diggits + 1)
                i+=1
        number_of_diggits += diggits_per_num
        curr+=1
        if curr == 10**diggits_per_num:
                diggits_per_num+=1
print dns
