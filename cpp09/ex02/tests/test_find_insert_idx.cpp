#include "PairPointer.hpp"
#include "test.hpp"
#include "utils.hpp"
#include <iostream>

bool _exec_find_insert_idx(const std::vector<PairPointer> &pairs,
                           const PairPointer &target_pair, std::size_t left,
                           std::size_t right, std::size_t expect) {
  std::size_t result = findInsertIdx(pairs, target_pair, left, right);
  bool fail = result != expect;

  if (fail) {
    std::cout << "[ERROR] test_jacobsthal: expect = " << expect
              << " actual = " << result << std::endl;
  }
  return fail;
}

int test_find_insert_idx(void) {
  std::vector<unsigned> vec;
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(9);
  vec.push_back(11);
  vec.push_back(15);
  vec.push_back(100);
  std::vector<PairPointer> pairs = PairPointer::vecToPairVec(vec);
  std::size_t size = pairs.size();

  int fail_count =
      _exec_find_insert_idx(pairs, PairPointer(2, NULL, NULL), 0, size, 1);

  if (fail_count == 0) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
