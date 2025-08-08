#include "parser.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>

void parseCsv(const std::string &file, DataBase &db) {
  std::ifstream s(file.c_str());
  std::string line;
  std::string key;
  double value;

  bool read_first_line = false;
  while (std::getline(s, line)) {
    if (!read_first_line) { // 最初の行(Header)は読み飛ばす
      read_first_line = true;
      continue;
    }
    parseLine(line, ",", key, value);
    db.insert(key, value);
  }
  s.close();
}

void parseLine(const std::string &line, const std::string &sep,
               std::string &key, double &value) {
  size_t comma_pos = line.find(sep);
  if (comma_pos == std::string::npos) {
    throw std::runtime_error("Invalid format.");
  }

  std::string date = line.substr(0, comma_pos);
  std::string value_str = line.substr(comma_pos + 1);

  if (!validateBtcDate(date) || !valiadteValue(value_str)) {
    throw std::runtime_error("Invalid format.");
  }

  key = date;
  value = std::strtod(value_str.c_str(), NULL);
}

bool validateBtcDate(const std::string &date) {
  if (date.size() != std::string("xxxx-xx-xx").size() || date[4] != '-' ||
      date[7] != '-') {
    return false;
  }

  std::string year_str = date.substr(0, 4);
  std::string month_str = date.substr(5, 2);
  std::string day_str = date.substr(8, 2);

  char *end;
  int year = std::strtol(year_str.c_str(), &end, 10);
  // https://ja.wikipedia.org/wiki/%E3%83%93%E3%83%83%E3%83%88%E3%82%B3%E3%82%A4%E3%83%B3
  if (*end != '\0' || year < 2009) {
    return false;
  }
  int month = std::strtol(month_str.c_str(), &end, 10);
  if (*end != '\0' || month < 1 || 12 < month) {
    return false;
  }
  int day = std::strtol(day_str.c_str(), &end, 10);
  if (*end != '\0' || day < 1 || 31 < day) {
    return false;
  }

  // TODO 閏年や月ごとの最終日のバリデーションを追加
  return true;
}

bool valiadteValue(const std::string &value) {
  char *end;
  std::strtod(value.c_str(), &end);
  return *end == '\0';
}
