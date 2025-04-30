#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void) {
  form_pairs_[0].name = "shrubbery creation";
  form_pairs_[0].makeFunc = &Intern::makeShrubberyCreationForm;
  form_pairs_[1].name = "robotomy request";
  form_pairs_[1].makeFunc = &Intern::makeRobotomyRequestForm;
  form_pairs_[2].name = "presidential pardon";
  form_pairs_[2].makeFunc = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern &intern) {
  for (size_t i = 0; i < NUM_OF_FORM_TYPES; i++) {
    form_pairs_[i].name = intern.form_pairs_[i].name;
    form_pairs_[i].makeFunc = intern.form_pairs_[i].makeFunc;
  }
}

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &intern) {
  if (this != &intern) {
    for (size_t i = 0; i < NUM_OF_FORM_TYPES; i++) {
      form_pairs_[i].name = intern.form_pairs_[i].name;
      form_pairs_[i].makeFunc = intern.form_pairs_[i].makeFunc;
    }
  }
  return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target) {
  for (size_t i = 0; i < NUM_OF_FORM_TYPES; i++) {
    if (form_pairs_[i].name == form_name) {
      std::cout << "Intern creates " << form_name << std::endl;
      return (this->*(form_pairs_[i].makeFunc))(target);
    }
  }
  std::cout << form_name << " not found" << std::endl;
  return NULL;
}

AForm *Intern::makeShrubberyCreationForm(std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string &target) {
  return new PresidentialPardonForm(target);
}
