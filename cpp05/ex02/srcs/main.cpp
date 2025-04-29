#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <sstream>
#include <string>

static const char *RED = "\033[41m";
static const char *GREEN = "\033[42m";
static const char *BLUE = "\e[46m";
static const char *RESET = "\033[0m";

void executePresidentialPardonForm(void) {
  std::cout << BLUE << "=== executePresidentialPardonForm ===" << RESET
            << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
  PresidentialPardonForm form("target");
  b.signForm(form);
  b.executeForm(form);
}

void executeRobotomyRequestForm(void) {
  std::cout << BLUE << "=== executeRobotomyRequestForm ===" << RESET
            << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
  RobotomyRequestForm form("target");
  b.signForm(form);

  // INFO RobotomyRequestFormは50%の確立で成功・失敗するので複数回実行
  for (size_t i = 0; i < 10; i++) {
    b.executeForm(form);
  }
}

void executeShrubberyCreationForm(void) {
  std::cout << BLUE << "=== executeShrubberyCreationForm ===" << RESET
            << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);

  // INFO ShrubberyCreationFormで複数のファイルを作成
  for (size_t i = 0; i < 10; i++) {
    std::ostringstream oss;
    oss << "target" << i + 1;
    ShrubberyCreationForm form(oss.str());
    b.signForm(form);
    b.executeForm(form);
  }
}

void testExecuteNoSignForm(void) {
  // INFO 署名のないFormを実行
  std::cout << BLUE << "=== testExecuteNoSignForm ===" << RESET << std::endl;

  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
  PresidentialPardonForm form("target");
  std::string expect = "ABC couldn't execute PresidentialPardonForm because "
                       "form is not signed!\n";

  std::string actual = b.executeForm(form);

  if (expect == actual) {
    std::cout << GREEN << "[SUCCESS:testExecuteNoSignForm]" << RESET
              << std::endl;
  } else {
    std::cout << RED << "[ERROR:testExecuteNoSignForm]"
              << " Output is unexpected." << RESET << std::endl;
  }
}

int main(void) {
  executePresidentialPardonForm();
  executeRobotomyRequestForm();
  executeShrubberyCreationForm();
  testExecuteNoSignForm();

  return 0;
}
