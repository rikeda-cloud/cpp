#include "PmergeMe.hpp"
#include "PairPointer.hpp"
#include "utils.hpp"
#include <cstddef>
#include <iostream>

static std::vector<PairPointer> _pair_up(std::vector<PairPointer> &pairs) {
  std::vector<PairPointer> new_pairs;
  new_pairs.reserve(pairs.size() / 2);

  for (std::size_t i = 1; i < pairs.size(); i += 2) {
    PairPointer *small = &pairs[i - 1];
    PairPointer *large = &pairs[i];
    if (*large < *small) { // INFO 大小比較
      std::swap(small, large);
    }
    new_pairs.push_back(PairPointer(large->getVal(), small, large));
  }
  return new_pairs;
}

static std::deque<PairPointer> _pair_up(std::deque<PairPointer> &pairs) {
  std::deque<PairPointer> new_pairs;

  for (std::size_t i = 1; i < pairs.size(); i += 2) {
    PairPointer *small = &pairs[i - 1];
    PairPointer *large = &pairs[i];
    if (*large < *small) { // INFO 大小比較
      std::swap(small, large);
    }
    new_pairs.push_back(PairPointer(large->getVal(), small, large));
  }
  return new_pairs;
}

static void
_prep_main_chain_and_pend(const std::vector<PairPointer> &pairs,
                          const std::vector<PairPointer> &sorted_pairs,
                          std::vector<PairPointer> &main_chain,
                          std::vector<PairPointer> &pend) {
  main_chain.reserve(pairs.size());
  pend.reserve(pairs.size() / 2 + 1);

  for (std::vector<PairPointer>::const_iterator it = sorted_pairs.begin();
       it != sorted_pairs.end(); ++it) {
    main_chain.push_back(it->getLargePair());
    pend.push_back(it->getSmallPair());
  }
  // ペアの数が奇数の場合、余り要素をpendに追加
  if (pairs.size() % 2 == 1) {
    pend.push_back(pairs.back());
  }
}

static void
_prep_main_chain_and_pend(const std::deque<PairPointer> &pairs,
                          const std::deque<PairPointer> &sorted_pairs,
                          std::deque<PairPointer> &main_chain,
                          std::deque<PairPointer> &pend) {
  for (std::deque<PairPointer>::const_iterator it = sorted_pairs.begin();
       it != sorted_pairs.end(); ++it) {
    main_chain.push_back(it->getLargePair());
    pend.push_back(it->getSmallPair());
  }
  // ペアの数が奇数の場合、余り要素をpendに追加
  if (pairs.size() % 2 == 1) {
    pend.push_back(pairs.back());
  }
}

static void
_insert_pend_elements_to_main_chain(std::size_t pairs_size,
                                    std::vector<PairPointer> &main_chain,
                                    const std::vector<PairPointer> &pend) {
  std::size_t main_chain_idx = 0;
  std::size_t pend_idx = 0;

  // INFO 最小要素のペアをmain_chain先頭に挿入
  main_chain.insert(main_chain.begin(), pend[0]);
  main_chain_idx++;
  pend_idx++;

  for (std::size_t k = 3; main_chain.size() < pairs_size; ++k) {
    std::size_t group_size = jacobsthal(k) - jacobsthal(k - 1);
    std::size_t group_end_idx = pend_idx + group_size;
    std::size_t right_idx = main_chain_idx + group_size;
    if (group_end_idx > pend.size()) {
      group_end_idx = pend.size();
      right_idx = main_chain.size();
    }

    std::size_t insert_end_pos_count = 0;
    for (std::size_t j = group_end_idx; j > pend_idx; --j) {
      std::vector<PairPointer>::iterator end =
          main_chain.begin() + right_idx - insert_end_pos_count;
      // INFO 余り要素の挿入位置探索はmain_chain全体
      if (pairs_size % 2 == 1 && j == pend.size()) {
        end = main_chain.end();
      }
      std::vector<PairPointer>::iterator insert_pos =
          std::lower_bound(main_chain.begin(), end, pend[j - 1]);
      main_chain.insert(insert_pos, pend[j - 1]);
      // INFO 二分探索範囲の右終端よりも右側に挿入されたら探索範囲を狭める
      insert_end_pos_count += (end - 1) < insert_pos;
    }
    pend_idx += group_size;
    main_chain_idx += group_size * 2;
  }
}

