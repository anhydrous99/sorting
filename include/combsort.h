//
// Created by arman on 11/30/2018.
//

#ifndef SORTING_COMBSORT_H
#define SORTING_COMBSORT_H

#include <iterator>
#include <algorithm>
#include <cmath>

template<class RandomIt>
void combsort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::floor;
  using std::swap;

  diff_t n = last - first;
  diff_t gap = n;
  double shrink = 1.3;
  bool sorted = false;

  while (!sorted) {
    gap = static_cast<diff_t>(floor(gap / shrink));
    if (gap <= 1) {
      gap = 1;
      sorted = true;
    }

    for (diff_t i = 0; i + gap < n; i++) {
      if (first[i] > first[i + gap]) {
        swap(first[i], first[i + gap]);
        sorted = false;
      }
    }
  }
}

#endif //SORTING_COMBSORT_H
