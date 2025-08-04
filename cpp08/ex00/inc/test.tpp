#ifndef CPP08_EX00_test_T_
#define CPP08_EX00_test_T_

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <string>
#include <iostream>

template <typename T>
bool test_container(const T &container, const std::string &container_type,
                    int p, bool expect_find) {
  bool actual_find = easyfind(container, p) != container.end();

  if (actual_find == expect_find) {
    std::cout << GREEN << "[OK]" << RESET << std::endl;
    return false;
  } else {
    std::cout << RED << "[FAIL] " << container_type << ": {";
    for (typename T::const_iterator it = container.begin();
         it != container.end(); ++it) {
      std::cout << " " << *it;
    }
    std::cout << " } Param: " << p << RESET << std::endl;
    return true;
  }
}

#endif
