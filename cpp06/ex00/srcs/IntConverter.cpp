#include "IntConverter.hpp"
#include "IntScalar.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>

IntConverter::IntConverter(void) : AConverter() {}

IntConverter::IntConverter(AConverter *converter) : AConverter(converter) {}

IntConverter::~IntConverter(void) {}

IScalar *IntConverter::convertTo(const std::string &s) const {
  char *end;
  long int lvalue = std::strtol(s.c_str(), &end, 10);

  // 文字列全てを変換かつIntの範囲内
  if (*end == '\0' && INT_MIN <= lvalue && lvalue <= INT_MAX) {
    return new IntScalar(static_cast<int>(lvalue));
  }

  return NULL;
}
