#ifndef CPP06_EX00_DoubleScalar_H_
#define CPP06_EX00_DoubleScalar_H_

#include "IScalar.hpp"
#include <string>

class DoubleScalar : public IScalar {
public:
  DoubleScalar(double);
  ~DoubleScalar(void);
  std::string castToInt(void);
  std::string castToChar(void);
  std::string castToFloat(void);
  std::string castToDouble(void);

private:
  double value_;

  DoubleScalar(void);
  DoubleScalar(const DoubleScalar &other);
  DoubleScalar &operator=(const DoubleScalar &other);
};

#endif
