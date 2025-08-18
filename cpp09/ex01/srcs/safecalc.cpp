#include <limits>
#include <stdexcept>

int safe_add(int v1, int v2) {
  if (v2 > 0 && v1 > std::numeric_limits<int>::max() - v2) {
    throw std::runtime_error("[ERROR] safe_add: Overflow");
  }
  if (v2 < 0 && v1 < std::numeric_limits<int>::min() - v2) {
    throw std::runtime_error("[ERROR] safe_add: Underflow");
  }
  return v1 + v2;
}

int safe_diff(int v1, int v2) {
  if (v2 < 0 && v1 > std::numeric_limits<int>::max() + v2) {
    throw std::runtime_error("[ERROR] safe_diff: Overflow");
  }
  if (v2 > 0 && v1 < std::numeric_limits<int>::min() + v2) {
    throw std::runtime_error("[ERROR] safe_diff: Underflow");
  }
  return v1 - v2;
}

int safe_div(int v1, int v2) {
  if (v2 == 0) {
    throw std::runtime_error("[ERROR] safe_div: 0 div");
  }

  long long llv1 = v1;
  long long llv2 = v2;
  long long result = llv1 / llv2;

  if (result > std::numeric_limits<int>::max()) {
    throw std::runtime_error("[ERROR] safe_div: Overflow");
  }
  if (result < std::numeric_limits<int>::min()) {
    throw std::runtime_error("[ERROR] safe_div: Underflow");
  }
  return v1 / v2;
}

int safe_mul(int v1, int v2) {
  long long llv1 = v1;
  long long llv2 = v2;
  long long result = llv1 * llv2;

  if (result > std::numeric_limits<int>::max()) {
    throw std::runtime_error("[ERROR] safe_mul: Overflow");
  }
  if (result < std::numeric_limits<int>::min()) {
    throw std::runtime_error("[ERROR] safe_mul: Underflow");
  }
  return v1 * v2;
}
