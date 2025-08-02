#include "Data.hpp"

Data::Data(int v1, int v2) : comparable_v_(v1), incomparable_v_(v2) {}

Data::~Data(void) {}

Data::Data(const Data &d)
    : comparable_v_(d.comparable_v_), incomparable_v_(d.incomparable_v_) {}

Data &Data::operator=(const Data &d) {
  if (this != &d) {
    this->comparable_v_ = d.comparable_v_;
    this->incomparable_v_ = d.incomparable_v_;
  }
  return *this;
}

bool Data::operator>(const Data &d) const {
  return this->comparable_v_ > d.comparable_v_;
}

bool Data::operator<(const Data &d) const {
  return this->comparable_v_ < d.comparable_v_;
}

bool Data::operator>=(const Data &d) const {
  return this->comparable_v_ >= d.comparable_v_;
}

bool Data::operator<=(const Data &d) const {
  return this->comparable_v_ <= d.comparable_v_;
}

bool Data::operator==(const Data &d) const {
  return this->comparable_v_ == d.comparable_v_;
}

bool Data::operator!=(const Data &d) const {
  return this->comparable_v_ != d.comparable_v_;
}

int Data::getIncomparableV(void) const { return this->incomparable_v_; }
