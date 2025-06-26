#include "Span.hpp"
#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void print_ok_(void) { std::cout << GREEN << "[OK]" << RESET << std::endl; }

void print_fail_(unsigned expect, unsigned actual) {
  std::cout << RED << "[FAIL] expect: " << expect << " actual: " << actual
            << RESET << std::endl;
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

  print_ok_();
  return false;
}

bool test_out_of_range(void) {
  const unsigned int N = 3;
  Span sp(N);

  unsigned int i = 0;
  for (; i < N; ++i) {
    sp.addNumber(i);
  }

  try {
    sp.addNumber(i);
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::length_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_throw_exception_shrtest(void) {
  Span sp(5);

  sp.addNumber(1);

  try {
    sp.shortestSpan();
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::domain_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_throw_exception_longest(void) {
  Span sp(5);

  try {
    sp.longestSpan();
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::domain_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_large_diff(void) {
  Span sp(5);
  const unsigned expect_diff = std::numeric_limits<unsigned int>::max();

  sp.addNumber(0);
  sp.addNumber(std::numeric_limits<int>::min());
  sp.addNumber(std::numeric_limits<int>::max());

  unsigned actual_diff = sp.longestSpan();

  if (expect_diff == actual_diff) {
    print_ok_();
    return false;
  }

  print_fail_(expect_diff, actual_diff);
  return true;
}

bool test_copy_operator(void) {
  Span sp1(3);
  sp1.addNumber(1);
  sp1.addNumber(2);

  Span sp2(sp1);
  sp1.addNumber(3);
  sp2.addNumber(3);

  try {
    sp2.addNumber(4);
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::length_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_assignment_operator(void) {
  Span sp1(3);
  sp1.addNumber(1);
  sp1.addNumber(2);

  Span sp2 = sp1;
  sp1.addNumber(3);
  sp2.addNumber(3);

  try {
    sp2.addNumber(4);
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::length_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_diff_zero(void) {
  Span sp(2);
  const unsigned expect_shortest = 0;
  const unsigned expect_longest = 0;

  sp.addNumber(0);
  sp.addNumber(0);

  if (expect_shortest != sp.shortestSpan()) {
    print_fail_(expect_shortest, sp.shortestSpan());
    return true;
  }
  if (expect_longest != sp.longestSpan()) {
    print_fail_(expect_longest, sp.longestSpan());
    return true;
  }

  print_ok_();
  return false;
}

bool test_add_numbers(void) {
  Span sp(5);
  int arr[] = {1, 2, 3, 4, 5};
  std::vector<int> vec;
  vec.insert(vec.begin(), arr, arr + 5);

  sp.addNumbers(vec.begin(), vec.end());

  try {
    sp.addNumber(6);
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::length_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_add_numbers_throw_exception(void) {
  Span sp(5);
  int arr[] = {1, 2, 3, 4, 5, 6};
  std::vector<int> vec;
  vec.insert(vec.begin(), arr, arr + 6);

  try {
    sp.addNumbers(vec.begin(), vec.end());
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::length_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_n_is_zero(void) {
  Span sp(0);

  try {
    sp.addNumber(1);
    std::cout << RED << "No exception occurred." << RESET << std::endl;
  } catch (std::length_error &e) {
    print_ok_();
    return false;
  } catch (std::exception &e) {
    std::cout << RED << "Unexpected exceptions occured." << RESET << std::endl;
  }
  return true;
}

bool test_n_is_10000(void) {
  const unsigned int n = 10000;
  const unsigned int expect_shortest = 1;
  const unsigned int expect_longest = n - 1;
  Span sp(n);

  for (unsigned i = 0; i < n; ++i) {
    sp.addNumber(i);
  }

  if (expect_shortest != sp.shortestSpan()) {
    print_fail_(expect_shortest, sp.shortestSpan());
    return true;
  }
  if (expect_longest != sp.longestSpan()) {
    print_fail_(expect_longest, sp.longestSpan());
    return true;
  }
  return false;
}

int main(void) {
  int fail_count =
      test_sample_main() + test_out_of_range() +
      test_throw_exception_shrtest() + test_throw_exception_longest() +
      test_large_diff() + test_copy_operator() + test_assignment_operator() +
      test_diff_zero() + test_add_numbers() +
      test_add_numbers_throw_exception() + test_n_is_zero() + test_n_is_10000();
  return fail_count != 0;
}
