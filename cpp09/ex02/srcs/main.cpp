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

  timeval start, end;

  printContainer(vec, "Before:  ");
  PairPointer::resetCmpCount();
  gettimeofday(&start, NULL);
  std::vector<unsigned> sorted_vec = PmergeMe::sort(vec);
  gettimeofday(&end, NULL);
  printContainer(sorted_vec, "After:   ");
  printTimeInfo(sorted_vec.size(), "vector", start, end);

  // std::cout << "cmp_count = " << PairPointer::getCmpCount() << std::endl;

  return 0;
}
