#include "FloatConverter.hpp"
#include "FloatScalar.hpp"
#include "IScalar.hpp"
#include <cstdlib>

FloatConverter::FloatConverter(void) : AConverter() {}

FloatConverter::FloatConverter(AConverter *converter) : AConverter(converter) {}

FloatConverter::~FloatConverter(void) {}

IScalar *FloatConverter::convertTo(const std::string &s) const {
  char *end;
  float value = std::strtof(s.c_str(), &end);

  if (s.length() > 1 && std::string(end) == "f") {
    return new FloatScalar(value);
  }

  return NULL;
}
