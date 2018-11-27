//
// Created by ubrdog on 11/26/18.
//

#ifndef SORTING_GNOMESORT_H
#define SORTING_GNOMESORT_H

#include <algorithm>
#include <iterator>

template <class RandomIt>
void gnomesort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
  using std::swap;

  diff_t begin = 1;
  diff_t n = last - first;
  while (begin < n) {
    if (first[begin - 1] <= first[begin])
      begin++;
    else {
      swap(first[begin - 1], first[begin]);
      if (--begin == 0)
        begin = 1;
    }
  }
}

#endif //SORTING_GNOMESORT_H
