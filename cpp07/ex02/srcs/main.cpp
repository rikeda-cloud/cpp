#include "Array.hpp"
#include "Array.tpp"
#include <exception>
#include <iostream>
#include <string>

void testDefaultConstructor(void) {
  // デフォルトコンストラクタでインスタンス化時、配列が空であるか?
  Array<int> arr;

  if (arr.size() == 0) {
    std::cout << "[OK]" << std::endl;
  } else {
    std::cout << "[ERROR] testDefaultConstructor: "
              << "size should be 0, got " << arr.size() << std::endl;
  }
}

void testCustomConstructor(void) {
  unsigned int n = 10;
  Array<float> arr(n);

  // 引数アリでインスタンス化し、size()==nか?
  if (arr.size() != n) {
    std::cout << "[ERROR] testCustomConstructor: "
              << "size should be " << n << ", got " << arr.size() << std::endl;
    return;
  }

  // デフォルト値で初期化されるか？
  for (unsigned int i = 0; i < n; ++i) {
    if (arr[i] != 0.0f) {
      std::cout << "[ERROR] testCustomConstructor: "
                << "element at index " << i << " should be 0.0, got " << arr[i]
                << std::endl;
      return;
    }
  }
  std::cout << "[OK]" << std::endl;
}

void testCopyConstructor(void) {
  unsigned int n = 2;
  Array<std::string> arr(n);
  arr[0] = "Hello";
  arr[1] = "World";

  // コピーコンストラクタで、コピー元と同じ値を持つか？
  Array<std::string> copy_arr(arr);
  for (unsigned int i = 0; i < n; ++i) {
    if (arr[i] != copy_arr[i]) {
      std::cout << "[ERROR] testCopyConstructor: "
                << "element at index " << i << " should be " << arr[i]
                << ", got " << copy_arr[i] << std::endl;
      return;
    }
  }

  // コピー元の変更がコピー先に影響しないか？
  copy_arr[0] = "Good";
  copy_arr[1] = "Evening";

  for (unsigned int i = 0; i < n; ++i) {
    if (arr[i] == copy_arr[i]) {
      std::cout << "[ERROR] testCopyConstructor: "
                << "element at index " << i
                << " should not be equal after modification, got "
                << copy_arr[i] << std::endl;
      return;
    }
  }
  std::cout << "[OK]" << std::endl;
}

void testAssignmentOperator(void) {
  unsigned int n = 3;
  Array<double> arr(n);
  arr[0] = 1.1;
  arr[1] = 2.2;
  arr[2] = 3.3;

  // 代入演算子で、コピー元と同じ値を持つか？
  Array<double> assignment_arr;
  assignment_arr = arr;
  for (unsigned int i = 0; i < arr.size(); ++i) {
    if (arr[i] != assignment_arr[i]) {
      std::cout << "[ERROR] testAssignmentOperator: "
                << "element at index " << i << " should be " << arr[i]
                << ", got " << assignment_arr[i] << std::endl;
      return;
    }
  }

  // コピー元の変更がコピー先に影響しないか？
  for (unsigned int i = 0; i < n; i++) {
    assignment_arr[i] *= 10;
  }
  for (unsigned int i = 0; i < n; ++i) {
    if (arr[i] == assignment_arr[i]) {
      std::cout << "[ERROR] testAssignmentOperator: "
                << "element at index " << i
                << " should not be equal after modification, got "
                << assignment_arr[i] << std::endl;
      return;
    }
  }
  std::cout << "[OK]" << std::endl;
}

void testAccessOperator(void) {
  unsigned int n = 5;
  Array<std::size_t> arr(n);

  // 添字演算子でアクセス、範囲外参照でstd::exception がスローされるか？
  try {
    arr[n + 1] = 42; // 範囲外アクセス
    std::cout << "[ERROR] testAccessOperator: "
              << "Access operator test failed." << std::endl;
  } catch (const std::exception &e) {
    std::cout << "[OK]" << std::endl;
  }
}

void testAccessOperatorEmptyArray(void) {
  Array<std::size_t> arr;

  // 空のArrayに対して、添字演算子でアクセス、
  // 範囲外参照でstd::exception がスローされるか？
  try {
    arr[0] = 42; // 範囲外アクセス
    std::cout << "[ERROR] testAccessOperatorEmptyArray: "
              << "Access empty array test failed." << std::endl;
  } catch (const std::exception &e) {
    std::cout << "[OK]" << std::endl;
  }
}

void testSelfAssignment(void) {
  unsigned int n = 4;
  Array<unsigned int> arr1(n);
  for (unsigned int i = 0; i < n; ++i) {
    arr1[i] = i;
  }

  // 自分自身に代入しても問題ないか？
  arr1 = arr1;
  for (unsigned int i = 0; i < n; ++i) {
    if (arr1[i] != i) {
      std::cout << "[ERROR] testSelfAssignment: "
                << "element at index " << i << " should be " << i << ", got "
                << arr1[i] << std::endl;
    }
  }
  std::cout << "[OK]" << std::endl;
}

int main(void) {
  try {
    testDefaultConstructor();
    testCustomConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testAccessOperator();
    testAccessOperatorEmptyArray();
    testSelfAssignment();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
