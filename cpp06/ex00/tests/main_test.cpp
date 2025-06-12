#include "test.hpp"
#include <iostream>
#include <limits>

int test_char(void) {
  int fail_count = exec_test_convert("a", "'a'", "97", "97.0f", "97.0") +
                   exec_test_convert("c", "'c'", "99", "99.0f", "99.0") +
                   exec_test_convert(" ", "' '", "32", "32.0f", "32.0") +
                   exec_test_convert("!", "'!'", "33", "33.0f", "33.0");

  return fail_count;
}

int test_int(void) {
  int fail_count =
      exec_test_convert("0", "Non displayable", "0", "0.0f", "0.0") +
      exec_test_convert("-42", "impossible", "-42", "-42.0f", "-42.0") +
      exec_test_convert("42", "'*'", "42", "42.0f", "42.0") +
      exec_test_convert("255", "Non displayable", "255", "255.0f", "255.0") +
      exec_test_convert("256", "impossible", "256", "256.0f", "256.0");

  return fail_count;
}

int test_int_max(void) {
  /*
   * INFO float型の精度には限界がある
   * 実行環境の丸めずに正確に表現できる桁数は下記プログラムで取得可能
   * std::cout << std::numeric_limits<float>::digits10 << std::endl;
   */

  std::string int_max = convert_long_to_string(std::numeric_limits<int>::max());
  std::string int_max_plus_1 = convert_long_to_string(
      static_cast<long>(std::numeric_limits<int>::max()) + 1);

  int fail_count =
      exec_test_convert(int_max, "impossible", int_max, int_max_plus_1 + ".0f",
                        int_max + ".0") +
      exec_test_convert(int_max_plus_1, "impossible", "impossible",
                        int_max_plus_1 + ".0f", int_max_plus_1 + ".0");

  return fail_count;
}

int test_int_min(void) {
  /*
   * INFO float型の精度には限界がある
   * 実行環境の丸めずに正確に表現できる桁数は下記プログラムで取得可能
   * std::cout << std::numeric_limits<float>::digits10 << std::endl;
   */

  std::string int_min = convert_long_to_string(std::numeric_limits<int>::min());
  std::string int_min_minus_1 = convert_long_to_string(
      static_cast<long>(std::numeric_limits<int>::min()) - 1);

  int fail_count =
      exec_test_convert(int_min, "impossible", int_min, int_min + ".0f",
                        int_min + ".0") +
      exec_test_convert(int_min_minus_1, "impossible", "impossible",
                        int_min + ".0f", int_min_minus_1 + ".0");

  return fail_count;
}

int test_float(void) {
  int fail_count =
      exec_test_convert("0.0f", "Non displayable", "0", "0.0f", "0.0") +
      exec_test_convert("-42.0f", "impossible", "-42", "-42.0f", "-42.0") +
      exec_test_convert("42.0f", "'*'", "42", "42.0f", "42.0");

  return fail_count;
}

int test_double(void) {
  int fail_count =
      exec_test_convert("0.0", "Non displayable", "0", "0.0f", "0.0") +
      exec_test_convert("-42.0", "impossible", "-42", "-42.0f", "-42.0") +
      exec_test_convert("42.0", "'*'", "42", "42.0f", "42.0");

  return fail_count;
}

int test_nan_inf(void) {
  int fail_count =
      exec_test_convert("nan", "impossible", "impossible", "nanf", "nan") +
      exec_test_convert("+nan", "impossible", "impossible", "nanf", "nan") +
      exec_test_convert("-nan", "impossible", "impossible", "-nanf", "-nan") +
      exec_test_convert("nanf", "impossible", "impossible", "nanf", "nan") +
      exec_test_convert("inf", "impossible", "impossible", "inff", "inf") +
      exec_test_convert("+inf", "impossible", "impossible", "inff", "inf") +
      exec_test_convert("-inf", "impossible", "impossible", "-inff", "-inf") +
      exec_test_convert("inff", "impossible", "impossible", "inff", "inf") +
      exec_test_convert("+inff", "impossible", "impossible", "inff", "inf") +
      exec_test_convert("-inff", "impossible", "impossible", "-inff", "-inf");

  return fail_count;
}

int main(void) {
  int total_fail_count = test_char() + test_int() + test_int_max() +
                         test_int_min() + test_float() + test_double() +
                         test_nan_inf();

  return total_fail_count != 0;
}
