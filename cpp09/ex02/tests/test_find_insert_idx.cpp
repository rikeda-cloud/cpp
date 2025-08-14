#include "PairPointer.hpp"
#include "test.hpp"
#include "utils.hpp"
#include <iostream>

std::vector<PairPointer> _create_pairs(void) {
  std::vector<unsigned> vec;
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(9);
  vec.push_back(11);
  vec.push_back(15);
  vec.push_back(100);
  return PairPointer::vecToPairVec(vec);
}

bool _exec_find_insert_idx(unsigned target, std::size_t right,
                           std::size_t expect_idx, std::size_t expect_cnt) {
  std::vector<PairPointer> pairs = _create_pairs();
  PairPointer target_pair = PairPointer(target, NULL, NULL);

  std::size_t cnt;
  std::size_t result = findInsertIdx(pairs, target_pair, right, cnt);

  if (result != expect_idx) {
    std::cout << "[ERROR] test_find_insert_idx: expect = " << expect_idx
              << " actual = " << result << std::endl;
    return true;
  }
  if (cnt != expect_cnt) {
    std::cout << "[ERROR] test_find_insert_idx: expect = " << expect_cnt
              << " actual = " << cnt << std::endl;
    return true;
  }
  return false;
}

int test_find_insert_idx(void) {
  std::size_t size = _create_pairs().size();

  int fail_count = _exec_find_insert_idx(2, size, 1, 3) +
                   _exec_find_insert_idx(4, size, 2, 3);

  if (fail_count == 0) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
