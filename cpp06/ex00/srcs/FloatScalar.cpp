#include "FloatScalar.hpp"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

FloatScalar::FloatScalar(float value) : value_(value) {}

FloatScalar::~FloatScalar(void) {}

std::string FloatScalar::castToInt(void) {
  if (!std::isfinite(this->value_)) {
    return "impossible";
  }
  int int_value = static_cast<int>(this->value_);
  std::ostringstream oss;
  oss << int_value;
  return oss.str();
}

std::string FloatScalar::castToChar(void) {
  if (-128.0 <= this->value_ && this->value_ <= 127.0) {
    char char_value = static_cast<char>(this->value_);
    if (std::isprint(char_value)) {
      std::ostringstream oss;
      oss << "'" << char_value << "'";
      return oss.str();
    }
    return "Non displayable";
  }
  return "impossible";
}

std::string FloatScalar::castToFloat(void) {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(FLOAT_PRECISION);
  oss << this->value_ << "f";
  return oss.str();
}

std::string FloatScalar::castToDouble(void) {
  double double_value = static_cast<double>(this->value_);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(DOUBLE_PRECISION);
  oss << double_value;
  return oss.str();
}
