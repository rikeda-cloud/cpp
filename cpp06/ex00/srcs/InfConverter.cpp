#include "InfConverter.hpp"
#include "InfScalar.hpp"
#include <cstdlib>

InfConverter::InfConverter(void) : AConverter() {}

InfConverter::InfConverter(AConverter *converter) : AConverter(converter) {}

InfConverter::~InfConverter(void) {}

IScalar *InfConverter::convertTo(const std::string &s) const {
  if (s == "inf" || s == "inff" || s == "+inf" || s == "+inff") {
    return new InfScalar(false);
  }
  if (s == "-inf" || s == "-inff") {
    return new InfScalar(true);
  }

  return NULL;
}
