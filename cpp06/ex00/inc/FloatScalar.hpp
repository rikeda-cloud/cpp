#ifndef CPP06_EX00_FloatScalar_H_
#define CPP06_EX00_FloatScalar_H_

#include <IScalar.hpp>

class FloatScalar : public IScalar {
public:
  FloatScalar(float);
  ~FloatScalar(void);
  int castToInt(void);
  char castToChar(void);
  float castToFloat(void);
  double castToDouble(void);

private:
  float value_;

  FloatScalar(void);
  FloatScalar(const FloatScalar &other);
  FloatScalar &operator=(const FloatScalar &other);
};

#endif
