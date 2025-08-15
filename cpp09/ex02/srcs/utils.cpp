#include "utils.hpp"
#include <cstdlib>
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
      return std::vector<unsigned>();
    }
  }
  return vec;
}
