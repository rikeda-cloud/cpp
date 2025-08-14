#include "PmergeMe.hpp"
#include "PairPointer.hpp"

#include <cstddef>

unsigned PmergeMe::jacobsthal(unsigned n) {
  if (n <= 1)
    return n;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

static void _sort(std::vector<PairPointer> &pairs) {
  if (pairs.size() <= 1) {
    return;
  }

  std::vector<PairPointer> new_pairs;
  for (std::size_t i = 1; i < pairs.size(); i += 2) {
    PairPointer *small = NULL;
    PairPointer *large = NULL;
    if (pairs[i - 1] < pairs[i]) { // INFO 大小比較しながらペアを作成
      small = &pairs[i - 1];
      large = &pairs[i];
    } else {
      small = &pairs[i];
      large = &pairs[i - 1];
    }
    new_pairs.push_back(PairPointer(large->getVal(), small, large));
  }

  _sort(new_pairs); // INFO 再帰的にソート
}

std::vector<unsigned> PmergeMe::sort(const std::vector<unsigned> &src) {
  // std::vector<unsigned> -> std::vector<PairPointer>

  // std::vector<PairPointer>を引数に取る再帰関数でソート

  // std::vector<PairPointer> -> std::vector<unsigned>
  return src;
}
