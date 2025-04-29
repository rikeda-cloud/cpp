#ifndef CPP05_EX03_Intern_H_
#define CPP05_EX03_Intern_H_

#include "AForm.hpp"
#include <string>

class Intern {
public:
  Intern(void);
  Intern(const Intern &);
  ~Intern(void);
  Intern &operator=(const Intern &);

  AForm *makeForm(const std::string, const std::string);

private:
  class FormPair {
  public:
    const char *name;
    AForm *(Intern::*makeFunc)(std::string &);
  };

  static const size_t NUM_OF_FORM_TYPES = 3;
  FormPair form_pairs_[NUM_OF_FORM_TYPES];

  AForm *makeRobotomyRequestForm(std::string &);
  AForm *makeShrubberyCreationForm(std::string &);
  AForm *makePresidentialPardonForm(std::string &);
};

#endif
