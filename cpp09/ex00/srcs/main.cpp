#include "BitcoinExchange.hpp"
#include "DataBase.hpp"
#include <exception>
#include <iostream>

const std::string DB_FILE = "csv/data.csv";

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Specify inputfile as a command line argument." << std::endl;
    return 1;
  }

  DataBase db;
  try {
    DataBase::parseCsv(DB_FILE, db);
    BitcoinExchange::exchange(argv[1], db);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
