#ifndef __PYTHAGOREAN_TREE_H__
#define __PYTHAGOREAN_TREE_H__

#include "sequence.h"
#include "base_definitions.h"
#include "math_objects.h"
#include <queue>
#include "Eigen/Dense"
#include "gcd.h" 

#include <functional>



template <typename T>
class PythagoreanTriplet{
    public:
        PythagoreanTriplet(T aa, T bb, T cc): a(aa), b(bb), c(cc) {}

        bool check(){ return (a*a + b*b) == c*c; }
        bool is_basic() { return gcd(gcd(a,b),c) == 1;}
        T perimeter(){ return a+b+c;}

    public:
        T a,b,c;

};


template <typename IntType>
class PythagoreanSequence : 
    public FiniteSequence<PythagoreanTriplet<IntType> > 
{
    public:
        typedef PythagoreanTriplet<IntType> PT;
        typedef std::queue<PT> QueueType;
        typedef std::function<bool(PT)> Predicate;

        static bool all_in(PT pt){ return true; }

    public:

        PythagoreanSequence(QueueType initial_q, 
                Predicate pred = all_in) : 
            q(initial_q), initial(initial_q),  upred(pred) {}

        PT next() {
            PT t = q.front();
            generate(t);
            q.pop(); 
            return t;
        }

        bool has_ended() { return q.empty(); }

        void restart() { q = initial; }

    private:
        QueueType q, initial;
        Predicate upred;

        typedef Eigen::Matrix<IntType,3,3> GeneratigMatrix;
        typedef Eigen::Matrix<IntType,3,1> TripletVec;

        void generate(PT pt){
            GeneratigMatrix gm[3];
            gm[0] << 1, -2, 2,  2, -1, 2,  2, -2 ,3;
            gm[1] << 1, 2, 2,  2, 1, 2,  2, 2 ,3;
            gm[2] << -1, 2, 2,  -2, 1, 2,  -2, 2 ,3;
            TripletVec tv;
            tv << pt.a, pt.b, pt.c;

            for (GeneratigMatrix m : gm){
                TripletVec candid_vec = (m*tv).transpose();
                PT candidate(candid_vec(0), candid_vec(1), candid_vec(2));
                if (upred(candidate))
                    q.push(candidate);
            }
        }
}; 

#endif // __PYTHAGOREAN_TREE_H__
