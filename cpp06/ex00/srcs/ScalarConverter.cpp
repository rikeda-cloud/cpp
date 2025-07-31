#include "ScalarConverter.hpp"
#include "AConverter.hpp"
#include "CharConverter.hpp"
#include "DoubleConverter.hpp"
#include "FloatConverter.hpp"
#include "IScalar.hpp"
#include "IntConverter.hpp"
#include <exception>
#include <iostream>

void ScalarConverter::convert(const std::string &s) {
  CharConverter cvt1;
  DoubleConverter cvt2(&cvt1);
  FloatConverter cvt3(&cvt2);
  IntConverter cvt4(&cvt3);

  try {
    IScalar *scalar = cvt4.convert(s);
    std::cout << "char: " << scalar->castToChar() << std::endl;
    std::cout << "int: " << scalar->castToInt() << std::endl;
    std::cout << "float: " << scalar->castToFloat() << std::endl;
    std::cout << "double: " << scalar->castToDouble() << std::endl;
    delete scalar;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
