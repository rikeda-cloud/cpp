#ifndef CPP06_CharConverter_H_
#define CPP06_CharConverter_H_

#include "AConverter.hpp"
#include "IScalar.hpp"

class CharConverter : public AConverter {
public:
  CharConverter(void);
  CharConverter(AConverter *);
  ~CharConverter(void);

private:
  CharConverter(const CharConverter &other);
  CharConverter &operator=(const CharConverter &other);

  IScalar *convertTo(const std::string &) const;
};

#endif
