#include "RPN.hpp"
#include <exception>
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define EXPECTED_EXCEPTION -99999

bool exec_test_evaluate(const std::string &s, int expect_result) {
  try {
    int actual_result = RPN::evaluate(s);
    if (expect_result == EXPECTED_EXCEPTION) {
      std::cout << RED << "[FAIL] not raised exception" << RESET << std::endl;
      return true;
    }
    if (expect_result != actual_result) {
      std::cout << RED << "[FAIL] "
                << "  Expected: \"" << expect_result << "\"" << std::endl
                << "  Actual  : \"" << actual_result << "\"" << RESET
                << std::endl;
      return true;
    }
  } catch (const std::exception &e) {
    if (expect_result != EXPECTED_EXCEPTION) {
      std::cout << RED << "[FAIL] raised exception: " << e.what() << RESET
                << std::endl;
      return true;
    }
  }
  std::cout << GREEN << "[OK]" << RESET << std::endl;
  return false;
}

int main(void) {
  int fail_count = exec_test_evaluate("8 9 * 9 - 9 - 9 - 4 - 1 +", 42) +
                   exec_test_evaluate("7 7 * 7 -", 42) +
                   exec_test_evaluate("1 2 * 2 / 2 * 2 4 - +", 0) +
                   exec_test_evaluate("1 2 + 3 * 4 /", 2) +
                   exec_test_evaluate("9", 9) +
                   exec_test_evaluate("5 1 2 + 4 * + 3 -", 14) +
                   exec_test_evaluate("0 9 - 3 /", -3) +
                   exec_test_evaluate("   1   1  +   ", 2) +
                   exec_test_evaluate("1	1	+", 2) +
                   exec_test_evaluate("(1 + 1)", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1 0 /", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("10 2 +", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("+", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1 + 2", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("", EXPECTED_EXCEPTION) +
                   exec_test_evaluate(" ", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1 2 + -", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1 2 + a", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1.1 2 +", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1 2 3 ++", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1 2 3 +", EXPECTED_EXCEPTION) +
                   exec_test_evaluate("1 -1 +", EXPECTED_EXCEPTION);

  return fail_count != 0;
}
