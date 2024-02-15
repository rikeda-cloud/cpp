#ifndef CPP05_EX03_Intern_H_
# define CPP05_EX03_Intern_H_

#include "AForm.hpp"
#include <string>

class Intern {
private:
	static const int	NUMBER_OF_FORM_TYPES = 3;
	AForm				*forms_[NUMBER_OF_FORM_TYPES];
	std::string			forms_name_[NUMBER_OF_FORM_TYPES];

public:
	Intern(void);
	Intern(const Intern&);
	~Intern(void);
	Intern&	operator=(const Intern&);

	AForm*	makeForm(std::string form_name, std::string target);
};

#endif
