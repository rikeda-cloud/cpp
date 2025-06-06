#include "DoubleConverter.hpp"
#include "IScalar.hpp"
#include <iostream>

DoubleConverter::DoubleConverter(void) : AConverter() {}

DoubleConverter::DoubleConverter(AConverter *converter)
    : AConverter(converter) {}

DoubleConverter::~DoubleConverter(void) {}

IScalar *DoubleConverter::convertTo(const std::string &s) const {
  std::cout << "call convertToDouble " << s << std::endl;
  return NULL;
}
