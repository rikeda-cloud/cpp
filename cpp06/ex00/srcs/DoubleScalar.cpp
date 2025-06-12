#include "DoubleScalar.hpp"
#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

DoubleScalar::DoubleScalar(double value) : value_(value) {}

DoubleScalar::~DoubleScalar(void) {}

std::string DoubleScalar::castToInt(void) {
  if (!std::isfinite(this->value_) ||
      this->value_ > std::numeric_limits<int>::max() ||
      this->value_ < std::numeric_limits<int>::min()) {
    return "impossible";
  }
  int int_value = static_cast<int>(this->value_);
  std::ostringstream oss;
  oss << int_value;
  return oss.str();
}

std::string DoubleScalar::castToChar(void) {
  if (0.0 <= this->value_ && this->value_ <= 255.0) {
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

std::string DoubleScalar::castToFloat(void) {
  float float_value = static_cast<float>(this->value_);

  // doubleは有限なのにfloatでinf → オーバーフロー
  if (std::isinf(float_value) && !std::isinf(this->value_)) {
    return "impossible";
  }
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(FLOAT_PRECISION);
  oss << float_value << "f";
  return oss.str();
}

std::string DoubleScalar::castToDouble(void) {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(DOUBLE_PRECISION);
  oss << this->value_;
  return oss.str();
}
