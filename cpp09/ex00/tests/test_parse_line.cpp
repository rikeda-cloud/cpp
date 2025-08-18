#include "utils.hpp"
#include <iostream>

static bool _exec_parse_line(const std::string &line, const std::string &sep,
                             bool success_parse) {
  std::string key;
  double value;
  return parseLine(line, sep, key, value) != success_parse;
}

int test_parse_line(void) {
  int fail_count = _exec_parse_line("2020-01-01,123456", ",", true) +
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

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
