#include "iter.hpp"
#include <iostream>

void testIntArray() {
  size_t length = 5;
  int arr[] = {1, 2, 3, 4, 5};
  int expect[] = {10, 20, 30, 40, 50};

  iter(arr, length, x10<int &>);

  for (size_t i = 0; i < length; ++i) {
    if (arr[i] != expect[i]) {
      std::cerr << "Test failed at index " << i << ": expected " << expect[i]
                << ", got " << arr[i] << std::endl;
      return;
    }
  }
}

void testDouble() {
  size_t length = 5;
  double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double expect[] = {11.0, 22.0, 33.0, 44.0, 55.0};

  iter(arr, length, x10<double &>);

  for (size_t i = 0; i < length; ++i) {
    if (arr[i] != expect[i]) {
      std::cerr << "Test failed at index " << i << ": expected " << expect[i]
                << ", got " << arr[i] << std::endl;
      return;
    }
  }
}

void testNull() {
  double *ptr = NULL;
  iter(ptr, 0, x10<double &>);

  double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  void (*f)(double &) = NULL;
  iter(arr, 5, f);
}

int main(void) {
  testIntArray();
  testDouble();
  testNull();

  return 0;
}
