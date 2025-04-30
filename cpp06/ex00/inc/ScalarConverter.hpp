#ifndef CPP06_EX00_ScalarConverter_H_
#define CPP06_EX00_ScalarConverter_H_

#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &);

private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &);
  ~ScalarConverter(void);
  ScalarConverter &operator=(const ScalarConverter &);
};

#endif
