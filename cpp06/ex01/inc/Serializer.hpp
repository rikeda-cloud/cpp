#ifndef CPP06_EX01_Serializer_H_
#define CPP06_EX01_Serializer_H_

#include "Data.hpp"
#include <stdint.h>

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer(void);
  ~Serializer(void);
  Serializer(const Serializer &);
  Serializer &operator=(const Serializer &);
};

#endif
