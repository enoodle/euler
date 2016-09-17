/* 
 * Generalized Continued Fractions
 *
 * Assumptions:
 * a series starts from position 1 (posision 0 equals zero)
 * b series starts from position 0
 *
 *
 */
#ifndef __GCF__H_
#define __GCF__H_

#include "math_objects.h"

typedef Sequence<erez_int> sequence;

/* Generalized Continued Fraction
 *
 * b0 + a0/(b0 + (a1/(b1 + a2/...)))
 */
class GCF {
    public:
        GCF(sequence& aa, sequence& bb);

        Fraction<erez_int> next();
        void restart();

    private:
        sequence& a;
        sequence& b;
        erez_int A_p, A_c, B_p, B_c;
};

#endif //__GCF__H_
