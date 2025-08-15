#include "PmergeMe.hpp"
#include "PairPointer.hpp"
#include "utils.hpp"
#include <cstddef>
#include <iostream>

// vector sort
static std::vector<PairPointer>
_create_larger_pairs(std::vector<PairPointer> &pairs) {
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
  std::vector<PairPointer> larger_pairs = _create_larger_pairs(pairs);
  _sort(larger_pairs); // INFO 再帰的にソート

  std::vector<PairPointer> main_chain;
  // INFO 最小の要素をMainChainに追加
  main_chain.push_back(larger_pairs[0].getSmallPair());
  // INFO 大きい方の要素を全て挿入
  for (std::size_t i = 0; i < larger_pairs.size(); ++i) {
    main_chain.push_back(larger_pairs[i].getLargePair());
  }

  if (pairs.size() == 2) { // INFO 要素が1ペア分しかない場合はそのまま返す
    pairs = main_chain;
    return;
  }

  std::size_t base_idx = 1;
  std::size_t loop_finish_size = larger_pairs.size() * 2;
  larger_pairs.erase(larger_pairs.begin());
  for (std::size_t i = 1; main_chain.size() < loop_finish_size; ++i) {
    std::size_t idx = jacobsthal(i) * 2;
    if (idx > larger_pairs.size()) {
      idx = larger_pairs.size();
    }
    std::size_t right_idx = base_idx + idx;
    for (std::size_t j = idx; j > 0; --j) {
      PairPointer target_pair = larger_pairs[j - 1].getSmallPair();
      std::vector<PairPointer>::iterator insert_pos = std::lower_bound(
          main_chain.begin(), main_chain.begin() + right_idx, target_pair);
      main_chain.insert(insert_pos, target_pair);
      larger_pairs.erase(larger_pairs.begin() + j - 1);
    }
    base_idx += idx * 2;
  }

  if (pairs.size() % 2 == 1) { // INFO 奇数の場合の残りの要素を挿入
    std::vector<PairPointer>::iterator insert_pos =
        std::lower_bound(main_chain.begin(), main_chain.end(), pairs.back());
    main_chain.insert(insert_pos, pairs.back());
  }
  pairs = main_chain;
}

std::vector<unsigned> PmergeMe::sort(const std::vector<unsigned> &src) {
  std::vector<PairPointer> pairs = PairPointer::vecToPairVec(src);
  _sort(pairs);
  return PairPointer::pairVecToVec(pairs);
}

// deque sort
static std::deque<PairPointer>
_create_larger_pairs(std::deque<PairPointer> &pairs) {
  std::deque<PairPointer> new_pairs;
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

static void _sort(std::deque<PairPointer> &pairs) {
  if (pairs.size() <= 1) {
    return;
  }
  std::deque<PairPointer> larger_pairs = _create_larger_pairs(pairs);
  _sort(larger_pairs); // INFO 再帰的にソート

  std::deque<PairPointer> main_chain;
  // INFO 最小の要素をMainChainに追加
  main_chain.push_back(larger_pairs[0].getSmallPair());
  // INFO 大きい方の要素を全て挿入
  for (std::size_t i = 0; i < larger_pairs.size(); ++i) {
    main_chain.push_back(larger_pairs[i].getLargePair());
  }

  if (pairs.size() == 2) { // INFO 要素が1ペア分しかない場合はそのまま返す
    pairs = main_chain;
    return;
  }

  std::size_t base_idx = 1;
  std::size_t loop_finish_size = larger_pairs.size() * 2;
  larger_pairs.erase(larger_pairs.begin());
  for (std::size_t i = 1; main_chain.size() < loop_finish_size; ++i) {
    std::size_t idx = jacobsthal(i) * 2;
    if (idx > larger_pairs.size()) {
      idx = larger_pairs.size();
    }
    std::size_t right_idx = base_idx + idx;
    for (std::size_t j = idx; j > 0; --j) {
      PairPointer target_pair = larger_pairs[j - 1].getSmallPair();
      std::deque<PairPointer>::iterator insert_pos = std::lower_bound(
          main_chain.begin(), main_chain.begin() + right_idx, target_pair);
      main_chain.insert(insert_pos, target_pair);
      larger_pairs.erase(larger_pairs.begin() + j - 1);
    }
    base_idx += idx * 2;
  }

  if (pairs.size() % 2 == 1) { // INFO 奇数の場合の残りの要素を挿入
    std::deque<PairPointer>::iterator insert_pos =
        std::lower_bound(main_chain.begin(), main_chain.end(), pairs.back());
    main_chain.insert(insert_pos, pairs.back());
  }
  pairs = main_chain;
}

std::deque<unsigned> PmergeMe::sort(const std::deque<unsigned> &src) {
  std::deque<PairPointer> pairs = PairPointer::dequeToPairDeque(src);
  _sort(pairs);
  return PairPointer::pairDequeToDeque(pairs);
}
