#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void) {
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(0));
    seeded = true;
  }

  switch (std::rand() % 3) {
  case 0:
    return new A;
  case 1:
    return new B;
  case 2:
    return new C;
  }
  return NULL;
}

void identify(Base *p) {
  A *aptr = dynamic_cast<A *>(p);
  B *bptr = dynamic_cast<B *>(p);
  C *cptr = dynamic_cast<C *>(p);

  if (aptr) {
    std::cout << "A" << std::endl;
  } else if (bptr) {
    std::cout << "B" << std::endl;
  } else if (cptr) {
    std::cout << "C" << std::endl;
  } else {
    std::cout << "Could not convert" << std::endl;
  }
}

void identify(Base &p) {
  try {
    dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (const std::exception &) {
  }

  try {
    dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (const std::exception &) {
  }

  try {
    dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (const std::exception &) {
  }
  std::cout << "Could not convert" << std::endl;
}
