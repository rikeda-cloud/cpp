#include "AConverter.hpp"
#include "IntConverter.hpp"

int main(void) {
  IntConverter cvt;
  IntConverter cvt2(&cvt);
  IntConverter cvt3(&cvt2);

  cvt3.convert("42");
  return 0;
}
