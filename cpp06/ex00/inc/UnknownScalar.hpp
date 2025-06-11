#ifndef CPP06_EX00_UnknownScalar_H_
#define CPP06_EX00_UnknownScalar_H_

#include "IScalar.hpp"
#include <string>

class UnknownScalar : public IScalar {
public:
  UnknownScalar(void);
  ~UnknownScalar(void);
  std::string castToInt(void);
  std::string castToChar(void);
  std::string castToFloat(void);
  std::string castToDouble(void);

private:
  UnknownScalar(const UnknownScalar &other);
  UnknownScalar &operator=(const UnknownScalar &other);
};

#endif
