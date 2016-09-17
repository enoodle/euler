#include "math/sequence.h"

#include <iostream>
#include <string>

using namespace std;

class NaturalsInterleavedSeq : public Sequence<int> {
    public:
        NaturalsInterleavedSeq() : cur(0) {}
        int next(){
            if (0 == cur){
                cur = 1;
                return 0;
            }
            if (cur > 0){
                cur = -cur;
                return -cur;
            } 
            cur = 1 - cur;
            return 1 - cur;
        }

        void restart() { cur = 0; }
    private:
        int cur;
};

class PentagonalNumbersSeq : public Sequence<unsigned int> {
    public:
        PentagonalNumbersSeq() : s() { s.next();}
        unsigned int next() {
            int k = s.next();
            return (3*k*k - k) / 2;
        }
        inline static unsigned int pentagonal(int k){
            return k*(3*k - 1) / 2;
        }
        void restart() {s.restart(); s.next();}
    private:
        NaturalsInterleavedSeq s;
};

class PartitionSequence : public RecursiveSequence<int> {
    public:
        PartitionSequence(int modu): 
            mod(modu)  { }

        virtual int calc_recurrence(unsigned int i){
            NaturalsInterleavedSeq naturals;
            int sum = 0;
            naturals.next(); // skip 0
            int k = naturals.next();
            unsigned int gk = PentagonalNumbersSeq::pentagonal(k);
            do {
                int sign = ( (k-1) % 2 == 0) ? 1 : -1 ;
                sum = (sum + sign * operator[](i-gk)) % mod;
                k = naturals.next();
                gk = PentagonalNumbersSeq::pentagonal(k);
            } while (gk <= i) ;

            return sum;
        }
        virtual std::pair<bool,int> seed_value(unsigned int i){
            if (i <= 1){
                return std::pair<bool,int>(true,1);
            }
            if (i == 2) {
                return std::pair<bool,int>(true,2);
            }
            return std::pair<bool,int>(false,0);
        }


    private:
        int mod;
        
};

int p78(int dividor){
    PartitionSequence seq(dividor);
    int p;
    int i = 0;
    do{
        p = seq.next();
        ++i;
    } while (p != 0 );

    return i-1;
}




int main(int argc, char** argv){
    /*
    PentagonalNumbersSeq pseq;
    for (int i = 0 ; i < 10; ++i) { cout << pseq.next() << endl; }

    PartitionSequence seq(10000);
    for (int i = 0 ; i < 10; ++i) { 
        cout << seq.next() << endl; 
    }
    */
    if (argc == 2){
        string s(argv[1]);
        cout << p78(stoi(s)) << endl;
    }
    else{
        cout << p78(1000000) << endl;
    }
    return 0;
}

