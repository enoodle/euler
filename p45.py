#! /usr/bin/python

if __name__ == "__main__":

        from math import sqrt
        p = 2
        found = 0
        while found < 4:
                p_2 = p**2
                x = sqrt(1+12*p_2-4*p)
                if x == int(x):
                        found+=1
                        t = 0.5*(-1+x)
                        h = 0.25*(1+x)
                        Pn = 0.5*p*(3*p-1)
                        Tn = 0.5*t*(t+1)
                        Hn = h*(2*h-1)
                        print 'p = ' , p , ' t = ' , t , ' h = ' , h ,
                        print ' Pn = ' , Pn , ' Tn = ' , Tn , ' Hn = ' , Hn
                p+=1
