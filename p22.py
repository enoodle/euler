#! /usr/bin/python

def wordval(str):
        val = 0
        for i in range(len(str)):
                val += ord(str[i]) - ord('A') + 1
        return val

if __name__ == "__main__":
        ins = open("input22","r")

        line = ins.readline()

        ins.close()

        list = line.split(",")
        list = [ i[1:-1] for i in list ]
        list.sort()
        print len(list)
        print list.index("COLIN")
        for i in range(len(list)):
                list[i] = wordval(list[i])*(i+1)
        print sum(list)
