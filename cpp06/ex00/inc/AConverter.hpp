#ifndef CPP06_EX00_AConverter_H_
#define CPP06_EX00_AConverter_H_

#include "IScalar.hpp"
#include <string>

class AConverter {
public:
  AConverter(void);
  AConverter(AConverter *);
  virtual ~AConverter(void);

  IScalar *convert(const std::string &) const;

protected:
  AConverter *next_;

private:
  AConverter(const AConverter &);
  AConverter &operator=(const AConverter &);

  virtual IScalar *convertTo(const std::string &) const = 0;
};

#endif
