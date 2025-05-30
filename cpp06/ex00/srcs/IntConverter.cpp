#include "IntConverter.hpp"
#include "IScalar.hpp"
#include <iostream>

IntConverter::IntConverter(void) : AConverter() {}

IntConverter::IntConverter(AConverter *converter) : AConverter(converter) {}

IntConverter::~IntConverter(void) {}

IScalar *IntConverter::convertTo(const std::string &s) const {
  std::cout << "call convertToInt " << s << std::endl;
  return NULL;
}

bool IntConverter::canConvert(const std::string &s) const {
  std::cout << "call canConvertInt " << s << std::endl;
  return false;
}
