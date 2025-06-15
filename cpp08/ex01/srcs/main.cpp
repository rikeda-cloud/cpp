#include "Span.hpp"
#include <iostream>
#include <vector>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void print_fail_(unsigned expect, unsigned actual) {
  std::cout << RED << "[FAIL] expect: " << expect << " actual: " << actual
            << std::endl;
}

bool test_sample_main(void) {
  const unsigned int expect_shortest = 2;
  const unsigned int expect_longest = 14;

  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  if (expect_shortest != sp.shortestSpan()) {
    print_fail_(expect_shortest, sp.shortestSpan());
    return true;
  }
  if (expect_longest != sp.longestSpan()) {
    print_fail_(expect_longest, sp.longestSpan());
    return true;
  }

  std::cout << GREEN << "[OK]" << std::endl;
  return false;
}

int main(void) {
  int fail_count = test_sample_main();
  return fail_count != 0;
}
