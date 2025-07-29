#ifndef CPP05_EX02_ShrubberyCreationForm_H_
#define CPP05_EX02_ShrubberyCreationForm_H_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  static const size_t REQUIRED_GRADE_SIGN = 145;
  static const size_t REQUIRED_GRADE_EXEC = 137;

  ShrubberyCreationForm(std::string);
  ~ShrubberyCreationForm(void);
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

private:
  const std::string target_;
  ShrubberyCreationForm(void);
  void action(void) const;
};

#endif
