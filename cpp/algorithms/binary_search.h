/* General functions for binary search in arrays
 *
 * Binary search functions get an array of length n, 
 * They search in an object in the array that satisfies a Predicate*.
 * Assuming the array is sorted* the function will find such object if it exists in the array
 * and will do so in O(log(n)) time.
 *
 *
 */

#ifndef __BINARY_SEARCH_H
#define __BINARY_SEARCH_H

template <typename T>
class Predicate{
    public:
        virtual int operator()(T) = 0;
};

// function binary_search
template <typename T>
T* binary_search(T* array, int size, Predicate<T>& pred);


// function binary_search
template <typename T>
T* binary_search(T* array, int size, Predicate<T>& pred){

    if (1 == size){
        if (0 == pred(array[0]))
            return array;
        else
            return 0; // NULL
    }

    int d = pred(array[size/2]);
    if (d == 0)
        return &( array[size/2] );
    if (d > 0)
        return binary_search(array, size/2, pred);
    else // (d < 0)
        return binary_search(array + size/2, (size/2) + (size%2), pred);
}


/* Binary search on the range [min, max].
 *
 * returns min-1 if there is not solution.
 */
int binary_search_int_seq(int min, int max, Predicate<int>& pred);


// function lion_in_desert

#endif //__BINARY_SEARCH_H
