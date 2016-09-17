#! /usr/bin/python

def p81sol(InputFile):

        instream = open(InputFile)
        last_intsList = []
        intsList = [0]
        for line in instream:
                last_intsList = intsList
                intsList = [int(i) for i in line.split(",") if i]
                for i in xrange(len(intsList)):
                        if i==0:
                                intsList[i]+=last_intsList[i]
                        else:
                                try:
                                        upper = last_intsList[i]
                                except:
                                        upper= intsList[i-1]
                                intsList[i]+=min(intsList[i-1],upper)
        i = len(intsList)-2
        while i>=0:
                intsList[i]+=intsList[i+1]
                i-=1
        print min(intsList)



if __name__ == "__main__":
        p81sol("matrix.txt")

