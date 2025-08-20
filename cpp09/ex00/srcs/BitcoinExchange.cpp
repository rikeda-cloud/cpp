#include "BitcoinExchange.hpp"
#include "DataBase.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>

void BitcoinExchange::exchange(const std::string &file, const DataBase &db) {
  std::ifstream s(file.c_str());
  std::string line;
  std::string key;
  double value;

  if (!s) {
    throw std::runtime_error("Error: could not open file.");
  }

  bool read_first_line = false;
  while (std::getline(s, line)) {
    if (!read_first_line) { // 最初の行(Header)は読み飛ばす
      read_first_line = true;
      continue;
    }

    // INFO Lineのパースが失敗したらエラーを表示し、次の行を処理
    try {
      parseLine(line, " | ", key, value);
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
      continue;
    }

    if (value > 1000.0) {
      std::cout << "Error: too large a number." << std::endl;
      continue;
    }
    double rate = db.select(key);
    if (rate == DataBase::NOT_FOUND) {
      std::cout << "Error: date is not found in db." << std::endl;
      continue;
    }
    std::cout << key << " => " << value << " = " << rate * value << std::endl;
  }
  if (s.eof() == false && s.fail()) {
    throw std::runtime_error("Error: could not read file.");
  }
  s.close();
  if (!read_first_line) {
    throw std::runtime_error("Error: empty file.");
  }
}
