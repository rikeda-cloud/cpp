#include "IntScalar.hpp"
#include <cctype>

IntScalar::IntScalar(int value) : value_(value) {}

IntScalar::~IntScalar(void) {}

int IntScalar::castToInt(void) { return this->value_; }

char IntScalar::castToChar(void) {
  if (this->value_ < 0 || this->value_ > 255) {
    return '\0';
  }
  if (std::isprint(this->value_)) {
    return static_cast<char>(this->value_);
  }
  return '\0';
}

float IntScalar::castToFloat(void) { return static_cast<float>(this->value_); }

double IntScalar::castToDouble(void) {
  return static_cast<double>(this->value_);
}
