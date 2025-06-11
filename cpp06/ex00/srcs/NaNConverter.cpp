#include "NaNConverter.hpp"
#include "NaNScalar.hpp"

NaNConverter::NaNConverter(void) : AConverter() {}

NaNConverter::NaNConverter(AConverter *converter) : AConverter(converter) {}

NaNConverter::~NaNConverter(void) {}

IScalar *NaNConverter::convertTo(const std::string &s) const {
  if (s == "nan" || s == "nanf") {
    return new NaNScalar();
  }

  return NULL;
}
