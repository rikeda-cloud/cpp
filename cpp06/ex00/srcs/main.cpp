#include "AConverter.hpp"
#include "CharConverter.hpp"
#include "DoubleConverter.hpp"
#include "FloatConverter.hpp"
#include "IntConverter.hpp"

int main(void) {
  IntConverter cvt;
  CharConverter cvt2(&cvt);
  FloatConverter cvt3(&cvt2);
  DoubleConverter cvt4(&cvt3);

  cvt4.convert("42");
  return 0;
}
