#ifndef CPP08_EX00_easyfind_T_
#define CPP08_EX00_easyfind_T_

template <typename T>
typename T::const_iterator easyfind(const T &container, int val) {
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    if (*it == val) {
      return it;
    }
  }
  return container.end();
}

#endif
