//
// Created by arman on 11/29/2018.
//

#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include <iterator>
#include <algorithm>

template<class RandomIt>
void selectionsort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::swap;

  diff_t i, j;
  diff_t n = last - first;

  for (j = 0; j < n - 1; j++) {
    diff_t iMin = j;
    for (i = j + 1; i < n; i++) {
      if (first[i] < first[iMin])
        iMin = i;
    }
    if (iMin != j)
      swap(first[j], first[iMin]);
  }
}

#endif //SORTING_SELECTIONSORT_H
