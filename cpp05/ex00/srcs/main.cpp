#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

static const char *RED = "\033[41m";
static const char *GREEN = "\033[42m";
static const char *BLUE = "\e[46m";
static const char *RESET = "\033[0m";

void testTooHighGrade(void) {
  // INFO グレードが高すぎるケース
  std::cout << BLUE << "=== testTooHighGrade ===" << RESET << std::endl;

  const size_t too_high_grade = Bureaucrat::GRADE_HIGH_LIMIT - 1;

  try {
    Bureaucrat b("ABC", too_high_grade);
    std::cerr << RED << "[ERROR:testTooHighGrade]" << " No exceptions occurred."
              << RESET << std::endl;
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << GREEN << "[SUCCESS:testTooHighGrade]" << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cerr << RED << "[ERROR:testTooHighGrade]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }
}

void testTooLowGrade(void) {
  // INFO グレードが低すぎるケース
  std::cout << BLUE << "=== testTooLowGrade ===" << RESET << std::endl;

  const size_t too_low_grade = Bureaucrat::GRADE_LOW_LIMIT + 1;

  try {
    Bureaucrat b("ABC", too_low_grade);
    std::cerr << RED << "[ERROR:testTooLowGrade]" << " No exceptions occurred."
              << RESET << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << GREEN << "[SUCCESS:testTooLowGrade]" << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cerr << RED << "[ERROR:testTooLowGrade]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }
}

void testNormalGrade(void) {
  // INFO 正常値でBureaucratクラスをインスタンス化するケース
  std::cout << BLUE << "=== testNormalGrade ===" << RESET << std::endl;

  try {
    Bureaucrat b1("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
    Bureaucrat b2("ABC", Bureaucrat::GRADE_LOW_LIMIT);
    std::cout << GREEN << "[SUCCESS:testNormalGrade]" << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cerr << RED << "[ERROR:testNormalGrade]"
              << " An exception has occurred." << RESET << std::endl;
  }
}

void testIncrementGradeThrowException(void) {
  // INFO インクリメント時に最高グレードを超えるケース
  std::cout << BLUE << "=== testIncrementGradeThrowException ===" << RESET
            << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);

  try {
    b.incrementGrade();
    std::cerr << RED << "[ERROR:testIncrementGradeThrowException]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << GREEN << "[SUCCESS:testIncrementGradeThrowException]" << RESET
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << RED << "[ERROR:testIncrementGradeThrowException]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }
}

void testDecrementGradeThrowException(void) {
  // INFO デクリメント時に最低グレードを下回るケース
  std::cout << BLUE << "=== testDecrementGradeThrowException ===" << RESET
            << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_LOW_LIMIT);

  try {
    b.decrementGrade();
    std::cerr << RED << "[ERROR:testDecrementGradeThrowException]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << GREEN << "[SUCCESS:testDecrementGradeThrowException]" << RESET
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << RED << "[ERROR:testDecrementGradeThrowException]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }
}

void testIncrementGradeAndDecrementGrade(void) {
  // INFO インクリメント・デクリメントが正常に行えるケース
  std::cout << BLUE << "=== testIncrementGradeAndDecrementGrade ===" << RESET
            << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);

  try {
    while (b.getGrade() < Bureaucrat::GRADE_LOW_LIMIT) {
      b.decrementGrade();
    }
    while (b.getGrade() < Bureaucrat::GRADE_HIGH_LIMIT) {
      b.incrementGrade();
    }
    std::cout << GREEN << "[SUCCESS:testIncrementGradeAndDecrementGrade]"
              << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cerr << RED << "[ERROR:testIncrementGradeAndDecrementGrade]"
              << " An exception has occurred." << RESET << std::endl;
  }
}

void testOutputOperator(std::string name) {
  // INFO 出力演算子が予期する文字列になっているか
  std::cout << BLUE << "=== testOutputOperator (" << name << ") ===" << RESET
            << std::endl;

  Bureaucrat b(name, 42);
  std::string expect = name + ", bureaucrat grade 42.\n";

  std::ostringstream oss;
  oss << b;

  if (oss.str() == expect) {
    std::cout << GREEN << "[SUCCESS:testOutputOperator]" << RESET << std::endl;
  } else {
    std::cerr << RED << "[ERROR:testOutputOperator]" << " Output is unexpected."
              << RESET << std::endl;
  }
}

void testCopyOperator(void) {
  // INFO コピー演算子が機能しているか
  std::cout << BLUE << "=== testCopyOperator ===" << RESET << std::endl;

  Bureaucrat b("ABC", 42);
  Bureaucrat copy_b(b);

  std::ostringstream output_b;
  output_b << b;
  std::ostringstream output_copy_b;
  output_copy_b << copy_b;

  if (b.getName() == copy_b.getName() && b.getGrade() == copy_b.getGrade() &&
      output_b.str() == output_copy_b.str()) {
    std::cout << GREEN << "[SUCCESS:testCopyOperator]" << RESET << std::endl;
  } else {
    std::cerr << RED << "[ERROR:testCopyOperator]"
              << " Copy bureaucrat is unexpected." << RESET << std::endl;
  }
}

void testAssignmentOperator(void) {
  // INFO 代入演算子が機能しているか
  std::cout << BLUE << "=== testAssignmentOperator ===" << RESET << std::endl;

  Bureaucrat b("ABC", 42);
  Bureaucrat assignment_b("DEF", 1);
  assignment_b = b;

  std::ostringstream output_b;
  output_b << b;
  std::ostringstream output_assignment_b;
  output_assignment_b << assignment_b;

  if (b.getName() == assignment_b.getName() &&
      b.getGrade() == assignment_b.getGrade() &&
      output_b.str() == output_assignment_b.str()) {
    std::cout << GREEN << "[SUCCESS:testAssignmentOperator]" << RESET
              << std::endl;
  } else {
    std::cerr << RED << "[ERROR:testAssignmentOperator]"
              << " Copy bureaucrat is unexpected." << RESET << std::endl;
  }
}

int main(void) {
  testTooHighGrade();
  testTooLowGrade();
  testNormalGrade();
  testIncrementGradeThrowException();
  testDecrementGradeThrowException();
  testIncrementGradeAndDecrementGrade();
  testOutputOperator("ABC");
  testOutputOperator("");
  testCopyOperator();
  testAssignmentOperator();

  return 0;
}
