//
// Created by arman on 11/29/2018.
//

#ifndef SORTING_MERGESORT_H
#define SORTING_MERGESORT_H

#include <iterator>
#include <algorithm>

template<class RandomIt>
void ButtomUpMerge(RandomIt first, typename std::iterator_traits<RandomIt>::difference_type iLeft,
                   typename std::iterator_traits<RandomIt>::difference_type iRight,
                   typename std::iterator_traits<RandomIt>::difference_type iEnd,
                   typename std::iterator_traits<RandomIt>::value_type Bfirst[]) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  typedef typename std::iterator_traits<RandomIt>::value_type val_t;
  diff_t i = iLeft, j = iRight;
  for (diff_t k = iLeft; k < iEnd; k++) {
    if (i < iRight && (j >= iEnd || first[i] <= first[j])) {
      Bfirst[k] = first[i];
      i++;
    } else {
      Bfirst[k] = first[j];
      j++;
    }
  }
}

template<class RandomIt>
void mergesort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  typedef typename std::iterator_traits<RandomIt>::value_type val_t;
  using std::copy;
  using std::min;

  diff_t n = last - first;
  val_t *B = new val_t[n];
  for (diff_t width = 1; width < n; width = 2 * width) {
    for (diff_t i = 0; i < n; i += 2 * width) {
      ButtomUpMerge(first, i, min(i + width, n), min(i + 2 * width, n), B);
    }
    copy(B, B + n, first);
  }
  delete[] B;
}

#endif //SORTING_MERGESORT_H
