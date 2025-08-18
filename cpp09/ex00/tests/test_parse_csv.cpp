#include "DataBase.hpp"
#include <exception>
#include <iostream>

bool _exec_parse_csv(const std::string &file, bool expect_exception) {
  DataBase db;

  try {
    DataBase::parseCsv(file, db);
    if (expect_exception) {
      std::cout << "[KO] test_parse_csv: no throw exception" << std::endl;
    }
  } catch (const std::exception &e) {
    if (!expect_exception) {
      std::cout << "[KO] test_parse_csv: throw unexpect exception" << std::endl;
      return true;
    }
  }
  return false;
}

int test_parse_csv(void) {
  const std::string csv_dir = "./csv/";
  int fail_count = _exec_parse_csv(csv_dir + "data.csv", false) +
                   _exec_parse_csv(csv_dir + "only_header.csv", false) +
                   _exec_parse_csv("", true) +
                   _exec_parse_csv(csv_dir + "has_empty_line.csv", true) +
                   _exec_parse_csv("invalid_date.csv", true) +
                   _exec_parse_csv("invalid_value.csv", true) +
                   _exec_parse_csv("invalid_separator.csv", true) +
                   _exec_parse_csv(csv_dir + "empty.csv", true);

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
