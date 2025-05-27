#ifndef CPP07_EX01_iter_H_
#define CPP07_EX01_iter_H_
#include <cstddef>

template <typename T> void iter(T *arr, std::size_t length, void (*f)(T &)) {
  for (std::size_t i = 0; i < length; ++i) {
    f(arr[i]);
  }
};

#endif
