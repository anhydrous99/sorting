#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include <chrono>

#include "bubblesort.h"
#include "gnomesort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "shellsort.h"
#include "mergesort.h"
#include "selectionsort.h"

int main(int argc, char *argv[]) {
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
  std::cout << "Starting Builtin Sort\n";
  auto t1 = hrc::now();
  std::sort(default_vec.begin(), default_vec.end());
  auto t2 = hrc::now();

  // use Bubble Sort
  d_vector bsort_vec = random_vector;
  std::cout << "Starting Bubble Sort\n";
  auto t3 = hrc::now();
  bubblesort(bsort_vec.begin(), bsort_vec.end());
  auto t4 = hrc::now();

  // use Gnome Sort
  d_vector gsort_vec = random_vector;
  std::cout << "Starting Gnome Sort\n";
  auto t5 = hrc::now();
  gnomesort(gsort_vec.begin(), gsort_vec.end());
  auto t6 = hrc::now();

  // use Heap Sort
  d_vector heap_vec = random_vector;
  std::cout << "Starting Heapsort Sort\n";
  auto t7 = hrc::now();
  heapsort(heap_vec.begin(), heap_vec.end());
  auto t8 = hrc::now();

  // use Insertion Sort
  d_vector ins_vec = random_vector;
  std::cout << "Starting Insertion Sort\n";
  auto t9 = hrc::now();
  insertionsort(ins_vec.begin(), ins_vec.end());
  auto t10 = hrc::now();

  // use Shell Sort
  d_vector shell_vec = random_vector;
  std::cout << "Starting Shell Sort\n";
  auto t11 = hrc::now();
  shellsort(shell_vec.begin(), shell_vec.end());
  auto t12 = hrc::now();

  // use Merge Sort
  d_vector merge_vec = random_vector;
  std::cout << "Starting Merge Sort\n";
  auto t13 = hrc::now();
  mergesort(merge_vec.begin(), merge_vec.end());
  auto t14 = hrc::now();

  // use Selection Sort
  d_vector selection_vec = random_vector;
  std::cout << "Starting Selection Sort\n";
  auto t15 = hrc::now();
  selectionsort(selection_vec.begin(), selection_vec.end());
  auto t16 = hrc::now();

  // Output results
  std::cout << "std::sort: " << duration_cast<microseconds>(t2 - t1).count() << " microseconds\n";
  std::cout << "bubble sort: " << duration_cast<microseconds>(t4 - t3).count() << " microseconds\n";
  std::cout << "gnome sort: " << duration_cast<microseconds>(t6 - t5).count() << " microseconds\n";
  std::cout << "heap sort: " << duration_cast<microseconds>(t8 - t7).count() << " microseconds\n";
  std::cout << "insertion sort: " << duration_cast<microseconds>(t10 - t9).count() << " microseconds\n";
  std::cout << "shell sort: " << duration_cast<microseconds>(t12 - t11).count() << " microseconds\n";
  std::cout << "merge sort: " << duration_cast<microseconds>(t14 - t13).count() << " microseconds\n";
  std::cout << "selection sort: " << duration_cast<microseconds>(t16 - t15).count() << " microseconds\n";
  return 0;
}