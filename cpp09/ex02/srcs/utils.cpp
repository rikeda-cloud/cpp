#include "utils.hpp"

unsigned jacobsthal(unsigned n) {
  if (n <= 1)
    return n;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::size_t findInsertIdx(const std::vector<PairPointer> &sorted_pairs,
                          const PairPointer &target_pair, std::size_t right_idx,
                          std::size_t &cmp_count) {
  std::size_t left_idx = 0;
  while (left_idx <= right_idx) {
    cmp_count++;
    std::size_t middle_idx = (left_idx + right_idx) / 2;
    PairPointer middle_pair = sorted_pairs[middle_idx];

    if (target_pair < middle_pair) {
      if (middle_idx == 0) {
        return 0;
      }
      right_idx = middle_idx - 1;
    } else if (target_pair > middle_pair) {
      if (middle_idx >= sorted_pairs.size()) {
        return sorted_pairs.size();
      }
      left_idx = middle_idx + 1;
    } else {
      return middle_idx;
    }
  }
  return left_idx;
}
