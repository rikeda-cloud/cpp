#include "DoubleConverter.hpp"
#include "DoubleScalar.hpp"
#include <cstdlib>
#include <iostream>

DoubleConverter::DoubleConverter(void) : AConverter() {}

DoubleConverter::DoubleConverter(AConverter *converter)
    : AConverter(converter) {}

DoubleConverter::~DoubleConverter(void) {}

IScalar *DoubleConverter::convertTo(const std::string &s) const {
  char *end;
  double value = std::strtod(s.c_str(), &end);

  if (*end == '\0') {
    return new DoubleScalar(value);
  }

  return NULL;
}
