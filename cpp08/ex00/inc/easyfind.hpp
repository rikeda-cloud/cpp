#ifndef CPP08_EX00_easyfind_H_
#define CPP08_EX00_easyfind_H_

#include <algorithm>
#include <string>

template <typename T>
typename T::const_iterator easyfind(const T &container, int val);

template <typename T> typename T::iterator easyfind(T &container, int val);

template <typename T>
bool test_container(const T &container, const std::string &container_type,
                    int p, bool expect_find);

#include "easyfind.tpp"

#endif
