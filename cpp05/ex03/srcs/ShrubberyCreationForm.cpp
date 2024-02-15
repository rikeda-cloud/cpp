#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target)
	:	AForm(name,
			ShrubberyCreationForm::REQUIRED_GRADE_SIGN,
			ShrubberyCreationForm::REQUIRED_GRADE_EXECUTE),
		target_(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
	:	AForm(form),
		target_(form.target_) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	if (this != &form) {
		AForm::operator=(form);
		const_cast<std::string&>(this->target_) = form.target_;
	}
	return *this;
}

void	ShrubberyCreationForm::Action(void) const {
	std::ofstream	s;
	s.open(target_ + std::string("_shrubbery"));
	if (s.fail())
		throw FileException();
	std::string	ascii_tree = 
		"     *      \n"
		"    /.\\    \n"
		"   /o..\\   \n"
		"   /..o\\   \n"
		"  /.o..o\\  \n"
		"  /...o.\\  \n"
		" /..o....\\ \n"
		" ^^^[_]^^^ \n";

	s << ascii_tree << std::endl;
	if (s.is_open()) {
		s.close();
		if (s.fail())
			throw FileException();
	}
}

AForm*	ShrubberyCreationForm::Clone(std::string& name, std::string& target) const {
	return new ShrubberyCreationForm(name, target);
}
