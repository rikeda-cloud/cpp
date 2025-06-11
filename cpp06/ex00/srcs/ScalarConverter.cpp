#include "ScalarConverter.hpp"
#include "AConverter.hpp"
#include "CharConverter.hpp"
#include "DoubleConverter.hpp"
#include "FloatConverter.hpp"
#include "IScalar.hpp"
#include "IntConverter.hpp"
#include <iostream>

void ScalarConverter::convert(const std::string &s) {
  DoubleConverter cvt1;
  FloatConverter cvt2(&cvt1);
  IntConverter cvt3(&cvt2);
  CharConverter cvt4(&cvt3);

  IScalar *scalar = cvt4.convert(s);
  std::cout << "char: " << scalar->castToChar() << std::endl;
  std::cout << "int: " << scalar->castToInt() << std::endl;
  std::cout << "float: " << scalar->castToFloat() << std::endl;
  std::cout << "double: " << scalar->castToDouble() << std::endl;
}
