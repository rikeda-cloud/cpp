#ifndef CPP05_EX03_PresidentialPardonForm_H_
#define CPP05_EX03_PresidentialPardonForm_H_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  static const size_t REQUIRED_GRADE_SIGN = 25;
  static const size_t REQUIRED_GRADE_EXEC = 5;

  PresidentialPardonForm(const std::string &);
  PresidentialPardonForm(const PresidentialPardonForm &);
  ~PresidentialPardonForm(void);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &);

private:
  const std::string target_;
  PresidentialPardonForm(void);
  void action(void) const;
};

#endif
