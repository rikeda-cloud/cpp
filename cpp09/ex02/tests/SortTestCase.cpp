#include "SortTestCase.hpp"
#include "PmergeMe.hpp"
#include "utils.hpp"
#include <algorithm>
#include <ctime>
#include <string>

SortTestCase::SortTestCase(const std::vector<unsigned> vec, std::size_t cmp)
    : input_(vec), expect_cmp_count_(cmp) {}

SortTestCase::~SortTestCase(void) {}

SortTestCase::SortTestCase(const SortTestCase &other)
    : input_(other.input_), expect_cmp_count_(other.expect_cmp_count_) {}

SortTestCase &SortTestCase::operator=(const SortTestCase &other) {
  if (this != &other) {
    input_ = other.input_;
    expect_cmp_count_ = other.expect_cmp_count_;
  }
  return *this;
}

const std::vector<unsigned> &SortTestCase::getInput() const { return input_; }

std::size_t SortTestCase::getCmpCount() const { return expect_cmp_count_; }

std::vector<SortTestCase> SortTestCase::createTestCase(void) {
  std::vector<SortTestCase> test_cases;

  unsigned a1[] = {5, 2, 4, 1, 3};
  std::vector<unsigned> simple_case(a1, a1 + sizeof(a1) / sizeof(a1[0]));
  test_cases.push_back(SortTestCase(simple_case, 7));

  unsigned a2[] = {5, 2, 4, 2, 5};
  std::vector<unsigned> duplicates_case(a2, a2 + sizeof(a2) / sizeof(a2[0]));
  test_cases.push_back(SortTestCase(duplicates_case, 7));

  unsigned a3[] = {1, 2, 3, 4, 5};
  std::vector<unsigned> sorted_case(a3, a3 + sizeof(a3) / sizeof(a3[0]));
  test_cases.push_back(SortTestCase(sorted_case, 7));

  unsigned a4[] = {9, 8, 7, 6, 5};
  std::vector<unsigned> reverse_case(a4, a4 + sizeof(a4) / sizeof(a4[0]));
  test_cases.push_back(SortTestCase(reverse_case, 7));

  unsigned a5[] = {10, 1, 2, 3, 4, 5};
  std::vector<unsigned> even_case(a5, a5 + sizeof(a5) / sizeof(a5[0]));
  test_cases.push_back(SortTestCase(even_case, 7));

  unsigned a6[] = {3, 5, 9, 7, 4};
  std::vector<unsigned> subject_case(a6, a6 + sizeof(a6) / sizeof(a6[0]));
  test_cases.push_back(SortTestCase(subject_case, 7));

  unsigned a8[] = {1};
  std::vector<unsigned> one_case(a8, a8 + sizeof(a8) / sizeof(a8[0]));
  test_cases.push_back(SortTestCase(one_case, 0));

  unsigned a9[] = {2, 1};
  std::vector<unsigned> two_case(a9, a9 + sizeof(a9) / sizeof(a9[0]));
  test_cases.push_back(SortTestCase(two_case, 1));

  unsigned a10[] = {2, 1, 3};
  std::vector<unsigned> three_case(a10, a10 + sizeof(a10) / sizeof(a10[0]));
  test_cases.push_back(SortTestCase(three_case, 3));

  std::vector<unsigned> empty_case;
  test_cases.push_back(SortTestCase(empty_case, 0));

  std::srand(std::time(0));
  std::vector<unsigned> random_case;
  for (unsigned i = 0; i < 1000; ++i) {
    random_case.push_back(std::rand() % 1000);
  }
  test_cases.push_back(SortTestCase(random_case, IGNORE_CMP));

  std::vector<unsigned> random_odd_case;
  for (unsigned i = 0; i < 4321; ++i) {
    random_case.push_back(std::rand() % 1000);
  }
  test_cases.push_back(SortTestCase(random_odd_case, IGNORE_CMP));

  return test_cases;
}
