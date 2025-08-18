#include "PmergeMe.hpp"
#include "SortTestCase.hpp"
#include "utils.hpp"
#include <algorithm>

bool _exec_test_sort_vector(const std::vector<unsigned> &vec,
                            std::size_t expect_cmp_count) {
  std::vector<unsigned> std_sorted_vec = vec;
  std::sort(std_sorted_vec.begin(), std_sorted_vec.end());
  PairPointer::resetCmpCount();
  std::vector<unsigned> pmerge_sorted_vec = PmergeMe::sort(vec);
  std::size_t actual_cmp_count = PairPointer::getCmpCount();

  if (pmerge_sorted_vec != std_sorted_vec) {
    std::cout << "[ERROR] test_sort_vector: " << std::endl;
    printContainer("Input:   ", vec);
    printContainer("Expect:  ", std_sorted_vec);
    printContainer("Actual:  ", pmerge_sorted_vec);
    return true;
  }
  if (expect_cmp_count != SortTestCase::IGNORE_CMP &&
      expect_cmp_count != actual_cmp_count) {
    std::cout << "[ERROR] test_sort_vector: expect_cmp_count = "
              << expect_cmp_count << " actual_cmp_count = " << actual_cmp_count
              << std::endl;
    printContainer("Input:   ", vec);
    return true;
  }
  std::cout << "[OK]" << std::endl;
  return false;
}

bool _exec_test_sort_deque(const std::deque<unsigned> &deq,
                           std::size_t expect_cmp_count) {
  std::deque<unsigned> std_sorted_deq = deq;
  std::sort(std_sorted_deq.begin(), std_sorted_deq.end());
  PairPointer::resetCmpCount();
  std::deque<unsigned> pmerge_sorted_deq = PmergeMe::sort(deq);
  std::size_t actual_cmp_count = PairPointer::getCmpCount();

  if (pmerge_sorted_deq != std_sorted_deq) {
    std::cout << "[ERROR] test_sort_deque: " << std::endl;
    printContainer("Input:   ", deq);
    printContainer("Expect:  ", std_sorted_deq);
    printContainer("Actual:  ", pmerge_sorted_deq);
    return true;
  }
  if (expect_cmp_count != SortTestCase::IGNORE_CMP &&
      expect_cmp_count != actual_cmp_count) {
    std::cout << "[ERROR] test_sort_deque: expect_cmp_count = "
              << expect_cmp_count << " actual_cmp_count = " << actual_cmp_count
              << std::endl;
    printContainer("Input:   ", deq);
    return true;
  }
  std::cout << "[OK]" << std::endl;
  return false;
}

int test_sort(void) {
  int fail_count = 0;
  std::vector<SortTestCase> test_case = SortTestCase::createTestCase();

  // test sort vector
  for (std::vector<SortTestCase>::const_iterator it = test_case.begin();
       it != test_case.end(); ++it) {
    if (_exec_test_sort_vector(it->getInput(), it->getCmpCount())) {
      fail_count++;
    }
  }
  // test sort deque
  for (std::vector<SortTestCase>::const_iterator it = test_case.begin();
       it != test_case.end(); ++it) {
    std::deque<unsigned> input_deque(it->getInput().begin(),
                                     it->getInput().end());
    if (_exec_test_sort_deque(input_deque, it->getCmpCount())) {
      fail_count++;
    }
  }
  return fail_count;
}
