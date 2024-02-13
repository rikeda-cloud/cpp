#ifndef CPP05_EX02_ShrubberyCreationForm_H_
# define CPP05_EX02_ShrubberyCreationForm_H_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	class FileException : std::exception {};

private:
	static const size_t	REQUIRED_GRADE_SIGN = 145;
	static const size_t	REQUIRED_GRADE_EXECUTE = 137;

	const std::string	target_;

	ShrubberyCreationForm(void);

public:
	ShrubberyCreationForm(std::string name, std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);

	void	Action(void) const;
};

#endif
