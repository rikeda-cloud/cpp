#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm",
            PresidentialPardonForm::REQUIRED_GRADE_SIGN,
            PresidentialPardonForm::REQUIRED_GRADE_EXEC),
      target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &form)
    : AForm(form), target_(form.target_) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
  if (this != &form) {
    AForm::operator=(form);
    const_cast<std::string &>(this->target_) = form.target_;
  }
  return *this;
}

void PresidentialPardonForm::action(void) const {
  std::cout << "Informs that " << target_
            << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
