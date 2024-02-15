#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void) {
	form_make_list_[0] = &Intern::MakeShrubberyCreationForm;
	form_make_list_[1] = &Intern::MakeRobotomyRequestForm;
	form_make_list_[2] = &Intern::MakePresidentialPardonForm;
	forms_name_[0] = "shrubbery creation";
	forms_name_[1] = "robotomy request";
	forms_name_[2] = "presidential pardon";
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& intern) {
	for (int i = 0; i < NUMBER_OF_FORM_TYPES; i++) {
		form_make_list_[i] = intern.form_make_list_[i];
		forms_name_[i] = intern.forms_name_[i];
	}
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& intern) {
	if (this != &intern) {
		for (int i = 0; i < NUMBER_OF_FORM_TYPES; i++) {
			form_make_list_[i] = intern.form_make_list_[i];
			forms_name_[i] = intern.forms_name_[i];
		}
	}
	return *this;
}

AForm*	Intern::makeForm(std::string form_name, std::string target) {
	for (int i = 0; i < NUMBER_OF_FORM_TYPES; i++) {
		if (forms_name_[i] == form_name) {
			std::cout << "Intern creates " << form_name << std::endl;
			return (this->*(form_make_list_[i]))(form_name, target);
		}
	}
	std::cerr << form_name << " not found" << std::endl;
	return NULL;
}

AForm*	Intern::MakeShrubberyCreationForm(std::string& form_name, std::string& target) {
	return new ShrubberyCreationForm(form_name, target);
}

AForm*	Intern::MakeRobotomyRequestForm(std::string& form_name, std::string& target) {
	return new RobotomyRequestForm(form_name, target);
}

AForm*	Intern::MakePresidentialPardonForm(std::string& form_name, std::string& target) {
	return new PresidentialPardonForm(form_name, target);
}
