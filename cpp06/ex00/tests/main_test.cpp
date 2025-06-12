#include "test.hpp"

int test_char(void) {
  int fail_count = exec_test_convert("a", "'a'", "97", "97.0f", "97.0");

  return fail_count;
}

int test_int(void) {
  int fail_count =
      exec_test_convert("0", "Non displayable", "0", "0.0f", "0.0");

  return fail_count;
}

int test_float(void) {
  int fail_count =
      exec_test_convert("0.0f", "Non displayable", "0", "0.0f", "0.0");

  return fail_count;
}

int test_double(void) {
  int fail_count =
      exec_test_convert("0.0", "Non displayable", "0", "0.0f", "0.0");

  return fail_count;
}

int test_nan_inf(void) {
  int fail_count =
      exec_test_convert("nan", "impossible", "impossible", "nanf", "nan") +
      exec_test_convert("+nan", "impossible", "impossible", "nanf", "nan") +
      exec_test_convert("-nan", "impossible", "impossible", "-nanf", "-nan") +
      exec_test_convert("inf", "impossible", "impossible", "inff", "inf") +
      exec_test_convert("+inf", "impossible", "impossible", "inff", "inf") +
      exec_test_convert("-inf", "impossible", "impossible", "-inff", "-inf");

  return fail_count;
}

int main(void) {
  int total_fail_count =
      test_char() + test_int() + test_float() + test_double() + test_nan_inf();

  return total_fail_count != 0;
}
