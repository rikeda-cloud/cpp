#ifndef CPP05_EX02_PresidentialPardonForm_H_
# define CPP05_EX02_PresidentialPardonForm_H_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	static const size_t	REQUIRED_GRADE_SIGN = 25;
	static const size_t	REQUIRED_GRADE_EXECUTE = 5;

	const std::string	target_;

	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(std::string name, std::string target);
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm(void);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

	void	Action(void) const;
};

#endif
