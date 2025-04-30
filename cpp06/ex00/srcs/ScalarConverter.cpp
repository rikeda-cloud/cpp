#include "ScalarConverter.hpp"
#include "ScalarType.hpp"
#include <cstdlib>
#include <iostream>

void ScalarConverter::convert(const std::string &s) {
  std::cout << s << ": " << detectScalarType(s) << std::endl;
}

ScalarType ScalarConverter::detectScalarType(const std::string &s) {
  if (isCharType(s))
    return Char;
  if (isIntType(s))
    return Int;
  if (isFloatType(s))
    return Float;
  if (isDoubleType(s))
    return Double;
  return Unknown;
}

bool ScalarConverter::isCharType(const std::string &s) {
  // INFO シングルクォーテーションで囲まれた文字と解釈
  return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

bool ScalarConverter::isIntType(const std::string &s) {
  char *end;
  std::strtol(s.c_str(), &end, 10);

  return (*end == '\0');
}

bool ScalarConverter::isFloatType(const std::string &s) {
  if (s.length() <= 1) {
    return false;
  }
  const char last_char = s[s.length() - 1];
  if (last_char != 'f' && last_char != 'F') {
    return false;
  }

  char *end;
  std::string new_s = s.substr(0, s.size() - 1);
  std::strtof(new_s.c_str(), &end);

  return (*end == '\0');
}

bool ScalarConverter::isDoubleType(const std::string &s) {
  char *end;
  std::strtof(s.c_str(), &end);
  return (*end == '\0');
}
