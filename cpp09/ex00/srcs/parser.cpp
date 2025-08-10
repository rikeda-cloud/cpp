#include "parser.hpp"
#include <cstdlib>
#include <iostream>

bool parseLine(const std::string &line, const std::string &sep,
               std::string &key, double &value) {
  size_t sep_pos = line.find(sep);
  if (sep_pos == std::string::npos) {
    std::cout << "Error: bad input => " << line << std::endl;
    return false;
  }

  std::string date = line.substr(0, sep_pos);
  std::string value_str = line.substr(sep_pos + sep.size());

  if (!validateBtcDate(date)) {
    std::cout << "Error: bad date => " << date << std::endl;
    return false;
  }
  if (!valiadteValue(value_str)) {
    std::cout << "Error: bad value => " << value_str << std::endl;
    return false;
  }
  key = date;
  value = std::strtod(value_str.c_str(), NULL);

  if (value < 0) {
    std::cout << "Error: not a positive number." << std::endl;
    return false;
  }
  return true;
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
  if (*end != '\0') {
    return false;
  }
  int day = std::strtol(day_str.c_str(), &end, 10);
  if (*end != '\0') {
    return false;
  }
  return isDate(year, month, day);
}

bool valiadteValue(const std::string &value) {
  char *end;

  if (value.size() == 0) {
    return false;
  }
  std::strtod(value.c_str(), &end);
  return *end == '\0';
}

bool isDate(int year, int month, int day) {
  const int LAST_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (!(1 <= month && month <= 12)) {
    return false;
  }

  //閏年判定
  bool is_leap_year = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  int last_day = LAST_DAYS[month - 1];

  if (month == 2 && is_leap_year) {
    last_day = 29;
  }
  return 1 <= day && day <= last_day;
}
