#ifndef CPP06_EX00_ScalarConverter_H_
#define CPP06_EX00_ScalarConverter_H_

#include "ScalarType.hpp"
#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &);
  static ScalarType detectScalarType(const std::string &);

  static bool isCharType(const std::string &);
  static bool isIntType(const std::string &);
  static bool isFloatType(const std::string &);
  static bool isDoubleType(const std::string &);

private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &);
  ~ScalarConverter(void);
  ScalarConverter &operator=(const ScalarConverter &);
};

#endif
