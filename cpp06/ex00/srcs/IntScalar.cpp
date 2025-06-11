#include "IntScalar.hpp"
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

IntScalar::IntScalar(int value) : value_(value) {}

IntScalar::~IntScalar(void) {}

std::string IntScalar::castToInt(void) {
  std::ostringstream oss;
  oss << this->value_;
  return oss.str();
}

std::string IntScalar::castToChar(void) {
  if (0 <= this->value_ && this->value_ <= 255) {
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

std::string IntScalar::castToFloat(void) {
  float float_value = static_cast<float>(this->value_);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(FLOAT_PRECISION);
  oss << float_value << "f";
  return oss.str();
}

std::string IntScalar::castToDouble(void) {
  double double_value = static_cast<double>(this->value_);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(DOUBLE_PRECISION);
  oss << double_value;
  return oss.str();
}
