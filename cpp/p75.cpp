#include <iostream>

#include "math/pythagorean_tree.h"

#include <set>


using namespace std;

class HipsterSet{
    public:
        void insert(int n) {
            if (everyone.insert(n).second){
                hipsters.insert(n);
            }
            else{
                hipsters.erase(n);
            }
        }

        int size() { return hipsters.size(); }

    private:
        set<int> hipsters;
        set<int> everyone;
};

int p75(int max_perimeter){
    HipsterSet hs;
    PythagoreanTriplet<int> pt(3,4,5);
    std::queue<PythagoreanTriplet<int> > q;
    q.push(pt);

    PythagoreanSequence<int> ps(q, 
            [max_perimeter](PythagoreanTriplet<int> pt){
            return pt.perimeter() < max_perimeter; });
    while (!ps.has_ended()){
        int perim = ps.next().perimeter();
        int cur = perim;
        while (cur < max_perimeter){
            hs.insert(cur);
            cur += perim;
        }
    }
    
    return hs.size();
}

int main(int argc, char** argv){
    if (argc == 2){
        string s(argv[1]);
        cout << p75(stoi(s)) << endl;
    }
    else{
        cout << p75(1500000) << endl;
    }
    return 0;
}

