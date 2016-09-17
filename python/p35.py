#! /usr/bin/python


from list_of_primes import list_of_primes

def permutes_in_ls(n,ls):
        #print 'starts checking permutations for ' , n
        d = n%10
        m = n
        l = 0
        while m > 0:
                m/=10
                l+=1
        m = n
        similarity_penalty = -1
        for i in xrange(1,l+1):
                #print 'm = ' , m , ' l = ' , l , ' d = ' , d
                try:
                        if m != n:
                                ls.remove(m)
                #                print 'removed: ', m
                        else:
                                similarity_penalty+=1
                except:
                        return 0
                m = (m-d)/10 + d*(10**(l-1))
                d = m%10
        print n
        return l-similarity_penalty


if __name__ == "__main__":

        import time
        t = time.clock()

        ls = list_of_primes(10**6)

        counter = 0
        for i in ls:
                #print 'next prime to check is: ' , i
                counter+= permutes_in_ls(i,ls)           
        print counter
        print 'This took ' ,  time.clock()- t , ' seconds'
