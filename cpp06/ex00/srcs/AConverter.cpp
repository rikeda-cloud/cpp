#include "AConverter.hpp"
#include "IScalar.hpp"

AConverter::AConverter(void) : next_(NULL) {}

AConverter::AConverter(AConverter *next) : next_(next) {}

AConverter::~AConverter(void) {}

IScalar *AConverter::convert(const std::string &s) const {
  if (canConvert(s)) {
    return convertTo(s);
  }
  if (next_) {
    return next_->convert(s);
  }
  return NULL;
}
