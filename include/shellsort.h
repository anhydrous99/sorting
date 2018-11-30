//
// Created by arman on 11/29/2018.
// Using A036562 -> O(n^(4/3))
//

#ifndef SORTING_SHELLSORT_H
#define SORTING_SHELLSORT_H

#include <algorithm>
#include <iterator>

template<class RandomIt>
void shellsort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  typedef typename std::iterator_traits<RandomIt>::value_type val_t;

  diff_t n = last - first;
  diff_t gap[13] = {16783361, 4197377, 1050113, 262913, 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1};

  for (diff_t g = 12; g >= 0; g--) {
    for (diff_t i = gap[g]; i < n; i += 1) {
      val_t tmp = first[i];

      diff_t j;
      for (j = i; j >= gap[g] && first[j - gap[g]] > tmp; j -= gap[g])
        first[j] = first[j - gap[g]];
      first[j] = tmp;
    }
  }
}

#endif //SORTING_SHELLSORT_H
