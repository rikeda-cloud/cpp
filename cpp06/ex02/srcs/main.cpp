#include "Base.hpp"
#include "utils.hpp"
#include <cstddef>

int main(void) {
  Base *ptr = generate();
  Base &ref = *ptr;
  Base *nullp = NULL;
  Base &nullr = *nullp;

  identify(ptr);
  identify(ref);
  identify(nullp);
  identify(nullr);

  delete ptr;
  return 0;
}
