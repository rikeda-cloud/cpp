#include "FloatScalar.hpp"

FloatScalar::FloatScalar(float value) : value_(value) {}

FloatScalar::~FloatScalar(void) {}

int FloatScalar::castToInt(void) { return static_cast<int>(this->value_); }

char FloatScalar::castToChar(void) { return static_cast<char>(this->value_); }

float FloatScalar::castToFloat(void) { return this->value_; }

double FloatScalar::castToDouble(void) {
  return static_cast<double>(this->value_);
}
