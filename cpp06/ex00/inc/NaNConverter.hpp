#ifndef CPP06_NaNConverter_H_
#define CPP06_NaNConverter_H_

#include "AConverter.hpp"
#include "IScalar.hpp"

class NaNConverter : public AConverter {
public:
  NaNConverter(void);
  NaNConverter(AConverter *);
  ~NaNConverter(void);

private:
  NaNConverter(const NaNConverter &other);
  NaNConverter &operator=(const NaNConverter &other);

  IScalar *convertTo(const std::string &) const;
};

#endif
