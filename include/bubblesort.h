//
// Created by ubrdog on 11/26/18.
//

#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include <algorithm>
#include <iterator>

template <class RandomIt>
void bubblesort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::swap;

  diff_t n = last - first;
  diff_t newn;
  while( n > 1 ) {
    newn = 0;
    for (diff_t i = 1; i < n; i++) {
      if (first[i - 1] > first[i]) {
        swap(first[i - 1], first[i]);
        newn = i;
      }
    }
    n = newn;
  }
}

#endif //SORTING_BUBBLESORT_H
