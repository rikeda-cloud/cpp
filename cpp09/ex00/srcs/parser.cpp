#include "parser.hpp"
#include <cstdlib>
#include <sstream>
#include <stdexcept>

void parseCsv(const std::string &file, DataBase &db) {}

void parseLine(const std::string &line, const std::string &sep,
               std::string &key, double &value) {
  size_t comma_pos = line.find(sep);
  if (comma_pos == std::string::npos) {
    throw std::runtime_error("Invalid format.");
  }

  std::string date = line.substr(0, comma_pos);
  std::string value_str = line.substr(comma_pos + 1);

  if (!validateDate(date) || !valiadteValue(value_str)) {
    throw std::runtime_error("Invalid format.");
  }

  key = date;
  value = std::strtod(value_str.c_str(), NULL);
}

bool validateDate(const std::string &date) {
  size_t first_div_c_pos = date.find('-');
  if (first_div_c_pos == std::string::npos) {
    return false;
  }

  size_t second_div_c_pos = date.find('-', first_div_c_pos + 1);
  if (second_div_c_pos == std::string::npos) {
    return false;
  }

  std::string year_str = date.substr(0, first_div_c_pos);
  size_t month_size = second_div_c_pos - (first_div_c_pos + 1);
  std::string month_str = date.substr(first_div_c_pos + 1, month_size);
  std::string day_str = date.substr(second_div_c_pos + 1);

  char *end;
  int year = std::strtol(year_str.c_str(), &end, 10);
  if (*end != '\0') {
    return false;
  }
  int month = std::strtol(year_str.c_str(), &end, 10);
  if (*end != '\0' || month < 1 || 12 < month) {
    return false;
  }
  int day = std::strtol(year_str.c_str(), &end, 10);
  if (*end != '\0' || day < 1 || 31 < day) {
    return false;
  }

  return true;
}

bool valiadteValue(const std::string &value) {
  char *end;
  double parsed_value = std::strtod(value.c_str(), &end);
  return *end == '\0';
}
