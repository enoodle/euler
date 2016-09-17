#! /usr/bin/python


def fac(n):
        if n == 0 :
                return 1
        else:
                return n*fac(n-1)
factorials_table = [fac(n) for n in xrange(10)]


def GetNextInChain(n):
        s = 0
        while n > 0:
                n,digit = divmod(n,10)
                s+=factorials_table[digit]
        return s


def how_long(n):
        r=1
        ls = []
        while n not in ls:
                ls.append(n)
                n = GetNextInChain(n)
                r+=1
        if n == ls[0]:
                return r-1
        return r

if __name__ == "__main__":

        print how_long(69)

        PossibleFacSums = {0:1}
        last = {}

        for i in xrange(6):
                for (k,v) in PossibleFacSums.iteritems():
                        if k!=0 or i ==0:
                                for x in xrange(10):
                                        try:
                                                last[x+k] +=v
                                        except KeyError:
                                                last[x+k] = v

                PossibleFacSums = last

        
        print len(PossibleFacSums.keys())
        print PossibleFacSums[367945]


        c = 0
        for (k,v) in PossibleFacSums.iteritems():
                if 60 == how_long(k):
                        c+=v
                        print k
                        print v
        print c
