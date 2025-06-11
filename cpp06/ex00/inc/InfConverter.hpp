#ifndef CPP06_InfConverter_H_
#define CPP06_InfConverter_H_

#include "AConverter.hpp"
#include "IScalar.hpp"

class InfConverter : public AConverter {
public:
  InfConverter(void);
  InfConverter(AConverter *);
  ~InfConverter(void);

private:
  InfConverter(const InfConverter &other);
  InfConverter &operator=(const InfConverter &other);

  IScalar *convertTo(const std::string &) const;
};

#endif
