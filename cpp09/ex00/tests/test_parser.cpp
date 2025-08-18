#include "utils.hpp"
#include <iostream>

bool _exec_validate_date(const std::string &date, bool success_validate) {
  bool error_occurred = validateBtcDate(date) != success_validate;
  if (error_occurred) {
    std::cout << "[ERROR] _test_validate_btc_date: date = " << date
              << std::endl;
  }
  return error_occurred;
}

bool _exec_validate_value(const std::string &value, bool success_validate) {
  bool error_occurred = valiadteValue(value) != success_validate;
  if (error_occurred) {
    std::cout << "[ERROR] _test_validate_value: value = " << value << std::endl;
  }
  return error_occurred;
}

bool _exec_is_date(int y, int m, int d, bool success_validate) {
  bool error_occurred = isDate(y, m, d) != success_validate;
  if (error_occurred) {
    std::cout << "[ERROR] _test_is_date: y = " << y << " m = " << m
              << " d = " << d << std::endl;
  }
  return error_occurred;
}

bool _exec_parse_line(const std::string &line, const std::string &sep,
                      bool success_parse) {
  std::string key;
  double value;
  return parseLine(line, sep, key, value) != success_parse;
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

int _test_validate_value(void) {
  return _exec_validate_value("123", true) + _exec_validate_value(".1", true) +
         _exec_validate_value("1.", true) + _exec_validate_value("1.1", true) +
         _exec_validate_value("", false) + _exec_validate_value("1a", false);
}

int _test_is_date(void) {
  return _exec_is_date(0, 1, 1, true) + _exec_is_date(2000, 2, 29, true) +
         _exec_is_date(9999, 12, 31, true) + _exec_is_date(2001, 2, 28, true) +
         _exec_is_date(2004, 2, 29, true) + _exec_is_date(2000, 2, 29, true) +
         _exec_is_date(2100, 2, 29, false) + _exec_is_date(2000, 4, 31, false) +
         _exec_is_date(2000, 1, 0, false) + _exec_is_date(2000, 12, 32, false) +
         _exec_is_date(2000, 13, 1, false) + _exec_is_date(2001, 0, 1, false);
}

int _test_parse_line(void) {
  return _exec_parse_line("2020-01-01,123456", ",", true) +
         _exec_parse_line("2020-01-01 | 1.000000001", " | ", true) +
         _exec_parse_line("2020-01-01 | -123456", " | ", false) +
         _exec_parse_line("2020-01-01 || 1", " | ", false) +
         _exec_parse_line("2020-01-01 | 1 1", " | ", false) +
         _exec_parse_line("2020-01-01 ! 1 1", ",", false) +
         _exec_parse_line("2020-01-01,", ",", false) +
         _exec_parse_line("2020-01-01,1234", "", false) +
         _exec_parse_line(",12345", ",", false) +
         _exec_parse_line("   ,    ", ",", false) +
         _exec_parse_line("", ",", false);
}
