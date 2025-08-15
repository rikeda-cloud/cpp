#include "PmergeMe.hpp"
#include "utils.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

bool _exec_test_sort_vector(const std::vector<unsigned> &vec) {
  std::vector<unsigned> std_sorted_vec = vec;
  std::sort(std_sorted_vec.begin(), std_sorted_vec.end());
  std::vector<unsigned> pmerge_sorted_vec = PmergeMe::sort(vec);

  if (pmerge_sorted_vec == std_sorted_vec) {
    std::cout << "[OK]" << std::endl;
    return false;
  } else {
    std::cout << "[ERROR] test_sort_vector: " << std::endl;
    printContainer("Input:   ", vec);
    printContainer("Expect:  ", std_sorted_vec);
    printContainer("Actual:  ", pmerge_sorted_vec);
    return true;
  }
}

int test_sort_vector() {
  int fail_count = 0;

  // simple
  {
    unsigned arr[] = {5, 2, 4, 1, 3};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // duplicates
  {
    unsigned arr[] = {5, 2, 4, 2, 5};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // already sorted
  {
    unsigned arr[] = {1, 2, 3, 4, 5};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // reverse
  {
    unsigned arr[] = {9, 8, 7, 6, 5};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // Odd
  {
    unsigned arr[] = {10, 1, 2, 3, 4, 5};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // subject
  {
    int arr[] = {3, 5, 9, 7, 4};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // empty
  {
    int arr[] = {};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // one
  {
    int arr[] = {1};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // two
  {
    int arr[] = {2, 1};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // three
  {
    int arr[] = {2, 1, 3};
    std::vector<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  // Large random
  {
    std::vector<unsigned> vec;
    std::srand(std::time(0));
    for (int i = 0; i < 3000; ++i) {
      vec.push_back(std::rand() % 1000);
    }
    if (_exec_test_sort_vector(vec))
      fail_count++;
  }

  if (fail_count == 0) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
