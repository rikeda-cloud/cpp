#include "PairPointer.hpp"

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

PairPointer *PairPointer::getSmallPair(void) const { return this->small_pair_; }

PairPointer *PairPointer::getLargePair(void) const { return this->large_pair_; }

bool PairPointer::operator>(const PairPointer &pair) const {
  return this->val_ > pair.val_;
}

bool PairPointer::operator<(const PairPointer &pair) const {
  return this->val_ < pair.val_;
}

bool PairPointer::operator>=(const PairPointer &pair) const {
  return this->val_ >= pair.val_;
}

bool PairPointer::operator<=(const PairPointer &pair) const {
  return this->val_ <= pair.val_;
}

bool PairPointer::operator==(const PairPointer &pair) const {
  return this->val_ == pair.val_;
}

bool PairPointer::operator!=(const PairPointer &pair) const {
  return this->val_ != pair.val_;
}
