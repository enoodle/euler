#ifndef __SEQUENCE__H
#define __SEQUENCE__H

#include <vector> 

template <typename T>
class Sequence{
    public:
        // returns the next value.
        virtual T next() = 0;
        // restarts the sequence.
        virtual void restart() = 0;
};

template <typename T>
class ScalarSequence : public Sequence<T> {
    public:
        ScalarSequence(T tt) : t(tt) {}
        inline T next() { return t;}
        inline void restart() {}
    private:
        T t;
};

template <typename T>
class FiniteSequence : public Sequence<T> {
    public:
        virtual bool has_ended() = 0;
        // TODO: throw from next
};

template <typename T>
class ConcatSequence : public Sequence<T> {
    public:
        ConcatSequence(FiniteSequence<T>& ss1, Sequence<T>& ss2) :
            s1(ss1), s2(ss2) {}
        T next() {
            if (s1.has_ended() == true)
                return s2.next();
            return s1.next();
        }
        void restart(){ s1.restart(); s2.restart(); }
    private:
        FiniteSequence<T>& s1;
        Sequence<T>& s2;
};

template <typename T>
class SingleSeq : public FiniteSequence<T> {
    public:
        SingleSeq(T xx) : x(xx), b(false) {}
        inline T next() { b = true; return x;}
        inline void restart() { b = false;}
        inline bool has_ended() { return b; }
    private:
        T x;
        bool b;
};


template <typename T>
class MemoizedSequence : public Sequence<T> {
    public:
        MemoizedSequence(Sequence<T>& s) : 
            seq(s), ind(0) {}
        T next(){
            if (memo.size() > ind){
                return memo[ind++];
            }
            memo.push_back(seq.next());
            return next();
        }
        void restart() {ind = 0; }
    private:
        Sequence<T>& seq;
        std::vector<T> memo;
        unsigned int ind;

};

template <typename T>
class RecursiveSequence : public Sequence<T> {
    public:
        RecursiveSequence() : 
            fun(), n(0) {}

        T next() {
            if (n < fun.size()) { 
                return operator[](n++); 
            }
            std::pair<bool,T> seed = seed_value(n);
            if (seed.first){
                fun.push_back(seed.second);
            } else {
                fun.push_back(calc_recurrence(n));
            }
            ++n;
            return *fun.rbegin();
        }

        virtual T operator[](int i) { return fun[i]; }

        unsigned int size() { return fun.size(); }

        void restart() { n = 0; }

    protected:
        virtual T calc_recurrence(unsigned int i) = 0;
        virtual std::pair<bool,T> seed_value(unsigned int i) = 0;

    protected:
        std::vector<T> fun;
        unsigned int n;
};

#endif // __SEQUENCE__H
