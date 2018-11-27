#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include <chrono>

#include "bubblesort.h"
#include "gnomesort.h"
#include "heapsort.h"

int main() {
  using namespace std::chrono;
  typedef high_resolution_clock hrc;
  typedef std::vector<double> d_vector;

  // init random number creating objects
  std::random_device d;
  std::mt19937 gen(d());
  // Set iterval for random numbers [0,100]
  std::uniform_real_distribution<double> dis(1.0, 100.0);
  // Init vector with space for 10000 doubles
  d_vector random_vector(10000);
  // Fill random_vector with random numbers
  std::generate(random_vector.begin(), random_vector.end(), [&](){ return dis(gen); });

  // use built in sorting
  d_vector default_vec = random_vector; // Copy for sorting
  auto t1 = hrc::now();
  std::sort(default_vec.begin(), default_vec.end());
  auto t2 = hrc::now();

  // use Bubble Sort
  d_vector bsort_vec = random_vector;
  auto t3 = hrc::now();
  bubblesort(bsort_vec.begin(), bsort_vec.end());
  auto t4 = hrc::now();

  // use Gnome Sort
  d_vector gsort_vec = random_vector;
  auto t5 = hrc::now();
  gnomesort(gsort_vec.begin(), gsort_vec.end());
  auto t6 = hrc::now();

  // Output results
  std::cout << "std::sort: " << duration_cast<microseconds>(t2 - t1).count() << " microseconds\n";
  std::cout << "bubble sort: " << duration_cast<milliseconds>(t4 - t3).count() << " milliseconds\n";
  std::cout << "gnome sort: " << duration_cast<milliseconds>(t6 - t5).count() << " milliseconds\n";
  return 0;
}