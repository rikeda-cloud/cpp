#ifndef CPP06_EX00_DoubleScalar_H_
#define CPP06_EX00_DoubleScalar_H_

#include <IScalar.hpp>

class DoubleScalar : public IScalar {
public:
  DoubleScalar(double);
  ~DoubleScalar(void);
  int castToInt(void);
  char castToChar(void);
  float castToFloat(void);
  double castToDouble(void);

private:
  double value_;

  DoubleScalar(void);
  DoubleScalar(const DoubleScalar &other);
  DoubleScalar &operator=(const DoubleScalar &other);
};

#endif
