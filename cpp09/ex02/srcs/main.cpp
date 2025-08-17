#include "PairPointer.hpp"
#include "PmergeMe.hpp"
#include "utils.hpp"
#include <ctime>
#include <iostream>

int main(int argc, const char **argv) {
  if (argc < 2) {
    std::cerr << "[ERROR] argc < 2" << std::endl;
    return 1;
  }
  std::vector<unsigned> vec = argvToUintVec(argc, argv);
  if (vec.empty()) {
    std::cerr << "[ERROR] Invalid input" << std::endl;
    return 1;
  }
  std::deque<unsigned> deq(vec.begin(), vec.end());

  clock_t start, end;

  printContainer("Before:  ", vec);
  PairPointer::resetCmpCount();
  start = clock();
  std::vector<unsigned> sorted_vec = PmergeMe::sort(vec);
  end = clock();
  printContainer("After:   ", sorted_vec);
  printTimeInfo(sorted_vec.size(), "vector", start, end);
  // std::cout << "cmp_count = " << PairPointer::getCmpCount() << std::endl;

  PairPointer::resetCmpCount();
  start = clock();
  std::deque<unsigned> sorted_deq = PmergeMe::sort(deq);
  end = clock();
  printTimeInfo(sorted_deq.size(), "deque ", start, end);
  // std::cout << "cmp_count = " << PairPointer::getCmpCount() << std::endl;

  return 0;
}
