#include "PairPointer.hpp"
#include <cstddef>

std::size_t PairPointer::cmp_count_ = 0;

PairPointer::PairPointer(unsigned val, PairPointer *small_pair,
                         PairPointer *large_pair)
    : val_(val), small_pair_(small_pair), large_pair_(large_pair) {}

PairPointer::~PairPointer(void) {}

PairPointer::PairPointer(const PairPointer &src)
    : val_(src.val_), small_pair_(src.small_pair_),
      large_pair_(src.large_pair_) {}

PairPointer &PairPointer::operator=(const PairPointer &pair) {
  if (this != &pair) {
    val_ = pair.val_;
    small_pair_ = pair.small_pair_;
    large_pair_ = pair.large_pair_;
  }
  return *this;
}

unsigned PairPointer::getVal(void) const { return this->val_; }

PairPointer PairPointer::getSmallPair(void) const { return *small_pair_; }

PairPointer PairPointer::getLargePair(void) const { return *large_pair_; }

bool PairPointer::operator>(const PairPointer &pair) const {
  PairPointer::cmp_count_++;
  return this->val_ > pair.val_;
}

bool PairPointer::operator<(const PairPointer &pair) const {
  PairPointer::cmp_count_++;
  return this->val_ < pair.val_;
}

bool PairPointer::operator>=(const PairPointer &pair) const {
  PairPointer::cmp_count_++;
  return this->val_ >= pair.val_;
}

bool PairPointer::operator<=(const PairPointer &pair) const {
  PairPointer::cmp_count_++;
  return this->val_ <= pair.val_;
}

bool PairPointer::operator==(const PairPointer &pair) const {
  PairPointer::cmp_count_++;
  return this->val_ == pair.val_;
}

bool PairPointer::operator!=(const PairPointer &pair) const {
  PairPointer::cmp_count_++;
  return this->val_ != pair.val_;
}

std::vector<PairPointer>
PairPointer::vecToPairVec(const std::vector<unsigned> &vec) {
  std::vector<PairPointer> pair_vec;
  for (std::vector<unsigned>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    pair_vec.push_back(PairPointer(*it, NULL, NULL));
  }
  return pair_vec;
}

std::vector<unsigned>
PairPointer::pairVecToVec(const std::vector<PairPointer> &pair_vec) {
  std::vector<unsigned> vec;
  for (std::size_t i = 0; i < pair_vec.size(); i++) {
    vec.push_back(pair_vec[i].getVal());
  }
  return vec;
}

std::deque<PairPointer>
PairPointer::dequeToPairDeque(const std::deque<unsigned> &deq) {
  std::deque<PairPointer> pair_deq;
  for (std::deque<unsigned>::const_iterator it = deq.begin(); it != deq.end();
       ++it) {
    pair_deq.push_back(PairPointer(*it, NULL, NULL));
  }
  return pair_deq;
}

std::deque<unsigned>
PairPointer::pairDequeToDeque(const std::deque<PairPointer> &pair_deq) {
  std::deque<unsigned> deq;
  for (std::size_t i = 0; i < pair_deq.size(); i++) {
    deq.push_back(pair_deq[i].getVal());
  }
  return deq;
}

std::size_t PairPointer::getCmpCount(void) { return PairPointer::cmp_count_; }
void PairPointer::resetCmpCount(void) { PairPointer::cmp_count_ = 0; }
