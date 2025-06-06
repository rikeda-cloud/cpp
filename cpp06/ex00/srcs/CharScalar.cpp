#include "CharScalar.hpp"

CharScalar::CharScalar(char value) : value_(value) {}

CharScalar::~CharScalar(void) {}

int CharScalar::castToInt(void) { return static_cast<int>(this->value_); }

char CharScalar::castToChar(void) { return this->value_; }

float CharScalar::castToFloat(void) { return static_cast<float>(this->value_); }

double CharScalar::castToDouble(void) {
  return static_cast<double>(this->value_);
}
