#ifndef CPP06_EX00_IntScalar_H_
#define CPP06_EX00_IntScalar_H_

#include "IScalar.hpp"
#include <string>

class IntScalar : public IScalar {
public:
  IntScalar(int);
  ~IntScalar(void);
  std::string castToInt(void);
  std::string castToChar(void);
  std::string castToFloat(void);
  std::string castToDouble(void);

private:
  int value_;

  IntScalar(void);
  IntScalar(const IntScalar &other);
  IntScalar &operator=(const IntScalar &other);
};

#endif
