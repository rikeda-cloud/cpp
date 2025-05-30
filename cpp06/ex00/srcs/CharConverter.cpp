#include "CharConverter.hpp"
#include "IScalar.hpp"
#include <iostream>

CharConverter::CharConverter(void) : AConverter() {}

CharConverter::CharConverter(AConverter *converter) : AConverter(converter) {}

CharConverter::~CharConverter(void) {}

IScalar *CharConverter::convertTo(const std::string &s) const {
  std::cout << "call convertToChar " << s << std::endl;
  return NULL;
}

bool CharConverter::canConvert(const std::string &s) const {
  std::cout << "call canConvertChar " << s << std::endl;
  return false;
}
