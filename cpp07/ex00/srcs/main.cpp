#include "Data.hpp"
#include "whatever.hpp"
#include <iostream>

void sample_main(void) {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void test_return_second_value(void) {
  // min, max関数で値が等しい場合に第二引数の値が返されるか？

  // INFO 比較される値は同じ
  int comparable_v = 1;
  int incomparable_v1 = 1;
  int incomparable_v2 = 2;
  Data d1(comparable_v, incomparable_v1);
  Data d2(comparable_v, incomparable_v2);

  if (::min(d1, d2).getIncomparableV() == incomparable_v2 &&
      ::max(d1, d2).getIncomparableV() == incomparable_v2) {
    std::cout << "[OK]" << std::endl;
  } else {
    std::cout << "[ERROR]" << std::endl;
  }

  ::swap(d1, d2);
  if (::min(d1, d2).getIncomparableV() == incomparable_v1 &&
      ::max(d1, d2).getIncomparableV() == incomparable_v1) {
    std::cout << "[OK]" << std::endl;
  } else {
    std::cout << "[ERROR]" << std::endl;
  }
}

int main(void) {
  sample_main();
  test_return_second_value();

  return 0;
}
