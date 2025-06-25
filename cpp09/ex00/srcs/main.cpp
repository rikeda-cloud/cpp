#include "BitcoinExchange.hpp"
#include <iostream>

int main(void) {
  BitcoinExchange btc("abc.txt");
  std::cout << btc.findRate("2022-01-18") << std::endl;
  return 0;
}
