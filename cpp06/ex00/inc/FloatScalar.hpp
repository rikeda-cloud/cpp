#ifndef CPP06_EX00_FloatScalar_H_
#define CPP06_EX00_FloatScalar_H_

#include "IScalar.hpp"
#include <string>

class FloatScalar : public IScalar {
public:
  FloatScalar(float);
  ~FloatScalar(void);
  std::string castToInt(void);
  std::string castToChar(void);
  std::string castToFloat(void);
  std::string castToDouble(void);

private:
  float value_;

  FloatScalar(void);
  FloatScalar(const FloatScalar &other);
  FloatScalar &operator=(const FloatScalar &other);
};

#endif
