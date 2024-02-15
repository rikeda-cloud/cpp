#ifndef CPP05_EX03_Bureaucrat_H_
# define CPP05_EX03_Bureaucrat_H_

#include <iostream>

class AForm;

class Bureaucrat {
public:
	static const size_t	GRADE_HIGH_LIMIT = 1;
	static const size_t	GRADE_LOW_LIMIT = 150;

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

private:
	const std::string	name_;
	size_t				grade_;

	Bureaucrat(void);

public:
	Bureaucrat(std::string, size_t);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat(void);
	Bureaucrat&	operator=(const Bureaucrat&);

	const std::string&	getName(void) const;
	size_t				getGrade(void) const;
	void				GradeUp(size_t);
	void				GradeDown(size_t);
	void				signForm(AForm&);
	void				executeForm(AForm const& form);
};

std::ostream&	operator<<(std::ostream& s, const Bureaucrat&);

#endif
