//
// Created by arman on 11/29/2018.
//

#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include <iterator>

template<class RandomIt>
void insertionsort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  typedef typename std::iterator_traits<RandomIt>::value_type val_t;

  diff_t n = last - first;

  for (diff_t i = 1; i < n; i++) {
    val_t x = first[i];
    diff_t j = i - 1;
    for (; j >= 0 && first[j] > x; j--)
      first[j + 1] = first[j];

    first[j + 1] = x;
  }
}

#endif //SORTING_INSERTIONSORT_H
