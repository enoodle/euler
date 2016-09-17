#include "gcf.h"

GCF::GCF(sequence& aa, sequence& bb) : 
    a(aa), b(bb), A_p(1), B_p(0), B_c(1) {
    
    a.restart();
    b.restart();
    A_c = b.next();
}

Fraction<erez_int> GCF::next(){
    erez_int a_n = a.next();
    erez_int b_n = b.next();

    erez_int A_n = b_n*A_c + a_n*A_p;
    erez_int B_n = b_n*B_c + a_n*B_p;

    A_p = A_c;
    B_p = B_c;
    A_c = A_n;
    B_c = B_n;

    return Fraction<erez_int>(A_n, B_n);
}

void GCF::restart(){
    a.restart();
    b.restart();
    A_p = 1; B_p = 0; B_c = 1; 
    A_c = b.next();
}
