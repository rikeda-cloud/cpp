#include "utils.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>

unsigned jacobsthal(unsigned n) {
  if (n <= 1)
    return n;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<unsigned> argvToUintVec(int argc, const char **argv) {
  std::vector<unsigned> vec;

  char *end;
  for (int i = 1; i < argc; ++i) {
    unsigned long num = std::strtoul(argv[i], &end, 10);
    if (*end == '\0' && num <= std::numeric_limits<unsigned int>::max()) {
      vec.push_back(num);
    } else {
      // INFO コマンドライン引数が不正な値なら空のVectorを返す
      return std::vector<unsigned>();
    }
  }
  return vec;
}

void printTimeInfo(std::size_t num_of_elements,
                   const std::string &container_type, clock_t start,
                   clock_t end) {
  double t = end - start;
  double sec = t / CLOCKS_PER_SEC;
  double usec = sec * 1000000;

  std::cout << "Time to process a range of " << num_of_elements
            << " elements with std::" << container_type << " : " << usec
            << " us" << std::endl;
}
