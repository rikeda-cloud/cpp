#include "AConverter.hpp"
#include "IScalar.hpp"
#include "UnknownScalar.hpp"

AConverter::AConverter(void) : next_(NULL) {}

AConverter::AConverter(AConverter *next) : next_(next) {}

AConverter::~AConverter(void) {}

IScalar *AConverter::convert(const std::string &s) const {
  IScalar *result = convertTo(s);
  if (result) {
    return result;
  }
  if (this->next_) {
    return next_->convert(s);
  }
  return new UnknownScalar();
}
