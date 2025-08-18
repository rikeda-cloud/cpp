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
  int fail_count = 0;
  // year case
  // INFO 紀元前(year < 0)は未定義動作とする
  fail_count +=
      _exec_is_date(0, 1, 1, true) + _exec_is_date(9999, 12, 31, true) +
      _exec_is_date(10000, 1, 1, true) + _exec_is_date(-1, 1, 1, true);

  // month case
  fail_count += _exec_is_date(2000, 0, 1, false) +
                _exec_is_date(2000, 13, 1, false) +
                _exec_is_date(2000, -1, 1, false);

  // day case
  fail_count +=
      _exec_is_date(2000, 1, 0, false) + _exec_is_date(2000, 0, -1, false) +
      _exec_is_date(2000, 4, 30, true) + _exec_is_date(2000, 4, 31, false) +
      _exec_is_date(2000, 6, 30, true) + _exec_is_date(2000, 6, 31, false) +
      _exec_is_date(2000, 9, 30, true) + _exec_is_date(2000, 9, 31, false) +
      _exec_is_date(2000, 11, 30, true) + _exec_is_date(2000, 11, 31, false);

  // leap case
  fail_count +=
      _exec_is_date(2000, 2, 28, true) + _exec_is_date(2000, 2, 29, true) +
      _exec_is_date(2001, 2, 28, true) + _exec_is_date(2001, 2, 29, false) +
      _exec_is_date(2004, 2, 29, true) + _exec_is_date(2100, 2, 29, false) +
      _exec_is_date(2400, 2, 29, true);

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
