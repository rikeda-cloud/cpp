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
  std::size_t cmp_count = 0;
  std::vector<unsigned> sorted_vec = PmergeMe::sort(vec, cmp_count);
  print_vector(sorted_vec);
  std::cout << "cmp_count = " << cmp_count << std::endl;

  return 0;
}
