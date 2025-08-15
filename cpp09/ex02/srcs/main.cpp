#include "PairPointer.hpp"
#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

void print_vector(const std::vector<unsigned> &vec) {
  for (std::vector<unsigned>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "argc < 2" << std::endl;
    return 1;
  }

  std::vector<unsigned> vec;
  for (int i = 1; i < argc; ++i) {
    std::istringstream iss(argv[i]);
    unsigned num;
    if (iss >> num) {
      vec.push_back(num);
    } else {
      std::cerr << "Invalid arg: " << argv[i] << std::endl;
      return 1;
    }
  }

  print_vector(vec);
  PairPointer::resetCmpCount();
  std::vector<unsigned> sorted_vec = PmergeMe::sort(vec);
  std::cout << "cmp_count = " << PairPointer::getCmpCount() << std::endl;
  print_vector(sorted_vec);

  return 0;
}
