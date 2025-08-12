#include "PmergeMe.hpp"
#include "test.hpp"

bool _exec_jacobsthal(unsigned n, unsigned expect) {
  return PmergeMe::jacobsthal(n) != expect;
}

int test_jacobsthal(void) {
  int fail_count = _exec_jacobsthal(1, 1) + _exec_jacobsthal(2, 1) +
                   _exec_jacobsthal(3, 3) + _exec_jacobsthal(4, 5) +
                   _exec_jacobsthal(5, 11) + _exec_jacobsthal(6, 21) +
                   _exec_jacobsthal(7, 43) + _exec_jacobsthal(8, 85) +
                   _exec_jacobsthal(9, 171);
  return fail_count;
}
