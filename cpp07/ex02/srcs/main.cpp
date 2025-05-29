#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

void testConstructor(void) {
  // パタメータ無しでインスタンス化し、配列が空であるか?
}

void testCustomConstructor(void) {
  // 引数アリでインスタンス化し、size()==nか?
  // デフォルト値で初期化されるか？
}

void testCopyConstructor(void) {
  // コピーコンストラクタで、コピー元と同じ値を持つか？
  // コピー元の変更がコピー先に影響しないか？
}

void testAssignmentOperator(void) {
  // 代入演算子で、コピー元と同じ値を持つか？
  // コピー元の変更がコピー先に影響しないか？
}

void testAccessOperator(void) {
  // 添字演算子でアクセス、範囲外参照でstd::exception がスローされるか？
}

void testSizeMethod(void) {
  // sizeが配列の要素数を返すか？
}

int main(void) {
  testConstructor();
  testCustomConstructor();
  testCopyConstructor();
  testAssignmentOperator();
  testAccessOperator();
  testSizeMethod();

  return 0;
}
