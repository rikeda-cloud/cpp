#include "test.hpp"

int main(void) {
  int fail_count = test_data_base() + test_parser();
  return fail_count;
}
