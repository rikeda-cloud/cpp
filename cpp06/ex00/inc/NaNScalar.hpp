#ifndef CPP06_EX00_NaNScalar_H_
#define CPP06_EX00_NaNScalar_H_

#include "IScalar.hpp"
#include <string>

class NaNScalar : public IScalar {
public:
  NaNScalar(void);
  ~NaNScalar(void);
  std::string castToInt(void);
  std::string castToChar(void);
  std::string castToFloat(void);
  std::string castToDouble(void);

private:
  NaNScalar(const NaNScalar &other);
  NaNScalar &operator=(const NaNScalar &other);
};

#endif
