#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

bool test_cmp_ptr(Data *d) {
  uintptr_t ptr = Serializer::serialize(d);
  Data *deserialized_d = Serializer::deserialize(ptr);

  if (d == deserialized_d) {
    std::cout << GREEN << "[OK]" << RESET << std::endl;
    return false;
  } else {
    std::cout << RED << "[FAIL]" << RESET << std::endl;
    return true;
  }
}

bool test_cmp_param(Data *d) {
  uintptr_t ptr = Serializer::serialize(d);
  Data *deserialized_d = Serializer::deserialize(ptr);

  if (d->param == deserialized_d->param) {
    std::cout << GREEN << "[OK]" << RESET << std::endl;
    return false;
  } else {
    std::cout << RED << "[FAIL]" << RESET << std::endl;
    return true;
  }
}

int main(void) {
  Data *d1 = new Data(1, true);
  Data *d2 = new Data(2, false);
  Data *null = NULL;

  int fail_count = test_cmp_ptr(d1) + test_cmp_ptr(d2) + test_cmp_ptr(null) +
                   test_cmp_param(d1) + test_cmp_param(d2);

  delete d1;
  delete d2;
  return fail_count != 0;
}
