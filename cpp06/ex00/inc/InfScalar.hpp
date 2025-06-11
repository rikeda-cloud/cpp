#ifndef CPP06_EX00_InfScalar_H_
#define CPP06_EX00_InfScalar_H_

#include "IScalar.hpp"
#include <string>

class InfScalar : public IScalar {
public:
  InfScalar(bool);
  ~InfScalar(void);
  std::string castToInt(void);
  std::string castToChar(void);
  std::string castToFloat(void);
  std::string castToDouble(void);

private:
  double minus_flag_;

  InfScalar(void);
  InfScalar(const InfScalar &other);
  InfScalar &operator=(const InfScalar &other);
};

#endif
