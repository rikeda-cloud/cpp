#include "DataBase.hpp"
#include "parser.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Specify inputfile as a command line argument." << std::endl;
    return 1;
  }

  DataBase db;
  try {

    parseCsv(argv[1], db);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
