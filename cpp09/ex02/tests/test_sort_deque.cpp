#include "PmergeMe.hpp"
#include "utils.hpp"
#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <string>

bool _exec_test_sort_deque(const std::deque<unsigned> &vec) {
  std::deque<unsigned> std_sorted_vec = vec;
  std::sort(std_sorted_vec.begin(), std_sorted_vec.end());
  std::deque<unsigned> pmerge_sorted_vec = PmergeMe::sort(vec);

  if (pmerge_sorted_vec == std_sorted_vec) {
    std::cout << "[OK]" << std::endl;
    return false;
  } else {
    std::cout << "[ERROR] test_sort_deque: " << std::endl;
    printContainer("Input:   ", vec);
    printContainer("Expect:  ", std_sorted_vec);
    printContainer("Actual:  ", pmerge_sorted_vec);
    return true;
  }
}

int test_sort_deque() {
  int fail_count = 0;

  // simple
  {
    unsigned arr[] = {5, 2, 4, 1, 3};
    std::deque<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // duplicates
  {
    unsigned arr[] = {5, 2, 4, 2, 5};
    std::deque<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // already sorted
  {
    unsigned arr[] = {1, 2, 3, 4, 5};
    std::deque<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // reverse
  {
    unsigned arr[] = {9, 8, 7, 6, 5};
    std::deque<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // Odd
  {
    unsigned arr[] = {10, 1, 2, 3, 4, 5};
    std::deque<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // subject
  {
    int arr[] = {3, 5, 9, 7, 4};
    std::deque<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // empty
  {
    std::deque<unsigned> vec;
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // one
  {
    std::deque<unsigned> vec;
    vec.push_back(1);
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // two
  {
    std::deque<unsigned> vec;
    vec.push_back(2);
    vec.push_back(1);
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // three
  {
    std::deque<unsigned> vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // same number
  {
    int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1};
    std::deque<unsigned> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  std::srand(std::time(0));

  // Large random
  {
    std::deque<unsigned> vec;
    for (int i = 0; i < 3000; ++i) {
      vec.push_back(std::rand() % 1000);
    }
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  // Large random odd
  {
    std::deque<unsigned> vec;
    for (int i = 0; i < 12345; ++i) {
      vec.push_back(std::rand() % 100000);
    }
    if (_exec_test_sort_deque(vec))
      fail_count++;
  }

  if (fail_count == 0) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
