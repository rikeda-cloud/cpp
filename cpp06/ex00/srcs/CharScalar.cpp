#include "CharScalar.hpp"
#include <cctype>
#include <iomanip>
#include <sstream>

CharScalar::CharScalar(char value) : value_(value) {}

CharScalar::~CharScalar(void) {}

std::string CharScalar::castToInt(void) {
  int int_value = static_cast<int>(this->value_);
  std::ostringstream oss;
  oss << int_value;
  return oss.str();
}

std::string CharScalar::castToChar(void) {
  if (std::isprint(this->value_)) {
    std::ostringstream oss;
    oss << "'" << this->value_ << "'";
    return oss.str();
  }
  return "Non displayable";
}

std::string CharScalar::castToFloat(void) {
  float float_value = static_cast<float>(this->value_);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(FLOAT_PRECISION);
  oss << float_value << "f";
  return oss.str();
}

std::string CharScalar::castToDouble(void) {
  double double_value = static_cast<double>(this->value_);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(DOUBLE_PRECISION);
  oss << double_value;
  return oss.str();
}
