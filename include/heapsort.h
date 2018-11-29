//
// Created by ubrdog on 11/26/18.
//

#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include <algorithm>
#include <iterator>

template <class RandomIt>
void heapify(RandomIt first, typename std::iterator_traits<RandomIt>::difference_type n,
             typename std::iterator_traits<RandomIt>::difference_type i) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::swap;

  diff_t largest = i;
  diff_t l = 2 * i + 1;
  diff_t r = 2 * i + 2;

  if (l < n && first[l] > first[largest])
    largest = l;

  if (r < n && first[r] > first[largest])
    largest = r;

  if (largest != i) {
    swap(first[i], first[largest]);
    heapify(first, n, largest);
  }
}

template <class RandomIt>
void heapsort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::swap;

  diff_t n = last - first;

  for (diff_t i = n / 2 - 1; i >= 0; i--)
    heapify(first, n, i);

  for (diff_t i = n - 1; i >= 0; i--) {
    swap(first[0], first[i]);
    heapify(first, i, 0);
  }
}

#endif //SORTING_HEAPSORT_H
