#include "CharConverter.hpp"
#include "DoubleConverter.hpp"
#include "FloatConverter.hpp"
#include "IScalar.hpp"
#include "IntConverter.hpp"
#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

bool _assert_string(const std::string &param, const std::string &expect,
                    const std::string &actual, const std::string &type) {
  if (expect == actual) {
    return 0;
  }

  std::cout << RED << "[FAIL] " << param << "(" << type << ")" << std::endl
            << "  Expected: \"" << expect << "\"" << std::endl
            << "  Actual  : \"" << actual << "\"" << RESET << std::endl;
  return 1;
}

bool exec_test_convert(const std::string &param, const std::string &expect_char,
                       const std::string &expect_int,
                       const std::string &expect_float,
                       const std::string &expect_double) {
  CharConverter cvt1;
  DoubleConverter cvt2(&cvt1);
  FloatConverter cvt3(&cvt2);
  IntConverter cvt4(&cvt3);

  IScalar *scalar = cvt4.convert(param);

  int fail_count =
      _assert_string(param, expect_char, scalar->castToChar(), "Char") +
      _assert_string(param, expect_int, scalar->castToInt(), "Int") +
      _assert_string(param, expect_float, scalar->castToFloat(), "Float") +
      _assert_string(param, expect_double, scalar->castToDouble(), "Double");

  if (!fail_count) {
    std::cout << GREEN << "[OK] " << param << RESET << std::endl;
  }

  return fail_count >= 1;
}
