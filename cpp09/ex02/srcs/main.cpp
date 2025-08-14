#include "PmergeMe.hpp"

int main(void) {
  std::vector<unsigned> vec;
  vec.push_back(9);
  vec.push_back(8);
  vec.push_back(7);
  vec.push_back(6);
  vec.push_back(5);
  vec.push_back(4);
  vec.push_back(3);
  vec.push_back(2);
  vec.push_back(1);

  PmergeMe::sort(vec);

  return 0;
}
