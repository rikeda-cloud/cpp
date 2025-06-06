#ifndef CPP06_EX00_CharScalar_H_
#define CPP06_EX00_CharScalar_H_

#include <IScalar.hpp>

class CharScalar : public IScalar {
public:
  CharScalar(char);
  ~CharScalar(void);
  int castToInt(void);
  char castToChar(void);
  float castToFloat(void);
  double castToDouble(void);

private:
  char value_;

  CharScalar(void);
  CharScalar(const CharScalar &other);
  CharScalar &operator=(const CharScalar &other);
};

#endif
