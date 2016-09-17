/* Periodic Continued Fraction for integer root squares.
 */

#ifndef __PCF__H_
#define __PCF__H_

#include "gcf.h"

class SquareRootPCF{
    public:
        SquareRootPCF(erez_int N, erez_int a_0 = -1);
        Fraction<erez_int> next();
        void restart();

    private:
        class SquareRootPCFSequence : public Sequence<erez_int>{
            public:
                SquareRootPCFSequence(erez_int N, erez_int a_0 = -1);
                bool found_cycle();
                erez_int get_cycle();
                erez_int next();
                void restart();
            private:
                erez_int S,a0,a,m,d;
                bool cycle_found;
                erez_int cycle_length;
        };

        erez_int S;
        static ScalarSequence<erez_int> one_seq;
        SquareRootPCF::SquareRootPCFSequence pcf_seq;
        GCF gcf;
        
};

#endif // __PCF__H_
