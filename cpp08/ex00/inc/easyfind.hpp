#ifndef CPP08_EX00_easyfind_H_
#define CPP08_EX00_easyfind_H_

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container, int val);

#include "easyfind.tpp"

#endif
