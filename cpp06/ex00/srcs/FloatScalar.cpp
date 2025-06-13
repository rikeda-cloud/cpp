#include "FloatScalar.hpp"
#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>

FloatScalar::FloatScalar(float value) : value_(value) {}

FloatScalar::~FloatScalar(void) {}

std::string FloatScalar::castToInt(void) {
  /*
   * INFO INT_MAXをfloatと比較する際、情報が落ちる
   */

  if (!std::isfinite(this->value_) ||
      this->value_ > static_cast<double>(std::numeric_limits<int>::max()) ||
      this->value_ < static_cast<double>(std::numeric_limits<int>::min())) {
    return "impossible";
  }
  int int_value = static_cast<int>(this->value_);
  std::ostringstream oss;
  oss << int_value;
  return oss.str();
}

std::string FloatScalar::castToChar(void) {
  if (std::isfinite(this->value_) &&
      std::numeric_limits<signed char>::min() <= this->value_ &&
      this->value_ <= std::numeric_limits<signed char>::max()) {
    signed char char_value = static_cast<signed char>(this->value_);
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
