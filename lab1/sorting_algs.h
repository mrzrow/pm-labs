#ifndef SORTING_ALGS_H_
#define SORTING_ALGS_H_

#include <algorithm>

/**
 * Insert sort
 * @param a array to sort
 * @param size size of the array
 */
template<class T> void insertSort(T* a, long size) {
    T x;
    long i, j;

    for (i = 0; i < size; i++) {
        x = a[i];
  
        for ( j=i-1; j>=0 && a[j] > x; j--)
            a[j+1] = a[j];

        a[j+1] = x;
  }
}

/**
 * Building pyramid
 * @param k start index
 * @param n end index
 */
template<class T> void downHeap(T* a, long k, long n) {
    T new_elem;
    long child;
    new_elem = a[k];
  
    while(k <= n/2) {
        child = 2*k;
        if( child < n && a[child] < a[child+1] ) child++;
        if( new_elem >= a[child] ) break; 
        a[k] = a[child];
        k = child;
    }
    a[k] = new_elem;
}
/**
 * Heap sort
 * @param a array to sort
 * @param size size of the array
 */
template<class T> void heapSort(T* a, long size) {
    long i;
    T temp;

    for(i=size/2-1; i >= 0; i--)
        downHeap(a, i, size-1);

    for(i=size-1; i > 0; i--) {
        std::swap(a[i], a[0]);
        downHeap(a, 0, i-1);
    }
}

/**
 * Quick sort
 * @param a array to sort
 * @param size size of the array
 */
template<class T> void quickSortR(T* a, long size)
{
    long i = 0, j = size-1;
    T p = a[ size>>1 ];

    do {
        while ( a[i] < p ) i++;
        while ( a[j] > p ) j--;

        if (i <= j) {
            std::swap(a[i], a[j]);
            i++; j--;
        }
    } while ( i<=j );

    if ( j > 0 ) quickSortR(a, j);
    if ( size > i ) quickSortR(a+i, size-i);
}

/**
 * Wrapper for std::sort
 * @param a array to sort
 * @param size size of the array
 */
template<class T> void standartSort(T* a, long size) {
    std::sort(a, a + size);
}

#endif