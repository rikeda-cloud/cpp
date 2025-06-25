#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange(const std::string &txt_file)
    : txt_file_(txt_file) {
  parseDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange(void) {}

bool BitcoinExchange::parseDatabase(const std::string &db_file) {
  std::ifstream f(db_file.c_str());

  if (!f) {
    return false;
  }

  std::string line;
  std::getline(f, line); // 1行目は読み飛ばす
  while (std::getline(f, line)) {
    size_t comma_pos = line.find(',');
    if (comma_pos == std::string::npos) {
      continue; // 不正な行なら読み飛ばす
    }

    std::string date = line.substr(0, comma_pos);
    std::string value_str = line.substr(comma_pos + 1);

    char *end;
    double value = std::strtod(value_str.c_str(), &end);

    if (*end != '\0') {
      continue; // 無効な変換なら読み飛ばす
    }

    db_[date] = value;
  }

  f.close();
  return true;
}

double BitcoinExchange::findRate(const std::string &date) const {
  std::map<std::string, double>::const_iterator it = db_.find(date);

  if (it != db_.end()) {
    return it->second; // 日付が見つかった場合はその値を返す
  }

  it = db_.upper_bound(date);
  if (it == db_.begin()) {
    // dateよりも前のデータが存在しない
    std::cout << "Error: No data available for date " << date << std::endl;
    return -1.0; // エラー値を返す
  }

  --it;
  return it->second; // dateよりも前の最新のデータを返す
}
