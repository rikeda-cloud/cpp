#ifndef CPP09_EX00_BitcoinExchange_H_
#define CPP09_EX00_BitcoinExchange_H_

#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange(const std::string &);
  ~BitcoinExchange(void);

  double findRate(const std::string &) const;

private:
  std::map<std::string, double> db_;
  std::string txt_file_;

  bool parseDatabase(const std::string &);

  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange &);
  BitcoinExchange &operator=(const BitcoinExchange &);
};

#endif
