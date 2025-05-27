#ifndef CPP07_EX02_Array_H_
#define CPP07_EX02_Array_H_

template <typename T> class Array {
public:
  Array(void);
  Array(unsigned int);
  ~Array(void);
  Array(const Array<T> &arr);
  Array &operator=(const Array<T> &);
  T &operator[](unsigned int);
  const T &operator[](unsigned int) const;
  unsigned int size(void) const;

private:
  T *array_;
  unsigned int size_;
};

#include "Array.hpp"

#endif
