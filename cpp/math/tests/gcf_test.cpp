#include "../gcf.h"
#include "../pcf.h"

#include <iostream>
using namespace std;

int main(){
    SingleSeq<erez_int> sseq(1);
    ScalarSequence<erez_int> one_seq(1), two_seq(2);
    ConcatSequence<erez_int> conseq(sseq, two_seq);

    for (int i = 0; i < 10; ++i){
        cout << one_seq.next() << " " << conseq.next() << endl;
    }

    one_seq.restart();
    conseq.restart();
    GCF gcf(one_seq, conseq);

    for (int i = 0; i < 10; ++i){
        cout << gcf.next() << endl;
    }


    SquareRootPCF pcf(7, 2);
    for (int i = 0; i < 10; ++i){
        cout << pcf.next() << endl;
    }


    return 0;
}
