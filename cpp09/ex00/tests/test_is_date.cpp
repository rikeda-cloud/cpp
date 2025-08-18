#include "utils.hpp"
#include <iostream>

static bool _exec_is_date(int y, int m, int d, bool success_validate) {
  bool error_occurred = isDate(y, m, d) != success_validate;
  if (error_occurred) {
    std::cout << "[ERROR] _test_is_date: y = " << y << " m = " << m
              << " d = " << d << std::endl;
  }
  return error_occurred;
}

int test_is_date(void) {
  int fail_count =
      _exec_is_date(0, 1, 1, true) + _exec_is_date(2000, 2, 29, true) +
      _exec_is_date(9999, 12, 31, true) + _exec_is_date(2001, 2, 28, true) +
      _exec_is_date(2004, 2, 29, true) + _exec_is_date(2100, 2, 29, false) +
      _exec_is_date(2000, 4, 31, false) + _exec_is_date(2000, 1, 0, false) +
      _exec_is_date(2000, 12, 32, false) + _exec_is_date(2000, 13, 1, false) +
      _exec_is_date(2001, 0, 1, false);

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
