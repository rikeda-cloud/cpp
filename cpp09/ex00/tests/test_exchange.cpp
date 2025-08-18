#include "BitcoinExchange.hpp"
#include "DataBase.hpp"
#include <iostream>

bool _exec_exchange(const DataBase &db, const std::string &file,
                    bool expect_exception) {
  try {
    std::cout << "===== " << file << " =====" << std::endl;
    BitcoinExchange::exchange(file, db);
    if (expect_exception) {
      std::cout << "[KO] test_exchange: no throw exception" << std::endl;
      return true;
    }
  } catch (const std::exception &e) {
    if (!expect_exception) {
      std::cout << "[KO] test_exchange: throw exception" << std::endl;
      return true;
    }
  }
  std::cout << std::endl;
  return false;
}

int test_exchange(void) {
  DataBase db;
  DataBase::parseCsv("csv/data.csv", db);

  const std::string input_dir = "input/";

  int fail_count =
      _exec_exchange(db, input_dir + "input.txt", false) +
      _exec_exchange(db, input_dir + "only_header.txt", false) +
      _exec_exchange(db, input_dir + "has_empty_line.txt", false) +
      _exec_exchange(db, input_dir + "invalid_date.txt", false) +
      _exec_exchange(db, input_dir + "invalid_value.txt", false) +
      _exec_exchange(db, input_dir + "invalid_separator.txt", false) +
      _exec_exchange(db, input_dir + "greater_than_1000.txt", false) +
      _exec_exchange(db, input_dir + "2009-01-01.txt", false) +
      _exec_exchange(db, input_dir + "", true) +
      _exec_exchange(db, input_dir + "empty.txt", true);

  if (!fail_count) {
    std::cout << "[OK]" << std::endl;
  }
  return fail_count;
}
