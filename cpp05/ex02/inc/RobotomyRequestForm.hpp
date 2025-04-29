#ifndef CPP05_EX02_RobotomyRequestForm_H_
#define CPP05_EX02_RobotomyRequestForm_H_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(std::string);
  RobotomyRequestForm(const RobotomyRequestForm &);
  ~RobotomyRequestForm(void);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &);

private:
  static const size_t REQUIRED_GRADE_SIGN = 72;
  static const size_t REQUIRED_GRADE_EXEC = 45;

  const std::string target_;
  RobotomyRequestForm(void);
  void action(void) const;
};

#endif
