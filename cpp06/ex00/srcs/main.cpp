#include "AConverter.hpp"
#include "CharConverter.hpp"
#include "DoubleConverter.hpp"
#include "FloatConverter.hpp"
#include "IScalar.hpp"
#include "IntConverter.hpp"
#include <iostream>

int main(void) {
  IntConverter cvt;
  CharConverter cvt2(&cvt);
  FloatConverter cvt3(&cvt2);
  DoubleConverter cvt4(&cvt3);

  IScalar *scalar = cvt4.convert("42");
  if (scalar) {
    std::cout << "Int: " << scalar->castToInt() << std::endl;
    std::cout << "Char: " << scalar->castToChar() << std::endl;
    std::cout << "Float: " << scalar->castToFloat() << std::endl;
    std::cout << "Double: " << scalar->castToDouble() << std::endl;
  } else {
    std::cout << "Error" << std::endl;
  }
  return 0;
}
