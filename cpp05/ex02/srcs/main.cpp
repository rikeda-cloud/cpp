#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <sstream>
#include <string>

// static const char *RED = "\033[41m";
// static const char *GREEN = "\033[42m";
// static const char *BLUE = "\e[46m";
// static const char *RESET = "\033[0m";

void executePresidentialPardonForm(void) {
  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
  PresidentialPardonForm form("target");
  b.signForm(form);
  b.executeForm(form);
}

void executeRobotomyRequestForm(void) {
  Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
  RobotomyRequestForm form("target");
  b.signForm(form);

  // INFO RobotomyRequestFormは50%の確立で成功・失敗するので複数回実行
  for (size_t i = 0; i < 10; i++) {
    b.executeForm(form);
  }
}

void executeShrubberyCreationForm(void) {
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

int main(void) {
  executePresidentialPardonForm();
  executeRobotomyRequestForm();
  executeShrubberyCreationForm();

  return 0;
}
