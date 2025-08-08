#ifndef CPP08_EX00_easyfind_T_
#define CPP08_EX00_easyfind_T_

#include <string>
#include <iostream>

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

template <typename T>
typename T::iterator easyfind(T &container, int val) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == val) {
			return it;
		}
	}
	return container.end();
}

template <typename T>
bool test_container(const T &container, const std::string &container_type,
                    int p, bool expect_find) {
  bool actual_find = easyfind(container, p) != container.end();

  if (actual_find == expect_find) {
    std::cout << "[OK]" << std::endl;
    return false;
  } else {
    std::cout << "[FAIL] " << container_type << ": {";
    for (typename T::const_iterator it = container.begin();
         it != container.end(); ++it) {
      std::cout << " " << *it;
    }
    std::cout << " } Param: " << p << std::endl;
    return true;
  }
}

#endif
