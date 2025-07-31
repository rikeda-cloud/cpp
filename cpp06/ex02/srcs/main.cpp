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
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
