/* General functions for binary search in arrays
 *
 * Binary search functions get an array of length n, 
 * They search in an object in the array that satisfies a Predicate*.
 * Assuming the array is sorted* the function will find such object if it exists in the array
 * and will do so in O(log(n)) time.
 *
 *
 */

#include "binary_search.h"

//#include <iostream>
//using namespace std;

int binary_search_int_seq(int min, int max, Predicate<int>& pred){


    if (min == max){
        if (0 == pred(min))
            return min;
        return min-1;
    }

    int size = max - min + 1;
    int mid = min + (size/2);

    int d = pred(mid);

    //cout << min << ", " << max << ", " << mid << ", " << d << endl;

    if (d == 0)
        return mid;
    if (d > 0)
        return binary_search_int_seq(min, mid - 1 , pred);
    else{ // (d < 0){
        int s = binary_search_int_seq(mid, max, pred);
        if (s < mid)
            return min - 1;
        return s;
    }
}


// function lion_in_desert

