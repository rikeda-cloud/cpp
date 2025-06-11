#include "NaNScalar.hpp"

NaNScalar::NaNScalar(void) {}

NaNScalar::~NaNScalar(void) {}

std::string NaNScalar::castToInt(void) { return "impossible"; }

std::string NaNScalar::castToChar(void) { return "impossible"; }

std::string NaNScalar::castToFloat(void) { return "nanf"; }

std::string NaNScalar::castToDouble(void) { return "nan"; }
