#include "PairPointer.hpp"
#include "PmergeMe.hpp"
#include "utils.hpp"
#include <iostream>

void print_vector(const std::vector<unsigned> &vec) {
  for (std::vector<unsigned>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

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

  print_vector(vec);
  PairPointer::resetCmpCount();
  std::vector<unsigned> sorted_vec = PmergeMe::sort(vec);
  std::cout << "cmp_count = " << PairPointer::getCmpCount() << std::endl;
  print_vector(sorted_vec);

  return 0;
}
