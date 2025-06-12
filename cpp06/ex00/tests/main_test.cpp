#include "test.hpp"
#include <iostream>
#include <limits>

int test_char(void) {
  int fail_count = exec_test_convert("a", "'a'", "97", "97.0f", "97.0") +
                   exec_test_convert("c", "'c'", "99", "99.0f", "99.0") +
                   exec_test_convert("T", "'T'", "84", "84.0f", "84.0") +
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
  /*
   * INFO 仕様上、小数点以下第１位までとする
   */

  int fail_count =
      exec_test_convert("0.0f", "Non displayable", "0", "0.0f", "0.0") +
      exec_test_convert("-42.0f", "impossible", "-42", "-42.0f", "-42.0") +
      exec_test_convert("42.0f", "'*'", "42", "42.0f", "42.0") +
      exec_test_convert(".9f", "Non displayable", "0", "0.9f", "0.9") +
      exec_test_convert("-.9f", "impossible", "0", "-0.9f", "-0.9") +
      exec_test_convert("1.f", "Non displayable", "1", "1.0f", "1.0") +
      exec_test_convert("0.100000f", "Non displayable", "0", "0.1f", "0.1") +
      exec_test_convert("-999.01f", "impossible", "-999", "-999.0f", "-999.0");

  return fail_count;
}

int test_float_max(void) {
  /*
   * INFO float型のオーバーフローはinffとして扱う
   */

  std::string float_max =
      convert_double_to_string(std::numeric_limits<float>::max());
  std::string float_max_mul_10 = float_max + "0";

  int fail_count =
      exec_test_convert(float_max, "impossible", "impossible",
                        float_max + ".0f", float_max + ".0") +
      exec_test_convert(float_max_mul_10, "impossible", "impossible", "inff",
                        float_max_mul_10 + ".0");

  return fail_count;
}

int test_float_min(void) {
  /*
   * INFO float型のアンダーフローは-inffとして扱う
   */

  std::string float_min =
      convert_double_to_string(-std::numeric_limits<float>::max());
  std::string float_min_mul_2 =
      convert_double_to_string(-std::numeric_limits<float>::max() * 2.0);

  int fail_count =
      exec_test_convert(float_min, "impossible", "impossible",
                        float_min + ".0f", float_min + ".0") +
      exec_test_convert(float_min_mul_2, "impossible", "impossible", "-inff",
                        float_min_mul_2 + ".0");

  return fail_count;
}

int test_double(void) {
  int fail_count =
      exec_test_convert("0.0", "Non displayable", "0", "0.0f", "0.0") +
      exec_test_convert("-42.0", "impossible", "-42", "-42.0f", "-42.0") +
      exec_test_convert("42.0", "'*'", "42", "42.0f", "42.0") +
      exec_test_convert(".9", "Non displayable", "0", "0.9f", "0.9") +
      exec_test_convert("-.9", "impossible", "0", "-0.9f", "-0.9") +
      exec_test_convert("1.", "Non displayable", "1", "1.0f", "1.0") +
      exec_test_convert("0.100000", "Non displayable", "0", "0.1f", "0.1") +
      exec_test_convert("-999.01", "impossible", "-999", "-999.0f", "-999.0");

  return fail_count;
}

int test_double_max(void) {
  std::string double_max =
      convert_double_to_string(std::numeric_limits<double>::max());
  std::string double_max_mul_10 = double_max + "0";

  int fail_count = exec_test_convert(double_max, "impossible", "impossible",
                                     "inff", double_max + ".0") +
                   exec_test_convert(double_max_mul_10, "impossible",
                                     "impossible", "inff", "inf");

  return fail_count;
}

int test_double_min(void) {
  std::string double_min =
      convert_double_to_string(-std::numeric_limits<double>::max());
  std::string double_min_mul_10 = double_min + "0";

  int fail_count = exec_test_convert(double_min, "impossible", "impossible",
                                     "-inff", double_min + ".0") +
                   exec_test_convert(double_min_mul_10, "impossible",
                                     "impossible", "-inff", "-inf");

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
  exec_test_convert("  inf  ", "impossible", "impossible", "impossible",
                    "impossible");
  exec_test_convert("nan    ", "impossible", "impossible", "impossible",
                    "impossible");
  exec_test_convert("    -inff", "impossible", "impossible", "-inff", "-inf");

  return fail_count;
}

int main(void) {
  int total_fail_count = test_char() + test_int() + test_int_max() +
                         test_int_min() + test_float() + test_float_max() +
                         test_float_min() + test_double() + test_double_max() +
                         test_double_min() + test_nan_inf();

  return total_fail_count != 0;
}
