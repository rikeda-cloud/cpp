#include "utils.hpp"
#include <iostream>

static bool _exec_validate_btc_date(const std::string &date,
                                    bool success_validate) {
  bool error_occurred = validateBtcDate(date) != success_validate;
  if (error_occurred) {
    std::cout << "[ERROR] _test_validate_btc_date: date = " << date
              << std::endl;
  }
  return error_occurred;
}

int test_validate_btc_date(void) {
  int fail_count = _exec_validate_btc_date("2009-01-01", true) +
                   _exec_validate_btc_date("2012-02-29", true) +
                   _exec_validate_btc_date("9999-12-31", true) +
                   _exec_validate_btc_date("2010-1-1", false) +
                   _exec_validate_btc_date("2010/01/01", false) +
                   _exec_validate_btc_date("2010-01-01a", false) +
                   _exec_validate_btc_date("201a-01-01", false) +
                   _exec_validate_btc_date("2015-a1-01", false) +
                   _exec_validate_btc_date("1234567890", false) +
                   _exec_validate_btc_date(" 2020-02-02", false) +
                   _exec_validate_btc_date("2020-02-02 ", false) +
                   _exec_validate_btc_date("2020- 02-02", false) +
                   _exec_validate_btc_date("2020-02 -02", false) +
                   _exec_validate_btc_date("2010-13-01", false) +
                   _exec_validate_btc_date("2010-12-32", false) +
                   _exec_validate_btc_date("0001-01-01", false) +
                   _exec_validate_btc_date("2010-02-31", false) +
                   _exec_validate_btc_date("", false);

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
