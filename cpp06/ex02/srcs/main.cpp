#include "Base.hpp"
#include "utils.hpp"
#include <cstddef>
#include <exception>
#include <iostream>

int main(void) {
  try {
    Base *ptr = generate();
    Base &ref = *ptr;

    identify(ptr);
    identify(ref);
    delete ptr;

    Base *nullp = NULL;
    Base &nullr = *nullp;
    identify(nullp);
    identify(nullr);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
