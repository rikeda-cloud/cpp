#ifndef CPP06_FloatConverter_H_
#define CPP06_FloatConverter_H_

#include "AConverter.hpp"
#include "IScalar.hpp"

class FloatConverter : public AConverter {
public:
  FloatConverter(void);
  FloatConverter(AConverter *);
  ~FloatConverter(void);

private:
  FloatConverter(const FloatConverter &other);
  FloatConverter &operator=(const FloatConverter &other);

  IScalar *convertTo(const std::string &) const;
};

#endif
