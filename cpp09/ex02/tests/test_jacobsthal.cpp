#include "PmergeMe.hpp"
#include "test.hpp"
#include <iostream>

bool _exec_jacobsthal(unsigned n, unsigned expect) {
  unsigned result = PmergeMe::jacobsthal(n);
  bool fail = result != expect;

  if (fail) {
    std::cout << "[ERROR] test_jacobsthal: expect = " << expect
              << " actual = " << result << std::endl;
  }
  return fail;
}

int test_jacobsthal(void) {
  int fail_count = _exec_jacobsthal(1, 1) + _exec_jacobsthal(2, 1) +
                   _exec_jacobsthal(3, 3) + _exec_jacobsthal(4, 5) +
                   _exec_jacobsthal(5, 11) + _exec_jacobsthal(6, 21) +
                   _exec_jacobsthal(7, 43) + _exec_jacobsthal(8, 85) +
                   _exec_jacobsthal(9, 171) + _exec_jacobsthal(10, 341) +
                   _exec_jacobsthal(11, 683) + _exec_jacobsthal(12, 1365);

  if (fail_count == 0) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
