#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <sstream>

static const char *RED = "\033[41m";
static const char *GREEN = "\033[42m";
static const char *BLUE = "\e[46m";
static const char *RESET = "\033[0m";

void testTooHighGrade(void) {
  // INFO グレードが高すぎるケース
  std::cout << BLUE << "=== testTooHighGrade ===" << RESET << std::endl;

  const size_t too_high_grade = Form::GRADE_HIGH_LIMIT - 1;

  // INFO gradeToSignのグレードが高すぎるケース
  try {
    Form f("ABC", too_high_grade, 42);
    std::cout << RED << "[ERROR:testTooHighGrade(gradeToSign)]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const Form::GradeTooHighException &e) {
    std::cout << GREEN << "[SUCCESS:testTooHighGrade(gradeToSign)]" << RESET
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[ERROR:testTooHighGrade(gradeToSign)]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }

  // INFO gradeToExecuteのグレードが高すぎるケース
  try {
    Form f("ABC", 42, too_high_grade);
    std::cout << RED << "[ERROR:testTooHighGrade(gradeToExecute)]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const Form::GradeTooHighException &e) {
    std::cout << GREEN << "[SUCCESS:testTooHighGrade(gradeToExecute)]" << RESET
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[ERROR:testTooHighGrade(gradeToExecute)]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }
}

void testTooLowGrade(void) {
  // INFO グレードが低すぎるケース
  std::cout << BLUE << "=== testTooLowGrade ===" << RESET << std::endl;

  const size_t too_low_grade = Form::GRADE_LOW_LIMIT + 1;

  // INFO gradeToSignが低すぎるケース
  try {
    Form f("ABC", too_low_grade, 42);
    std::cout << RED << "[ERROR:testTooLowGrade(gradeToSign)]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << GREEN << "[SUCCESS:testTooLowGrade(gradeToSign)]" << RESET
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[ERROR:testTooLowGrade(gradeToSign)]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }

  // INFO gradeToExecuteが低すぎるケース
  try {
    Form f("ABC", 42, too_low_grade);
    std::cout << RED << "[ERROR:testTooLowGrade(gradeToExecute)]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << GREEN << "[SUCCESS:testTooLowGrade(gradeToExecute)]" << RESET
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[ERROR:testTooLowGrade(gradeToExecute)]"
              << " An unexpected error has occurred." << RESET << std::endl;
  }
}

void testNormalGrade(void) {
  // INFO 正常値でFormクラスをインスタンス化するケース
  std::cout << BLUE << "=== testNormalGrade ===" << RESET << std::endl;

  try {
    Form f1("ABC", Form::GRADE_HIGH_LIMIT, Form::GRADE_LOW_LIMIT);
    Form f2("ABC", Form::GRADE_LOW_LIMIT, Form::GRADE_HIGH_LIMIT);
    std::cout << GREEN << "[SUCCESS:testNormalGrade]" << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[ERROR:testNormalGrade]"
              << " An exception has occurred." << RESET << std::endl;
  }
}

void testOutputOperator(std::string name) {
  // INFO 出力演算子が予期する文字列になっているか
  std::cout << BLUE << "=== testOutputOperator (" << name << ") ===" << RESET
            << std::endl;

  Form f(name, 42, 42);
  std::string expect = "Name: " + name + "\n" + "Signed: " + "False" + "\n" +
                       "Grade to sign: " + "42" + "\n" +
                       "Grade to execute: " + "42" + "\n";

  std::ostringstream oss;
  oss << f;

  if (oss.str() == expect) {
    std::cout << GREEN << "[SUCCESS:testOutputOperator]" << RESET << std::endl;
  } else {
    std::cout << RED << "[ERROR:testOutputOperator]"
              << " Output is unexpected." << RESET << std::endl;
  }
}

void testCopyOperator(void) {
  // INFO コピー演算子が機能しているか
  std::cout << BLUE << "=== testCopyOperator ===" << RESET << std::endl;

  Form f("ABC", 42, 42);
  Form copy_f(f);

  std::ostringstream output_f;
  output_f << f;
  std::ostringstream output_copy_f;
  output_copy_f << copy_f;

  if (f.getName() == copy_f.getName() &&
      f.getGradeToSign() == copy_f.getGradeToSign() &&
      f.getGradeToExecute() == copy_f.getGradeToExecute() &&
      output_f.str() == output_copy_f.str()) {
    std::cout << GREEN << "[SUCCESS:testCopyOperator]" << RESET << std::endl;
  } else {
    std::cout << RED << "[ERROR:testCopyOperator]"
              << " Copy bureaucrat is unexpected." << RESET << std::endl;
  }
}

