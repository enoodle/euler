#! /usr/bin/python


def do_thing(ls,n):
        digit_map = [0,0,0,0,0,0,0,0,0,0,0]
        x = n
        while x > 0:
                x,digit = divmod(x,10)
                digit_map[digit]+=1
        try:
                index = [i[0] for i in ls].index(digit_map)
                ls[index].append(n)
        except:
                ls.append([digit_map,n])
        return ls


n = 22
ls = [[1]]
while max([len(i)-1 for i in ls ]) < 5:
        ls = do_thing(ls,n**3)
        n+=1
        if n%10**3 == 0:
                print n
index = [len(i)-1 for i in ls].index(5)
print ls[index]
