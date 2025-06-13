#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", RobotomyRequestForm::REQUIRED_GRADE_SIGN,
            RobotomyRequestForm::REQUIRED_GRADE_EXEC),
      target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : AForm(form), target_(form.target_) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
  if (this != &form) {
    AForm::operator=(form);
    const_cast<std::string &>(this->target_) = form.target_;
  }
  return *this;
}

void RobotomyRequestForm::action(void) const {
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(0));
    seeded = true;
  }

  if (std::rand() % 2 == 0) {
    std::cout << "[SUCCESS] " << target_ << " has become a robot" << std::endl;
  } else {
    std::cout << "[ERROR] " << target_ << " couldn't become a robot"
              << std::endl;
  }
}
