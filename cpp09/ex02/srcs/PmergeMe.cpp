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

  std::vector<PairPointer> sorted_pairs;
  sorted_pairs.push_back(new_pairs[0].getSmallPair());
  sorted_pairs.push_back(new_pairs[0].getLargePair());

  for (std::size_t i = 1;; i++) {
    std::size_t j = PmergeMe::jacobsthal(i);
    while (j) {
      j--;
      // std::size_t idx = findInsertIdx(sorted_pairs, new_pairs[j]);
      // sorted_pairs.insert(idx, new_pairs[i]);
    }
  }

  if (pairs.size() % 2 == 1) { // INFO 奇数の場合の残りの要素を挿入
    // std::size_t idx = findInsertIdx(sorted_pairs, pairs.back());
    // sorted_pairs.insert(idx, pairs.back());
  }
  pairs = sorted_pairs;
}

std::vector<unsigned> PmergeMe::sort(const std::vector<unsigned> &src) {
  std::vector<PairPointer> pairs = PairPointer::vecToPairVec(src);
  _sort(pairs);
  return PairPointer::pairVecToVec(pairs);
}
