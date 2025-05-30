#include "AConverter.hpp"
#include "CharConverter.hpp"
#include "FloatConverter.hpp"
#include "IntConverter.hpp"

int main(void) {
  IntConverter cvt;
  CharConverter cvt2(&cvt);
  FloatConverter cvt3(&cvt2);

  cvt3.convert("42");
  return 0;
}
