#include "BitcoinExchange.hpp"
#include "DataBase.hpp"
#include <iostream>

bool _exec_exchange(const DataBase &db, const std::string &file,
                    bool expect_exception) {
  try {
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
  return false;
}

int test_exchange(void) {
  DataBase db;
  DataBase::parseCsv("csv/data.csv", db);

  const std::string input_dir = "input/";

  int fail_count = _exec_exchange(db, input_dir + "", true);

  return fail_count;
}