void testAssignmentOperator(void) {
  // INFO 代入演算子が機能しているか
  std::cout << BLUE << "=== testAssignmentOperator ===" << RESET << std::endl;

  Form f("ABC", 42, 42);
  Form assignment_f("DEF", 100, 100);
  assignment_f = f;

  std::ostringstream output_f;
  output_f << f;
  std::ostringstream output_assignment_f;
  output_assignment_f << assignment_f;

  if (f.getName() == assignment_f.getName() &&
      f.getGradeToSign() == assignment_f.getGradeToSign() &&
      f.getGradeToExecute() == assignment_f.getGradeToExecute() &&
      output_f.str() == output_assignment_f.str()) {
    std::cout << GREEN << "[SUCCESS:testAssignmentOperator]" << RESET
              << std::endl;
  } else {
    std::cout << RED << "[ERROR:testAssignmentOperator]"
              << " Copy bureaucrat is unexpected." << RESET << std::endl;
  }
}

void testBeSigned(void) {
  // INFO besigned関数が機能するか
  std::cout << BLUE << "=== testBeSigned ===" << RESET << std::endl;

  Form f("ABC", 1, 1); // INFO 署名にGrade1のBureaucratが必要
  Bureaucrat grade2_bureaucrat("Grade2", 2);
  Bureaucrat grade1_bureaucrat("Grade1", 1);

  // INFO Bureaucratのグレードが低いと例外が発生
  try {
    f.beSigned(grade2_bureaucrat);
    std::cout << RED << "[ERROR:testBeSigned(1)]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cout << GREEN << "[SUCCESS:testBeSigned(1)]" << RESET << std::endl;
  }

  // INFO Bureaucratのグレードが高いと署名可能
  try {
    f.beSigned(grade1_bureaucrat);
    if (f.getIsSigned() == false) {
      throw std::exception();
    }
    std::cout << GREEN << "[SUCCESS:testBeSigned(2)]" << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[ERROR:testBeSigned(2)]"
              << " An exception has occurred." << RESET << std::endl;
  }

  // INFO 署名の有無に関わらずBureaucratのグレードが低いと例外が発生
  try {
    f.beSigned(grade2_bureaucrat);
    std::cout << RED << "[ERROR:testBeSigned(3)]"
              << " No exceptions occurred." << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cout << GREEN << "[SUCCESS:testBeSigned(3)]" << RESET << std::endl;
  }

  // INFO 署名の有無に関わらずBureaucratのグレードが高いと署名可能
  try {
    f.beSigned(grade1_bureaucrat);
    std::cout << GREEN << "[SUCCESS:testBeSigned(4)]" << RESET << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[ERROR:testBeSigned(4)]"
              << " An exception has occurred." << RESET << std::endl;
  }
}

void testSignForm(void) {
  // INFO signForm関数が機能するか
  std::cout << BLUE << "=== testSignForm ===" << RESET << std::endl;

  Form f("ABC", 1, 1);
  Bureaucrat grade2_bureaucrat("Grade2", 2);
  Bureaucrat grade1_bureaucrat("Grade1", 1);

  // INFO グレードが低すぎるため署名は失敗する
  std::string expect_signForm_by_grade2 =
      "Grade2 couldn't sign ABC because Grade too low!.\n";
  if (expect_signForm_by_grade2 == grade2_bureaucrat.signForm(f)) {
    std::cout << GREEN << "[SUCCESS:testSignForm(1)]" << RESET << std::endl;
  } else {
    std::cout << RED << "[ERROR:testSignForm(1)]"
              << " Output is unexpected." << RESET << std::endl;
  }

  // INFO グレードが高いので署名に成功
  std::string expect_signForm_by_grade1 = "Grade1 signed ABC\n";
  if (expect_signForm_by_grade1 == grade1_bureaucrat.signForm(f)) {
    std::cout << GREEN << "[SUCCESS:testSignForm(2)]" << RESET << std::endl;
  } else {
    std::cout << RED << "[ERROR:testSignForm(2)]"
              << " Output is unexpected." << RESET << std::endl;
  }
}

int main(void) {
  testTooHighGrade();
  testTooLowGrade();
  testNormalGrade();
  testOutputOperator("ABC");
  testOutputOperator("");
  testCopyOperator();
  testAssignmentOperator();
  testBeSigned();
  testSignForm();

  return 0;
}
