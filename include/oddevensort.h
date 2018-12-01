//
// Created by arman on 11/30/2018.
// can be parallelized
//

#ifndef SORTING_ODDEVENSORT_H
#define SORTING_ODDEVENSORT_H

#include <iterator>
#include <algorithm>

template<class RandomIt>
void oddevensort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::swap;

  bool sorted = false;
  diff_t n = last - first;
  while (!sorted) {
    sorted = true;
    for (diff_t i = 1; i < n - 1; i += 2) {
      if (first[i] > first[i + 1]) {
        swap(first[i], first[i + 1]);
        sorted = false;
      }
    }

    for (diff_t i = 0; i < n - 1; i += 2) {
      if (first[i] > first[i + 1]) {
        swap(first[i], first[i + 1]);
        sorted = false;
      }
    }
  }
}

#endif //SORTING_ODDEVENSORT_H
