#include "FloatConverter.hpp"
#include "IScalar.hpp"
#include <iostream>

FloatConverter::FloatConverter(void) : AConverter() {}

FloatConverter::FloatConverter(AConverter *converter) : AConverter(converter) {}

FloatConverter::~FloatConverter(void) {}

IScalar *FloatConverter::convertTo(const std::string &s) const {
  std::cout << "call convertToFloat " << s << std::endl;
  return NULL;
}
