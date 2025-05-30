#include "AConverter.hpp"
#include "CharConverter.hpp"
#include "IntConverter.hpp"

int main(void) {
  IntConverter cvt;
  CharConverter cvt2(&cvt);

  cvt2.convert("42");
  return 0;
}
