#ifndef CPP05_EX03_Intern_H_
# define CPP05_EX03_Intern_H_

#include "AForm.hpp"
#include <string>

class Intern {
private:
	static const int	NUMBER_OF_FORM_TYPES = 3;
	AForm*				(Intern::*form_make_list_[NUMBER_OF_FORM_TYPES])(std::string&, std::string&);
	std::string			forms_name_[NUMBER_OF_FORM_TYPES];
	AForm*				MakeRobotomyRequestForm(std::string& form_name, std::string& target);
	AForm*				MakeShrubberyCreationForm(std::string& form_name, std::string& target);
	AForm*				MakePresidentialPardonForm(std::string& form_name, std::string& target);

public:
	Intern(void);
	Intern(const Intern&);
	~Intern(void);
	Intern&	operator=(const Intern&);

	AForm*			makeForm(std::string form_name, std::string target);
};

#endif
