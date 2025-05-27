#include "iter.hpp"
#include <iostream>

bool testIntArray() {
  size_t length = 5;
  int arr[] = {1, 2, 3, 4, 5};
  int expect[] = {10, 20, 30, 40, 50};

  iter(arr, length, x10<int &>);

  for (size_t i = 0; i < length; ++i) {
    if (arr[i] != expect[i]) {
      std::cerr << "Test failed at index " << i << ": expected " << expect[i]
                << ", got " << arr[i] << std::endl;
      return false;
    }
  }
  return true;
}

bool testDouble() {
  size_t length = 5;
  double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double expect[] = {11.0, 22.0, 33.0, 44.0, 55.0};

  iter(arr, length, x10<double &>);

  for (size_t i = 0; i < length; ++i) {
    if (arr[i] != expect[i]) {
      std::cerr << "Test failed at index " << i << ": expected " << expect[i]
                << ", got " << arr[i] << std::endl;
      return false;
    }
  }
  return true;
}

int main(void) {
  if (testIntArray())
    std::cout << "Integer array test passed." << std::endl;
  if (testDouble())
    std::cout << "Double array test passed." << std::endl;

  return 0;
}
