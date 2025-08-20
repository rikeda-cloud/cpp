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

  unsigned a1[] = {1};
  std::vector<unsigned> case1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
  test_cases.push_back(SortTestCase(case1, 0));

  unsigned a2[] = {2, 1};
  std::vector<unsigned> case2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
  test_cases.push_back(SortTestCase(case2, 1));

  unsigned a3[] = {2, 1, 0};
  std::vector<unsigned> case3(a3, a3 + sizeof(a3) / sizeof(a3[0]));
  test_cases.push_back(SortTestCase(case3, 3));

  unsigned a4[] = {2, 1, 0, 4};
  std::vector<unsigned> case4(a4, a4 + sizeof(a4) / sizeof(a4[0]));
  test_cases.push_back(SortTestCase(case4, 5));

  unsigned a5[] = {1, 4, 2, 3, 0};
  std::vector<unsigned> case5(a5, a5 + sizeof(a5) / sizeof(a5[0]));
  test_cases.push_back(SortTestCase(case5, 7));

  unsigned a6[] = {5, 1, 4, 2, 3, 0};
  std::vector<unsigned> case6(a6, a6 + sizeof(a6) / sizeof(a6[0]));
  test_cases.push_back(SortTestCase(case6, 10));

  unsigned a7[] = {6, 1, 5, 2, 3, 4, 0};
  std::vector<unsigned> case7(a7, a7 + sizeof(a7) / sizeof(a7[0]));
  test_cases.push_back(SortTestCase(case7, 13));

  unsigned a8[] = {8, 1, 6, 2, 7, 3, 5, 4};
  std::vector<unsigned> case8(a8, a8 + sizeof(a8) / sizeof(a8[0]));
  test_cases.push_back(SortTestCase(case8, 16));

  unsigned a9[] = {9, 1, 6, 2, 7, 3, 5, 4, 8};
  std::vector<unsigned> case9(a9, a9 + sizeof(a9) / sizeof(a9[0]));
  test_cases.push_back(SortTestCase(case9, 19));

  unsigned a10[] = {10, 1, 7, 2, 8, 3, 6, 4, 9, 5};
  std::vector<unsigned> case10(a10, a10 + sizeof(a10) / sizeof(a10[0]));
  test_cases.push_back(SortTestCase(case10, 22));

  unsigned a12[] = {12, 1, 6, 2, 7, 3, 5, 4, 8, 9, 10, 11};
  std::vector<unsigned> case12(a12, a12 + sizeof(a12) / sizeof(a12[0]));
  test_cases.push_back(SortTestCase(case12, 30));

  unsigned a13[] = {13, 1, 6, 2, 7, 3, 5, 4, 8, 9, 10, 11, 12};
  std::vector<unsigned> case13(a13, a13 + sizeof(a13) / sizeof(a13[0]));
  test_cases.push_back(SortTestCase(case13, 34));

  unsigned a15[] = {15, 1, 6, 2, 7, 3, 5, 4, 8, 9, 10, 11, 12, 13, 14};
  std::vector<unsigned> case15(a15, a15 + sizeof(a15) / sizeof(a15[0]));
  test_cases.push_back(SortTestCase(case15, 42));

  unsigned a17[] = {17, 1, 6, 2, 7, 3, 5, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::vector<unsigned> case17(a17, a17 + sizeof(a17) / sizeof(a17[0]));
  test_cases.push_back(SortTestCase(case17, 50));

  unsigned a19[] = {19, 1,  6,  2,  7,  3,  5,  4,  8, 9,
                    10, 11, 12, 13, 14, 15, 16, 17, 18};
  std::vector<unsigned> case19(a19, a19 + sizeof(a19) / sizeof(a19[0]));
  test_cases.push_back(SortTestCase(case19, 58));

  unsigned a20[] = {20, 1, 12, 2, 16, 3, 11, 4, 19, 5,
                    14, 6, 18, 7, 13, 8, 17, 9, 15, 10};
  std::vector<unsigned> case20(a20, a20 + sizeof(a20) / sizeof(a20[0]));
  test_cases.push_back(SortTestCase(case20, 62));

  unsigned a21[] = {21, 1,  13, 2,  17, 3,  12, 4,  20, 5, 15,
                    6,  19, 7,  14, 8,  18, 9,  16, 10, 11};
  std::vector<unsigned> case21(a21, a21 + sizeof(a21) / sizeof(a21[0]));
  test_cases.push_back(SortTestCase(case21, 66));

  unsigned dup[] = {5, 2, 4, 2, 5};
  std::vector<unsigned> duplicate_case(dup, dup + sizeof(dup) / sizeof(dup[0]));
  test_cases.push_back(SortTestCase(duplicate_case, IGNORE_CMP));

  unsigned sbj[] = {3, 5, 9, 7, 4};
  std::vector<unsigned> subject_case(sbj, sbj + sizeof(sbj) / sizeof(sbj[0]));
  test_cases.push_back(SortTestCase(subject_case, IGNORE_CMP));

  std::vector<unsigned> empty_case;
  test_cases.push_back(SortTestCase(empty_case, 0));

  std::srand(std::time(0));
  std::vector<unsigned> random_case;
  for (unsigned i = 0; i < 3000; ++i) {
    random_case.push_back(std::rand() % 1000);
  }
  test_cases.push_back(SortTestCase(random_case, IGNORE_CMP));

  std::vector<unsigned> random_odd_case;
  for (unsigned i = 0; i < 4321; ++i) {
    random_odd_case.push_back(std::rand() % 1000);
  }
  test_cases.push_back(SortTestCase(random_odd_case, IGNORE_CMP));

  // INFO
  // 挿入する値が次に挿入する要素のペア(大)よりも大きい場合、次に挿入する要素は探索範囲を狭くできる
  unsigned max_effi[] = {1, 2, 5, 6, 3, 4};
  std::vector<unsigned> maximum_efficiency_case(
      max_effi, max_effi + sizeof(max_effi) / sizeof(max_effi[0]));
  test_cases.push_back(SortTestCase(maximum_efficiency_case, 9));

  return test_cases;
}
