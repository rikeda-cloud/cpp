#include "PmergeMe.hpp"
#include "PairPointer.hpp"
#include "utils.hpp"
#include <cstddef>

static std::vector<PairPointer> _create_pairs(std::vector<PairPointer> &pairs) {
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
  return new_pairs;
}

static void _sort(std::vector<PairPointer> &pairs) {
  if (pairs.size() <= 1) {
    return;
  }
  std::vector<PairPointer> new_pairs = _create_pairs(pairs);
  _sort(new_pairs); // INFO 再帰的にソート

  std::vector<PairPointer> sorted_pairs;
  sorted_pairs.push_back(new_pairs[0].getSmallPair());
  sorted_pairs.push_back(new_pairs[0].getLargePair());

  if (new_pairs.size() == 1) { // INFO ペアが1つしかない場合はそのまま返す
    pairs = sorted_pairs;
    return;
  }

  // INFO 大きい方の要素を全て挿入
  for (std::size_t i = 1; i < new_pairs.size(); ++i) {
    sorted_pairs.push_back(new_pairs[i].getLargePair());
  }

  std::size_t base_idx = 1;
  std::size_t n = 1;
  for (; base_idx < pairs.size();) {
    for (std::size_t i = jacobsthal(n++) * 2; i > 0; --i) {
      // std::size_t idx = findInsertIdx(sorted_pairs, , pairs[i - 1 +
      // base_idx]); sorted_pairs.insert(idx, pairs[i - 1 + base_idx]);
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
