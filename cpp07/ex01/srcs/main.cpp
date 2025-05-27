#include "iter.hpp"
#include <iostream>

void x2(int &x) { x *= 2; }
void toUpper(std::string &s) {
  for (size_t i = 0; i < s.length(); ++i) {
    s[i] = std::toupper(s[i]);
  }
}
void x10(double &x) { x *= 10; }

bool testIntArray() {
  size_t length = 5;
  int arr[] = {1, 2, 3, 4, 5};
  int expect[] = {2, 4, 6, 8, 10};

  iter(arr, length, x2);

  for (size_t i = 0; i < length; ++i) {
    if (arr[i] != expect[i]) {
      std::cerr << "Test failed at index " << i << ": expected " << expect[i]
                << ", got " << arr[i] << std::endl;
      return false;
    }
  }
  return true;
}

bool testStringArray() {
  size_t length = 2;
  std::string arr[] = {"Hello", "World"};
  std::string expect[] = {"HELLO", "WORLD"};

  iter(arr, length, toUpper);

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
  size_t length = 4;
  double arr[] = {1.1, 2.2, 3.3, 4.4};
  double expect[] = {11.0, 22.0, 33.0, 44.0};

  iter(arr, length, x10);

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
  if (testStringArray())
    std::cout << "String array test passed." << std::endl;
  if (testDouble())
    std::cout << "Double array test passed." << std::endl;

  return 0;
}
