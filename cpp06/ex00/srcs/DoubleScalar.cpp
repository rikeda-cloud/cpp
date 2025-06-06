#include "DoubleScalar.hpp"

DoubleScalar::DoubleScalar(double value) : value_(value) {}

DoubleScalar::~DoubleScalar(void) {}

int DoubleScalar::castToInt(void) { return static_cast<int>(this->value_); }

char DoubleScalar::castToChar(void) { return static_cast<char>(this->value_); }

float DoubleScalar::castToFloat(void) {
  return static_cast<float>(this->value_);
}

double DoubleScalar::castToDouble(void) { return this->value_; }
