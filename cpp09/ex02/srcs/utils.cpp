#include "utils.hpp"

unsigned jacobsthal(unsigned n) {
  if (n <= 1)
    return n;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::size_t findInsertIdx(const std::vector<PairPointer> &sorted_pairs,
                          const PairPointer &target_pair, std::size_t left_idx,
                          std::size_t right_idx) {
  while (left_idx <= right_idx) {
    std::size_t middle_idx = (left_idx + right_idx) / 2;
    PairPointer middle_pair = sorted_pairs[middle_idx];

    if (target_pair < middle_pair) {
      right_idx = middle_idx - 1;
      continue;
    }
    if (target_pair > middle_pair) {
      left_idx = middle_idx + 1;
      continue;
    }
    return middle_idx;
  }
  return left_idx;
}
