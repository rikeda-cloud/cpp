#include "PmergeMe.hpp"

unsigned PmergeMe::jacobsthal(unsigned n) {
  if (n <= 1)
    return n;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}
