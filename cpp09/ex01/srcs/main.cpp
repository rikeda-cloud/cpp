#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "argc != 2" << std::endl;
    return 1;
  }

  try {
    std::cout << RPN::evaluate(argv[1]) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  return 0;
}
