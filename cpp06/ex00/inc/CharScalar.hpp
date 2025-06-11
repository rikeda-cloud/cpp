#ifndef CPP06_EX00_CharScalar_H_
#define CPP06_EX00_CharScalar_H_

#include "IScalar.hpp"
#include <string>

class CharScalar : public IScalar {
public:
  CharScalar(char);
  ~CharScalar(void);
  std::string castToInt(void);
  std::string castToChar(void);
  std::string castToFloat(void);
  std::string castToDouble(void);

private:
  char value_;

  CharScalar(void);
  CharScalar(const CharScalar &other);
  CharScalar &operator=(const CharScalar &other);
};

#endif
