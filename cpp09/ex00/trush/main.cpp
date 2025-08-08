#include "BitcoinExchange.hpp"
#include <iostream>

int main(void) {
  BitcoinExchange btc("abc.txt");
  std::cout << btc.calcBitcoin("2011-01-03", 3) << std::endl;
  std::cout << btc.calcBitcoin("2011-01-03", 2) << std::endl;
  std::cout << btc.calcBitcoin("2011-01-03", 1) << std::endl;
  std::cout << btc.calcBitcoin("2011-01-03", 1.2) << std::endl;
  std::cout << btc.calcBitcoin("2011-01-09", 1) << std::endl;
  std::cout << btc.calcBitcoin("2012-01-11", 1) << std::endl;
  return 0;
}
