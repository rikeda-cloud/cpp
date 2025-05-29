#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#include <string>

void testDefaultConstructor(void) {
  Array<int> arr;

  // パタメータ無しでインスタンス化し、配列が空であるか?
  if (arr.size() != 0) {
    std::cerr << "Default constructor failed: size should be 0, got "
              << arr.size() << std::endl;
  }
}

void testCustomConstructor(void) {
  unsigned int n = 10;
  Array<float> arr(n);

  // 引数アリでインスタンス化し、size()==nか?
  if (arr.size() != n) {
    std::cerr << "Custom constructor failed: size should be " << n << ", got "
              << arr.size() << std::endl;
  }

  // デフォルト値で初期化されるか？
  for (unsigned int i = 0; i < n; ++i) {
    if (arr[i] != 0.0f) {
      std::cerr << "Custom constructor failed: element at index " << i
                << " should be 0.0, got " << arr[i] << std::endl;
    }
  }
}

void testCopyConstructor(void) {
  unsigned int n = 2;
  Array<std::string> arr1(n);
  arr1[0] = "Hello";
  arr1[1] = "World";

  // コピーコンストラクタで、コピー元と同じ値を持つか？
  Array<std::string> arr2(arr1);
  for (unsigned int i = 0; i < n; ++i) {
    if (arr1[i] != arr2[i]) {
      std::cerr << "Copy constructor failed: element at index " << i
                << " should be " << arr1[i] << ", got " << arr2[i] << std::endl;
    }
  }

  // コピー元の変更がコピー先に影響しないか？
  arr2[0] = "Good";
  arr2[1] = "Evening";

  for (unsigned int i = 0; i < n; ++i) {
    if (arr1[i] == arr2[i]) {
      std::cerr << "Copy constructor failed: element at index " << i
                << " should not be equal after modification, got " << arr2[i]
                << std::endl;
    }
  }
}

void testAssignmentOperator(void) {
  unsigned int n = 3;
  Array<double> arr1(n);
  arr1[0] = 1.1;
  arr1[1] = 2.2;
  arr1[2] = 3.3;

  // 代入演算子で、コピー元と同じ値を持つか？
  Array<double> arr2;
  arr2 = arr1;
  for (unsigned int i = 0; i < arr1.size(); ++i) {
    if (arr1[i] != arr2[i]) {
      std::cerr << "Assignment operator failed: element at index " << i
                << " should be " << arr1[i] << ", got " << arr2[i] << std::endl;
    }
  }

  // コピー元の変更がコピー先に影響しないか？
  arr2[0] *= 10;
  arr2[1] *= 10;
  arr2[2] *= 10;
  for (unsigned int i = 0; i < n; ++i) {
    if (arr1[i] == arr2[i]) {
      std::cerr << "Assignment operator failed: element at index " << i
                << " should not be equal after modification, got " << arr2[i]
                << std::endl;
    }
  }
}

void testAccessOperator(void) {
  unsigned int n = 5;
  Array<std::size_t> arr(n);

  // 添字演算子でアクセス、範囲外参照でstd::exception がスローされるか？
  try {
    arr[n + 1] = 42; // 範囲外アクセス
    std::cerr << "Access operator test failed." << std::endl;
  } catch (const std::exception &e) {
    if (e.what() != std::string("std::exception")) {
      std::cerr << "Access operator test failed: expected std::exception, got "
                << e.what() << std::endl;
    }
  }
}

void testAccessOperatorEmptyArray(void) {
  Array<std::size_t> arr;

  // 空のArrayに対して、添字演算子でアクセス、
  // 範囲外参照でstd::exception がスローされるか？
  try {
    arr[0] = 42; // 範囲外アクセス
    std::cerr << "Access empty array test failed." << std::endl;
  } catch (const std::exception &e) {
    if (e.what() != std::string("std::exception")) {
      std::cerr
          << "Access empty array test failed: expected std::exception, got "
          << e.what() << std::endl;
    }
  }
}

void testSelfAssignment(void) {
  unsigned int n = 4;
  Array<unsigned int> arr1(n);
  for (unsigned int i = 0; i < n; ++i) {
    arr1[i] = (i + 1) * 10;
  }

  // 自分自身に代入しても問題ないか？
  arr1 = arr1;
  for (unsigned int i = 0; i < n; ++i) {
    if (arr1[i] != (i + 1) * 10) {
      std::cerr << "Self-assignment test failed: element at index " << i
                << " should be " << (i + 1) * 10 << ", got " << arr1[i]
                << std::endl;
    }
  }
}

int main(void) {
  testDefaultConstructor();
  testCustomConstructor();
  testCopyConstructor();
  testAssignmentOperator();
  testAccessOperator();
  testAccessOperatorEmptyArray();
  testSelfAssignment();

  return 0;
}
