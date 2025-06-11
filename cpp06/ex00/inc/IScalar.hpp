#ifndef CPP06_EX00_IScalar_H_
#define CPP06_EX00_IScalar_H_

#include <string>

class IScalar {
public:
  virtual ~IScalar(void);
  virtual std::string castToInt(void) = 0;
  virtual std::string castToChar(void) = 0;
  virtual std::string castToFloat(void) = 0;
  virtual std::string castToDouble(void) = 0;

protected:
  IScalar(void);
  static const int FLOAT_PRECISION = 1;
  static const int DOUBLE_PRECISION = 1;

private:
  IScalar(const IScalar &other);
  IScalar &operator=(const IScalar &other);
};

#endif
