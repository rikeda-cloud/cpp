#ifndef CPP08_EX00_easyfind_H_
#define CPP08_EX00_easyfind_H_

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container, int val) {
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    if (*it == val) {
      return it;
    }
  }
  return container.end();
};

#endif
