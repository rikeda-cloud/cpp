#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

void testTooHighGrade(void) {
  // INFO グレードが高すぎるケース
  std::cout << "=== testTooHighGrade ===" << std::endl;

  const size_t too_high_grade = Bureaucrat::GRADE_HIGH_LIMIT - 1;

  try {
    Bureaucrat b("ABC", too_high_grade);
    std::cerr << "[ERROR:testTooHighGrade]"
              << " No exceptions occurred." << std::endl;
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "[SUCCESS:testTooHighGrade]" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "[ERROR:testTooHighGrade]"
              << " An unexpected error has occurred." << std::endl;
  }
}

void testTooLowGrade(void) {
  // INFO グレードが低すぎるケース
  std::cout << "=== testTooLowGrade ===" << std::endl;

  const size_t too_low_grade = Bureaucrat::GRADE_LOW_LIMIT + 1;

  try {
    Bureaucrat b("ABC", too_low_grade);
    std::cerr << "[ERROR:testTooLowGrade]"
              << " No exceptions occurred." << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "[SUCCESS:testTooLowGrade]" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "[ERROR:testTooLowGrade]"
              << " An unexpected error has occurred." << std::endl;
  }
}

void testNormalGrade(void) {
  // INFO 正常値でBureaucratクラスをインスタンス化するケース
  std::cout << "=== testNormalGrade ===" << std::endl;

  try {
    Bureaucrat b1("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
    Bureaucrat b2("ABC", Bureaucrat::GRADE_LOW_LIMIT);
    std::cout << "[SUCCESS:testNormalGrade]" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "[ERROR:testNormalGrade]"
              << " An exception has occurred." << std::endl;
  }
}

void testIncrementGradeThrowException(void) {
  // INFO インクリメント時に最高グレードを超えるケース
  std::cout << "=== testIncrementGradeThrowException ===" << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);

  try {
    b.incrementGrade();
    std::cerr << "[ERROR:testIncrementGradeThrowException]"
              << " No exceptions occurred." << std::endl;
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "[SUCCESS:testIncrementGradeThrowException]" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "[ERROR:testIncrementGradeThrowException]"
              << " An unexpected error has occurred." << std::endl;
  }
}

void testDecrementGradeThrowException(void) {
  // INFO デクリメント時に最低グレードを下回るケース
  std::cout << "=== testDecrementGradeThrowException ===" << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_LOW_LIMIT);

  try {
    b.decrementGrade();
    std::cerr << "[ERROR:testDecrementGradeThrowException]"
              << " No exceptions occurred." << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "[SUCCESS:testDecrementGradeThrowException]" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "[ERROR:testDecrementGradeThrowException]"
              << " An unexpected error has occurred." << std::endl;
  }
}

void testIncrementGradeAndDecrementGrade(void) {
  // INFO インクリメント・デクリメントが正常に行えるケース
  std::cout << "=== testIncrementGradeAndDecrementGrade ===" << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);

  try {
    while (b.getGrade() < Bureaucrat::GRADE_LOW_LIMIT) {
      b.decrementGrade();
    }
    while (b.getGrade() < Bureaucrat::GRADE_HIGH_LIMIT) {
      b.incrementGrade();
    }
    std::cout << "[SUCCESS:testIncrementGradeAndDecrementGrade]" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "[ERROR:testIncrementGradeAndDecrementGrade]"
              << " An exception has occurred." << std::endl;
  }
}

void testOutputOperator(std::string name) {
  // INFO 出力演算子が予期する文字列になっているか
  Bureaucrat b(name, 42);
  std::string expect = name + ", bureaucrat grade 42.\n";

  std::ostringstream oss;
  oss << b;

  std::cout << "=== testOutputOperator (" << name << ") ===" << std::endl;

  if (oss.str() == expect) {
    std::cout << "[SUCCESS:testOutputOperator]" << std::endl;
  } else {
    std::cerr << "[ERROR:testOutputOperator]"
              << " Output is unexpected." << std::endl;
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

  return 0;
}
