#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target)
	:	AForm(name,
			RobotomyRequestForm::REQUIRED_GRADE_SIGN,
			RobotomyRequestForm::REQUIRED_GRADE_EXECUTE),
		target_(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
	:	AForm(form),
		target_(form.target_) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
	if (this != &form) {
		AForm::operator=(form);
		const_cast<std::string&>(this->target_) = form.target_;
	}
	return *this;
}

void	RobotomyRequestForm::Action(void) const {
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << "[SUCCESS] " << target_ << "has become a robot";
	else
		std::cout << "[ERROR]  " << target_ << "couldn't become a robot";
}

AForm*	RobotomyRequestForm::Clone(std::string& name, std::string& target) const {
	return new RobotomyRequestForm(name, target);
}
