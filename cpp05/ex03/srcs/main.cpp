#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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

void testMakeShrubberyCreationForm(void) {
  std::cout << BLUE << "=== testMakeShrubberyCreationForm ===" << RESET
            << std::endl;

  Intern intern;
  AForm *rrf;
  rrf = intern.makeForm("shrubbery creation", "Bender");

  if (rrf) {
    Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    std::cout << GREEN << "[SUCCESS:testMakeShrubberyCreationForm]" << RESET
              << std::endl;
    delete rrf;
  } else {
    std::cout << RED << "[ERROR:testMakeShrubberyCreationForm]"
              << " Form could not be created." << RESET << std::endl;
  }
}

void testMakeRobotomyRequestForm(void) {
  std::cout << BLUE << "=== testMakeRobotomyRequestForm ===" << RESET
            << std::endl;

  Intern intern;
  AForm *rrf;
  rrf = intern.makeForm("robotomy request", "Bender");

  if (rrf) {
    Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    std::cout << GREEN << "[SUCCESS:testMakeRobotomyRequestForm]" << RESET
              << std::endl;
    delete rrf;
  } else {
    std::cout << RED << "[ERROR:testMakeRobotomyRequestForm]"
              << " Form could not be created." << RESET << std::endl;
  }
}

void testMakePresidentialPardonForm(void) {
  std::cout << BLUE << "=== testMakePresidentialPardonForm ===" << RESET
            << std::endl;

  Intern intern;
  AForm *rrf;
  rrf = intern.makeForm("presidential pardon", "Bender");

  if (rrf) {
    Bureaucrat b("ABC", Bureaucrat::GRADE_HIGH_LIMIT);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    std::cout << GREEN << "[SUCCESS:testMakePresidentialPardonForm]" << RESET
              << std::endl;
    delete rrf;
  } else {
    std::cout << RED << "[ERROR:testMakePresidentialPardonForm]"
              << " Form could not be created." << RESET << std::endl;
  }
}

void testMakeNotExistForm(void) {
  std::cout << BLUE << "=== testMakeNotExistForm ===" << RESET << std::endl;

  Intern intern;
  AForm *rrf;
  rrf = intern.makeForm("NotExistForm", "Bender");

  if (rrf) {
    std::cout << RED << "[ERROR:testMakeNotExistForm]"
              << " Form should not be able to be created" << RESET << std::endl;
    delete rrf;
  } else {
    std::cout << GREEN << "[SUCCESS:testMakeNotExistForm]" << RESET
              << std::endl;
  }
}

int main(void) {
  testMakeShrubberyCreationForm();
  testMakeRobotomyRequestForm();
  testMakePresidentialPardonForm();
  testMakeNotExistForm();

  return 0;
}
