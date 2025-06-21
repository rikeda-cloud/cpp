#include "safecalc.hpp"
#include <exception>
#include <limits>

int safe_add(int v1, int v2) {
  if (v2 > 0 && v1 > std::numeric_limits<int>::max() - v2) {
    throw std::exception();
  }
  if (v2 < 0 && v1 < std::numeric_limits<int>::min() - v2) {
    throw std::exception();
  }
  return v1 + v2;
}

int safe_diff(int v1, int v2) {
  if (v2 < 0 && v1 > std::numeric_limits<int>::max() + v2) {
    throw std::exception();
  }
  if (v2 > 0 && v1 < std::numeric_limits<int>::min() + v2) {
    throw std::exception();
  }
  return v1 - v2;
}

int safe_div(int v1, int v2) {
  if (v2 == 0) {
    // Division by zero is not allowed
    throw std::exception();
  }
  return v1 / v2;
}

int safe_mul(int v1, int v2) { return v1 * v2; }
