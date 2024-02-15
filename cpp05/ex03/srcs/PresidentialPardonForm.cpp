#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target)
	:	AForm(name,
			PresidentialPardonForm::REQUIRED_GRADE_SIGN,
			PresidentialPardonForm::REQUIRED_GRADE_EXECUTE),
		target_(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form)
	:	AForm(form),
		target_(form.target_) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
	if (this != &form) {
		AForm::operator=(form);
		const_cast<std::string&>(this->target_) = form.target_;
	}
	return *this;
}

void	PresidentialPardonForm::Action(void) const {
	std::cout << "Informs that " << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm*	PresidentialPardonForm::Clone(std::string& name, std::string& target) const {
	return new PresidentialPardonForm(name, target);
}
