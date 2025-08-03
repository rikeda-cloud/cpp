#include "iter.hpp"
#include <iostream>

void testIntArray() {
  size_t length = 5;
  int arr[] = {1, 2, 3, 4, 5};
  int expect[] = {10, 20, 30, 40, 50};

  // INFO 非const参照で引数を受け取り、値を10倍にする関数テンプレートを使用
  iter(arr, length, x10<int>);

  for (size_t i = 0; i < length; ++i) {
    if (arr[i] != expect[i]) {
      std::cout << "[ERROR] testIntArray: "
                << "Test failed at index " << i << ": expected " << expect[i]
                << ", got " << arr[i] << std::endl;
      return;
    }
  }
  std::cout << "[OK]" << std::endl;
}

void testDoubleArray() {
  size_t length = 5;
  double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double expect[] = {11.0, 22.0, 33.0, 44.0, 55.0};

  iter(arr, length, x10<double>);

  for (size_t i = 0; i < length; ++i) {
    if (arr[i] != expect[i]) {
      std::cout << "[ERROR] testDoubleArray: "
                << "Test failed at index " << i << ": expected " << expect[i]
                << ", got " << arr[i] << std::endl;
      return;
    }
  }
  std::cout << "[OK]" << std::endl;
}

void testNull() {
  size_t length = 5;
  int *null_arr = NULL;
  void (*null_f)(int &) = NULL;
  int arr[] = {1, 2, 3, 4, 5};

  iter(null_arr, length, x10<int>);
  iter(arr, length, null_f);
  std::cout << "[OK]" << std::endl;
}

void testConstCharArray() {
  size_t length = 5;
  const char arr[] = {'a', 'b', 'c', 'd', 'e'};
  const std::string expect_output = "'a b c d e '";

  std::cout << "~~ 目grepで確認して!! ~~" << std::endl;
  std::cout << "expect: " << expect_output << std::endl;

  std::cout << "actual: '";
  // INFO const参照で引数を受け取り、出力する関数テンプレートを使用
  iter(arr, length, myprint<char>);
  std::cout << "'" << std::endl;
}

void testConstStringArray() {
  size_t length = 5;
  const std::string arr[] = {"A", "B", "C", "D", "E"};
  const std::string expect_output = "'A B C D E '";

  std::cout << "~~ 目grepで確認して!! ~~" << std::endl;
  std::cout << "expect: " << expect_output << std::endl;

  std::cout << "actual: '";
  iter(arr, length, myprint<std::string>);
  std::cout << "'" << std::endl;
}

int main(void) {
  testIntArray();
  testDoubleArray();
  testNull();
  testConstCharArray();
  testConstStringArray();

  return 0;
}
