#ifndef CPP06_IntConverter_H_
#define CPP06_IntConverter_H_

#include "AConverter.hpp"
#include "IScalar.hpp"

class IntConverter : public AConverter {
public:
  IntConverter(void);
  IntConverter(AConverter *);
  ~IntConverter(void);

private:
  IntConverter(const IntConverter &other);
  IntConverter &operator=(const IntConverter &other);

  IScalar *convertTo(const std::string &) const;
  bool canConvert(const std::string &) const;
};

#endif
