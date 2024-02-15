#ifndef CPP05_EX03_Form_H_
# define CPP05_EX03_Form_H_

#include <iostream>

class Bureaucrat;

class AForm {
public:
	static const size_t	GRADE_HIGH_LIMIT = 1;
	static const size_t	GRADE_LOW_LIMIT = 150;

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
	class AlreadySignedException : public std::exception {};
	class NoSignException : public std::exception {};

private:
	const std::string	name_;
	const size_t		grade_to_sign_;
	const size_t		grade_to_execute_;
	bool				is_signed_;

	AForm(void);

public:
	AForm(std::string name, size_t grade_to_sign, size_t grade_to_execute);
	AForm(const AForm&);
	virtual	~AForm(void);
	AForm&	operator=(const AForm&);

	const std::string&	getName(void) const;
	size_t				getGradeToSign(void) const;
	size_t				getGradeToExecute(void) const;
	bool				getIsSigned(void) const;
	void				beSigned(const Bureaucrat&);

	virtual void		Action(void) const = 0;
	void				execute(Bureaucrat const& exeutor) const;
};

std::ostream&	operator<<(std::ostream& s, const AForm&);

#endif
