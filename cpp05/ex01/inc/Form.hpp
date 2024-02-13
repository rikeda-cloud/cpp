#ifndef CPP05_EX01_Form_H_
# define CPP05_EX01_Form_H_

#include <iostream>

class Bureaucrat;

class Form {
public:
	static const size_t	GRADE_HIGH_LIMIT = 1;
	static const size_t	GRADE_LOW_LIMIT = 150;

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
	class AlreadySignedException : public std::exception {};

private:
	std::string	name_;
	size_t		grade_;
	bool		is_signed_;

	Form(void);

public:
	Form(std::string, size_t);
	Form(const Form&);
	~Form(void);
	Form&	operator=(const Form&);

	const std::string&	getName(void) const;
	size_t				getGrade(void) const;
	bool				getIsSigned(void) const;
	void				beSigned(const Bureaucrat&);
};

std::ostream&	operator<<(std::ostream& s, const Form&);

#endif
