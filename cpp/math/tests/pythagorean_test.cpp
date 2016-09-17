#include "../pythagorean_tree.h"
#include <iostream>

#include <queue>


using std::cout;
using std::endl;


int main(){

    PythagoreanTriplet<erez_int> pt(3,4,5);
    cout << pt.check() << endl;
    cout << pt.is_basic() << endl;
    

    std::queue<PythagoreanTriplet<erez_int> > q;
    q.push(pt);
    PythagoreanSequence<erez_int> ps(q);

    for (int i = 0; i < 10; ++i){
        PythagoreanTriplet<erez_int> pt = ps.next();
        cout << pt.a << ", " << pt.b << ", " << pt.c << endl;
    }

    return 0;
}
