#include "CharConverter.hpp"
#include "CharScalar.hpp"
#include <iostream>

CharConverter::CharConverter(void) : AConverter() {}

CharConverter::CharConverter(AConverter *converter) : AConverter(converter) {}

CharConverter::~CharConverter(void) {}

IScalar *CharConverter::convertTo(const std::string &s) const {
  if (s.length() == 1) {
    return new CharScalar(s[0]);
  }
  return NULL;
}