static void
_insert_pend_elements_to_main_chain(std::size_t pairs_size,
                                    std::deque<PairPointer> &main_chain,
                                    const std::deque<PairPointer> &pend) {
  std::size_t main_chain_idx = 0;
  std::size_t pend_idx = 0;

  // INFO 最小要素のペアをmain_chain先頭に挿入
  main_chain.insert(main_chain.begin(), pend[pend_idx]);
  main_chain_idx++;
  pend_idx++;

  for (std::size_t k = 3; main_chain.size() < pairs_size; ++k) {
    std::size_t group_size = jacobsthal(k) - jacobsthal(k - 1);
    std::size_t group_end_idx = pend_idx + group_size;
    std::size_t right_idx = main_chain_idx + group_size;
    if (group_end_idx > pend.size()) {
      group_end_idx = pend.size();
      right_idx = main_chain.size();
    }

    std::size_t insert_end_pos_count = 0;
    for (std::size_t j = group_end_idx; j > pend_idx; --j) {
      std::deque<PairPointer>::iterator end =
          main_chain.begin() + right_idx - insert_end_pos_count;
      // INFO 余り要素の挿入位置探索はmain_chain全体
      if (pairs_size % 2 == 1 && j == pend.size()) {
        end = main_chain.end();
      }
      std::deque<PairPointer>::iterator insert_pos =
          std::lower_bound(main_chain.begin(), end, pend[j - 1]);
      main_chain.insert(insert_pos, pend[j - 1]);
      // INFO 二分探索範囲の右終端よりも右側に挿入されたら探索範囲を狭める
      insert_end_pos_count += (end - 1) < insert_pos;
    }
    pend_idx += group_size;
    main_chain_idx += group_size * 2;
  }
}

static void _sort(std::vector<PairPointer> &pairs) {
  if (pairs.size() <= 1) {
    return;
  }
  // INFO Step1: ペアリングと再帰ソート
  std::vector<PairPointer> larger_pairs = _pair_up(pairs);
  _sort(larger_pairs);

  // INFO Step2: メインチェーンと挿入待ちリストの構築
  std::vector<PairPointer> main_chain, pend;
  _prep_main_chain_and_pend(pairs, larger_pairs, main_chain, pend);

  // INFO Step3: pend要素をメインチェーンに挿入
  _insert_pend_elements_to_main_chain(pairs.size(), main_chain, pend);
  pairs = main_chain;
}

static void _sort(std::deque<PairPointer> &pairs) {
  if (pairs.size() <= 1) {
    return;
  }
  // INFO Step1: ペアリングと再帰ソート
  std::deque<PairPointer> larger_pairs = _pair_up(pairs);
  _sort(larger_pairs);

  // INFO Step2: メインチェーンと挿入待ちリストの構築
  std::deque<PairPointer> main_chain, pend;
  _prep_main_chain_and_pend(pairs, larger_pairs, main_chain, pend);

  // INFO Step3: pend要素をメインチェーンに挿入
  _insert_pend_elements_to_main_chain(pairs.size(), main_chain, pend);
  pairs = main_chain;
}

std::vector<unsigned> PmergeMe::sort(const std::vector<unsigned> &src) {
  std::vector<PairPointer> pairs = PairPointer::vecToPairVec(src);
  _sort(pairs);
  return PairPointer::pairVecToVec(pairs);
}

std::deque<unsigned> PmergeMe::sort(const std::deque<unsigned> &src) {
  std::deque<PairPointer> pairs = PairPointer::dequeToPairDeque(src);
  _sort(pairs);
  return PairPointer::pairDequeToDeque(pairs);
}
