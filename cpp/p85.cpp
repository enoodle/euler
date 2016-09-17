#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
class DynamicProgramming{
    public:
        typedef std::function<bool(int,int)> SeedPredicate;
        typedef std::function<T(int,int)> SeedGen;
        typedef std::function<T(int,int, 
                vector<vector<T> >&)> DynamicRule;
        typedef std::function<void(int,int,T&)> Visitor;

        DynamicProgramming(vector<vector<T> >& base,
                SeedPredicate seed_pred,
                SeedGen seed_gen,
                DynamicRule rule,
                // this mustn't(!) dangle
                Visitor& visitor) : 
            seed_pred(seed_pred), seed_gen(seed_gen), 
            rule(rule), visitor(visitor) {

                if (base.size() == 0 || base[0].size() == 0){
                    throw std::logic_error("base can't be empty");
                }
                for (auto &row : base){
                    if (row.size() != base[0].size()){
                        throw std::logic_error("base should be rectangle");
                    }
                }
                m = base; // CC'tor because m doesn't exist
            }

        void calc_new_row(){
            m.push_back(vector<T>());
            int i = m.size()-1;
            for (unsigned int j = 0 ; j < m[i-1].size(); ++j){ 
                //i-1 is a legal index because base was not empty
                calc_single(i,j);
            }
        }

        void calc_new_column(){
            int j = m[0].size();
            for (unsigned int i = 0 ; i < m.size(); ++i){
                // assumes base was a rectangle
                calc_single(i,j);
            }
        }

        void inflate(){
            calc_new_row();
            calc_new_column();
        }

    private:
        vector<vector<T> > m;
        SeedPredicate seed_pred;
        SeedGen seed_gen;
        DynamicRule rule;
        Visitor& visitor;

        void push_value(int i, int j, T&& t){
            m[i].push_back(t);
            visitor(i,j,m[i][j]);
        }

        void calc_single(int i, int j){
            if (seed_pred(i,j)){
                push_value(i,j,seed_gen(i,j));
            } else {
                // no real need as its a private function, to be removed
                if ((i+1 > (int)m.size()) || (j > (int)m[i].size()) ){
                    throw std::out_of_range(
                            "Recurrence base doesn't exist");
                }
                // How do we know its j-th place in m[i]? private function
                push_value(i,j,rule(i,j,m));
            }
        }
};

class P85Solver : public DynamicProgramming<int> {
    public:
        P85Solver(DynamicProgramming<int>::Visitor& visitor) : 
            DynamicProgramming<int> (base,
            [](int i, int j) { return ( 0 == i || 0 == j); },
            [](int, int) { return 0;},
            [](int i, int j, vector<vector<int> > &m) { 
            return m[i-1][j] + m[i][j-1] - m[i-1][j-1] + i*j;},
            visitor) {}
    private:
        static vector<vector<int> > base;

}; 
vector<vector<int> > P85Solver::base = 
    vector<vector<int> >(1, vector<int>(1,0));

class ClosestToN{
    public:
        ClosestToN(int n): n(n), x(0), y(0), closest(0) {}

        void operator()(int i, int j, int& t){
            if (abs(closest-n) > abs(t-n)){
                x = i;
                y = j;
                closest = t; // assignment op called as closest is not a ref
            }
        }
    public: // For easy access from outside
        int n;
        int x,y, closest;
};

class Printer{
    public:
        void operator()(int i, int j, int& t) {
            cout << "(" << i << " , " << j << ") = " << t << endl;
        }
};


int p85(int max_n){

    ClosestToN visi = ClosestToN(max_n);
    DynamicProgramming<int>::Visitor visitor = 
        std::bind(&ClosestToN::operator(), &visi, placeholders::_1,
                placeholders::_2, placeholders::_3);
    P85Solver dp(visitor);

    dp.calc_new_row();
    int closest ;
    int ind = 0;
    do {
        ++ind;
        closest = visi.closest;
        dp.calc_new_column();
    } while (closest != visi.closest ) ;
    cout << visi.closest << endl;
    cout << visi.x << " , " << visi.y << endl;

    for (int i = 0; i < ind; ++i){
        dp.calc_new_row();
    }


    cout << visi.closest << endl;
    cout << visi.x << " , " << visi.y << endl;
    return visi.x * visi.y;
}


int main(int argc, char** argv){

    DynamicProgramming<int>::Visitor printer = Printer();
    P85Solver dp(printer);

    dp.calc_new_row();
    dp.calc_new_row();
    dp.calc_new_column();
    dp.calc_new_column();
    dp.calc_new_column();


    if (argc == 2){
        string s(argv[1]);
        cout << p85(stoi(s)) << endl;
    }
    else{
        std::cout << p85(2000000) << std::endl;
    }
    return 0;
}


