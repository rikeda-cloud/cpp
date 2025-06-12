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

bool _assert_string(const std::string &expect, const std::string &actual,
                    const std::string &type) {
  if (expect == actual) {
    std::cout << GREEN << "[OK] " << RESET << std::endl;
    return 0;
  } else {
    std::cout << RED << "[FAIL"
              << "(" << type << ")"
              << "] "
              << "Expected: \"" << expect << "\", but got: \"" << actual << "\""
              << RESET << std::endl;
    return 1;
  }
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

  int fail_count = 0;
  fail_count += _assert_string(expect_char, scalar->castToChar(), "Char");
  fail_count += _assert_string(expect_int, scalar->castToInt(), "Int");
  fail_count += _assert_string(expect_float, scalar->castToFloat(), "Float");
  fail_count += _assert_string(expect_double, scalar->castToDouble(), "Double");

  return fail_count >= 1;
}
