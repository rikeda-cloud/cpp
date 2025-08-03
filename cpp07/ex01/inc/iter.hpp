#ifndef CPP07_EX01_iter_H_
#define CPP07_EX01_iter_H_
#include <cstddef>
#include <iostream>

template <typename T, typename Func>
void iter(T *arr, std::size_t length, Func f) {
  // INFO 配列がNULL、または、関数ポインタがNULLの場合何もしない
  if (!arr || !f) {
    return;
  }

  for (std::size_t i = 0; i < length; ++i) {
    f(arr[i]);
  }
}

template <typename T> void x10(T &val) { val *= 10; };

template <typename T> void myprint(const T &val) { std::cout << val << " "; }

#endif
