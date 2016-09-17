#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

typedef boost::multiprecision::cpp_int erez_int;

using namespace std;

class MagicNGon{
    public:
        MagicNGon(int n, int* outter, int* inner) : N(n) {
            // rotating
            int min_outter = *min_element(outter, outter+N);
            int min_ind = 0;
            while (outter[min_ind] != min_outter) {++min_ind;}
            // copying
            triplets = new int*[N];
            for (int triplet = 0; triplet < N; ++triplet){
                triplets[triplet] = new int[3];
                triplets[triplet][0] = outter[(0 + triplet + min_ind) % N];
                triplets[triplet][1] = inner[(1 + triplet + min_ind) % N];
                triplets[triplet][2] = inner[(2 + triplet + min_ind) % N];
            }
        }

        bool is_magic(){
            int magic = triplets[0][0] + triplets[0][1] + triplets[0][2];
            for (int triplet = 1; triplet < N; ++triplet){
                int sum = 0;
                for (int ind = 0; ind < 3; ++ind) {sum += triplets[triplet][ind];}
                if (sum != magic){
                    return false;
                }
            }
            return true;
        }

        erez_int get_value(){
            erez_int mult = 1;
            erez_int val = 0;
            for (int triplet = N-1; triplet >= 0 ; --triplet){
                for (int ind = 2; ind >= 0; --ind){
                    val += (mult * triplets[triplet][ind]);
                    if (10 <= triplets[triplet][ind]){
                        mult = mult * 100;
                    }
                    else{
                        mult = mult * 10;
                    }
                }
            }
            return val;
        }

        ~MagicNGon(){
            for (int triplet = 0; triplet < N; ++triplet){
                delete[] triplets[triplet];
            }
            delete[] triplets;
        }
    private:
        int N;
        int** triplets;
};

erez_int factorial(int n){
    if (n == 1) return 1;
    return n * factorial(n-1);
}

erez_int p68(int n){
    // specific code because yea..
    int* numbers = new int[2*n];
    int* numbers_pointer = numbers;
    int permutations = 2*n;
    erez_int max_value;
    for (int i = 0; i < 2*n; ++i){
        numbers[i] = i+1;
    }
    if (n == 5){
        ++numbers_pointer;
        --permutations;
        for (int i = 1; i < 2*n; ++i){
            numbers[i] = i;
        }
        numbers[0] = 10;
    }

    do{
        MagicNGon m(n, numbers, numbers + n);
        if (m.is_magic()){
            max_value = max(max_value, m.get_value());
        }
    } while(next_permutation(numbers_pointer, numbers_pointer + permutations));
    
    delete[] numbers;

    return max_value;
}


int main(){
    cout << p68(5) << endl;
}
