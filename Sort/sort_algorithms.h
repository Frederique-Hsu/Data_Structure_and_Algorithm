#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

    #include <vector>
    using namespace std;

    template<typename T> void insertion_sort(T data[], int n);
    template<typename T> void selection_sort(T data[], int n);
    template<typename T> void bubble_sort(T data[], int n);
    template<typename T> void comb_sort(T data[], int n);
    template<typename T> void heap_sort(T data[], int size);
    template<typename T> void quick_sort(T data[], int first, int last);
    template<typename T> void quick_sort(T data[], int n);

    #include "sort_algorithms.cpp"

#endif  /* SORT_ALGORITHMS_H */
