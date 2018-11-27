//
// Created by ubrdog on 11/26/18.
//

#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include <algorithm>
#include <iterator>

template <class RandomIt>
void siftDown(RandomIt first, RandomIt last) {

}

template <class RandomIt>
void heapify(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;

  diff_t largest = 1;
}

template <class RandomIt>
void heapsort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::swap;

  heapify(first, last);

  diff_t n = last - first;
  diff_t end = n - 1;
  while (end > 0) {
    swap(first[end], first[0]);
    end--;
    siftDown(first, first + end);
  }
}

#endif //SORTING_HEAPSORT_H
