#ifndef CPP09_EX02_utils_H_
#define CPP09_EX02_utils_H_

#include "PairPointer.hpp"
#include <cstddef>
#include <ctime>
#include <iostream>

unsigned jacobsthal(unsigned);
std::vector<unsigned> argvToUintVec(int argc, const char **argv);

template <typename T>
void printContainer(const std::string message, const T &container) {
  std::cout << message;
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    std::cout << *it;
    if (it + 1 != container.end())
      std::cout << " ";
  }
  std::cout << std::endl;
}

void printTimeInfo(std::size_t, const std::string &, clock_t, clock_t);

#endif
