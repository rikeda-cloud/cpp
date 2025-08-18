#include "utils.hpp"
#include <exception>
#include <iostream>

static bool _exec_parse_line(const std::string &line, const std::string &sep,
                             bool expect_exception) {
  std::string key;
  double value;

  try {
    parseLine(line, sep, key, value);
    if (expect_exception) {
      std::cout << "[KO] test_parse_line: no throw exception" << std::endl;
      return true;
    }
  } catch (const std::exception &e) {
    if (!expect_exception) {
      std::cout << "[KO] test_parse_line: throw exception" << std::endl;
      return true;
    }
  }
  return false;
}

int test_parse_line(void) {
  int fail_count = _exec_parse_line("2020-01-01,123456", ",", false) +
                   _exec_parse_line("2020-01-01 | 1.000000001", " | ", false) +
                   _exec_parse_line("2020-01-01 | -123456", " | ", true) +
                   _exec_parse_line("2020-01-01 || 1", " | ", true) +
                   _exec_parse_line("2020-01-01 | 1 1", " | ", true) +
                   _exec_parse_line("2020-01-01 ! 1 1", ",", true) +
                   _exec_parse_line("2020-01-01,", ",", true) +
                   _exec_parse_line("2020-01-01,1234", "", true) +
                   _exec_parse_line(",12345", ",", true) +
                   _exec_parse_line("   ,    ", ",", true) +
                   _exec_parse_line("    -  -  ,10", ",", true) +
                   _exec_parse_line("", ",", true);

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
