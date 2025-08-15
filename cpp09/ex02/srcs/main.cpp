#include "PairPointer.hpp"
#include "PmergeMe.hpp"
#include "utils.hpp"
#include <iostream>
#include <sys/time.h>

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

  timeval start, end;

  printContainer("Before:  ", vec);
  PairPointer::resetCmpCount();
  gettimeofday(&start, NULL);
  std::vector<unsigned> sorted_vec = PmergeMe::sort(vec);
  gettimeofday(&end, NULL);
  printContainer("After:   ", sorted_vec);
  printTimeInfo(sorted_vec.size(), "vector", start, end);
  std::cout << "cmp_count = " << PairPointer::getCmpCount() << std::endl;

  gettimeofday(&start, NULL);
  std::deque<unsigned> sorted_deq = PmergeMe::sort(deq);
  gettimeofday(&end, NULL);
  printTimeInfo(sorted_vec.size(), "deque ", start, end);

  return 0;
}
