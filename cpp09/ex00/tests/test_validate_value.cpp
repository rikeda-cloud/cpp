#include "utils.hpp"
#include <iostream>

static bool _exec_validate_value(const std::string &value,
                                 bool success_validate) {
  bool error_occurred = validateValue(value) != success_validate;
  if (error_occurred) {
    std::cout << "[ERROR] _test_validate_value: value = " << value << std::endl;
  }
  return error_occurred;
}

int test_validate_value(void) {
  int fail_count =
      _exec_validate_value("123", true) + _exec_validate_value(".1", true) +
      _exec_validate_value("1.", true) + _exec_validate_value("1.1", true) +
      _exec_validate_value("", false) + _exec_validate_value("1a", false);

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
