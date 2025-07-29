#include "Base.hpp"
#include "utils.hpp"
#include <cstddef>

int main(void) {
  Base *ptr = generate();
  Base &ref = *ptr;

  identify(ptr);
  identify(ref);
  identify(NULL);

  delete ptr;
  return 0;
}
