#ifndef CPP06_EX00_IntScalar_H_
#define CPP06_EX00_IntScalar_H_

#include <IScalar.hpp>

class IntScalar : public IScalar {
public:
  IntScalar(int);
  ~IntScalar(void);
  int castToInt(void);
  char castToChar(void);
  float castToFloat(void);
  double castToDouble(void);

private:
  int value_;

  IntScalar(void);
  IntScalar(const IntScalar &other);
  IntScalar &operator=(const IntScalar &other);
};

#endif
