#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern(void) {
	forms_[0] = new ShrubberyCreationForm("", "");
	forms_[1] = new PresidentialPardonForm("", "");
	forms_[2] = new RobotomyRequestForm("", "");
	forms_name_[0] = "shrubbery creation";
	forms_name_[1] = "presidential pardon";
	forms_name_[2] = "robotomy request";
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& intern) {
	*this->forms_[0] = *intern.forms_[0];
	*this->forms_[1] = *intern.forms_[1];
	*this->forms_[2] = *intern.forms_[2];
	this->forms_name_[0] = intern.forms_name_[0];
	this->forms_name_[1] = intern.forms_name_[1];
	this->forms_name_[2] = intern.forms_name_[2];
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void) {
	if (forms_[0])
		delete forms_[0];
	if (forms_[1])
		delete forms_[1];
	if (forms_[2])
		delete forms_[2];
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& intern) {
	if (this != &intern) {
		*this->forms_[0] = *intern.forms_[0];
		*this->forms_[1] = *intern.forms_[1];
		*this->forms_[2] = *intern.forms_[2];
		this->forms_name_[0] = intern.forms_name_[0];
		this->forms_name_[1] = intern.forms_name_[1];
		this->forms_name_[2] = intern.forms_name_[2];
	}
	return *this;
}

AForm*	Intern::makeForm(std::string form_name, std::string target) {
	AForm	*form = NULL;

	for (int i = 0; i < NUMBER_OF_FORM_TYPES; i++) {
		if (forms_name_[i] == form_name) {
			form = forms_[i]->Clone(form_name, target);
			break ;
		}
	}
	return form;
}
