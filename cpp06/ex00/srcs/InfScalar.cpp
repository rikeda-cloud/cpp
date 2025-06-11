#include "InfScalar.hpp"
#include <iomanip>
#include <sstream>
#include <string>

InfScalar::InfScalar(bool minus_flag) : minus_flag_(minus_flag) {}

InfScalar::~InfScalar(void) {}

std::string InfScalar::castToInt(void) { return "impossible"; }

std::string InfScalar::castToChar(void) { return "impossible"; }

std::string InfScalar::castToFloat(void) {
  if (this->minus_flag_) {
    return "-inff";
  }
  return "inff";
}

std::string InfScalar::castToDouble(void) {
  if (this->minus_flag_) {
    return "-inf";
  }
  return "inf";
}
