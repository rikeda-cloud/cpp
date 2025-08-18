#ifndef CPP08_EX00_BitcoinExchange_H_
#define CPP08_EX00_BitcoinExchange_H_

#include "DataBase.hpp"

class BitcoinExchange {
public:
  static void exchange(const std::string &, const DataBase &);

private:
  BitcoinExchange(void);
  ~BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange &);
  BitcoinExchange &operator=(const BitcoinExchange &);
};

#endif
