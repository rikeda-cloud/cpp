#ifndef CPP06_DoubleConverter_H_
#define CPP06_DoubleConverter_H_

#include "AConverter.hpp"
#include "IScalar.hpp"

class DoubleConverter : public AConverter {
public:
  DoubleConverter(void);
  DoubleConverter(AConverter *);
  ~DoubleConverter(void);

private:
  DoubleConverter(const DoubleConverter &other);
  DoubleConverter &operator=(const DoubleConverter &other);

  IScalar *convertTo(const std::string &) const;
};

#endif
