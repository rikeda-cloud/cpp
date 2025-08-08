#include "parser.hpp"
#include <iostream>

bool _exec_validate_date(const std::string &date, bool success_validate) {
  bool error_occurred = validateBtcDate(date) != success_validate;
  if (error_occurred) {
    std::cout << "[ERROR] _test_validate_btc_date: date = " << date
              << std::endl;
  }
  return error_occurred;
}

int _test_validate_btc_date(void) {
  return _exec_validate_date("2009-01-01", true) +
         _exec_validate_date("2012-02-29", true) +
         _exec_validate_date("9999-12-31", true) +

         _exec_validate_date("2010-1-1", false) +
         _exec_validate_date("2010/01/01", false) +
         _exec_validate_date("2010-01-01a", false) +
         _exec_validate_date("201a-01-01", false) +
         _exec_validate_date("2015-a1-01", false) +
         _exec_validate_date("1234567890", false) +
         _exec_validate_date(" 2020-02-02", false) +
         _exec_validate_date("2020-02-02 ", false) +
         _exec_validate_date("2020- 02-02", false) +
         _exec_validate_date("2020-02 -02", false) +

         _exec_validate_date("2010-13-01", false) +
         _exec_validate_date("2010-12-32", false) +
         _exec_validate_date("0001-01-01", false) +
         _exec_validate_date("2010-02-31", false) +
         _exec_validate_date("", false);
}

int test_validate_value(void) {
  return (valiadteValue("123") != true) + (valiadteValue(".1") != true) +
         (valiadteValue("1.") != true) + (valiadteValue("1.1") != true) +
         (valiadteValue("") != false) + (valiadteValue("1a") != false);
}

int test_parser(void) {
  int fail_count = _test_validate_btc_date();
  return fail_count;
}
