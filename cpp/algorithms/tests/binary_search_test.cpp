#include <iostream>
#include "binary_search.h"
using namespace std;

class IntPred : public Predicate<int> {
    public:
        IntPred(int k) : n(k) {}
        int operator()(int x) { return x-n; }
    private:
        int n;
};

int test_case(int* arr, int n){
    IntPred pred(2);
    int *s = binary_search<int>(arr, n, pred);
    if (0 == s){
        cout << "fail, s==0" << endl;
    }
    else{
        cout << *s << endl;
    }
}



int main(){
    int arr1[] = {1,2,3,4};
    test_case(arr1, sizeof(arr1)/sizeof(int));
    int arr2[] = {1,2,4};
    test_case(arr2, sizeof(arr2)/sizeof(int));
    int arr3[] = {1,2,3,4,5};
    test_case(arr3, sizeof(arr3)/sizeof(int));
    int arr4[] = {1,3,4,5};
    test_case(arr4, sizeof(arr4)/sizeof(int));

    IntPred pred(2), pred2(10);
    cout << binary_search_int_seq(0, 2, pred) << endl;
    cout << binary_search_int_seq(2, 10, pred) << endl;
    cout << binary_search_int_seq(1, 3, pred) << endl;
    cout << binary_search_int_seq(0, 4, pred) << endl;
    cout << binary_search_int_seq(1, 4, pred) << endl;
    cout << binary_search_int_seq(-2, 1, pred) << endl;
    cout << binary_search_int_seq(0, 4, pred2) << endl;
    


    return 0;
}
