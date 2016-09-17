#include "pcf.h"

ScalarSequence<erez_int> SquareRootPCF::one_seq = ScalarSequence<erez_int>(1);

SquareRootPCF::SquareRootPCFSequence::SquareRootPCFSequence(erez_int N, erez_int a_0) :
    S(N), a0(a_0), a(a_0), m(0), d(1), cycle_found(false), cycle_length(0) {
        if (-1 == a0){ // finding a0 in case it wasnt provided..
            a0 = 1;
            while (a0*a0 < S) { ++a0; }
            --a0; a = a0;
        }
    }

bool SquareRootPCF::SquareRootPCFSequence::found_cycle() {
    return cycle_found;
}

erez_int SquareRootPCF::SquareRootPCFSequence::get_cycle() {
    return cycle_length;
}

erez_int SquareRootPCF::SquareRootPCFSequence::next(){
    a = (a0 + m) / d;
    m = d*a - m;
    d = (S - m*m) / d;

    if (a == 2*a0){ cycle_found = true; }
    else { ++cycle_length; }

    return a;
}

void SquareRootPCF::SquareRootPCFSequence::restart(){
    m = 0;
    d = 1;
    if (not cycle_found)
        cycle_length = 0;
    a = a0;
}



SquareRootPCF::SquareRootPCF(erez_int N, erez_int a_0) :
    S(N), pcf_seq(N, a_0), gcf(one_seq, pcf_seq) {}

Fraction<erez_int> SquareRootPCF::next() { return gcf.next(); }

void SquareRootPCF::restart() { gcf.restart(); }
