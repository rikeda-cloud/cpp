#ifndef CPP05_EX03_RobotmyRequestForm_H_
# define CPP05_EX03_RobotmyRequestForm_H_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	static const size_t	REQUIRED_GRADE_SIGN = 72;
	static const size_t	REQUIRED_GRADE_EXECUTE = 45;

	const std::string	target_;

	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(std::string name, std::string target);
	RobotomyRequestForm(const RobotomyRequestForm&);
	~RobotomyRequestForm(void);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

	void	Action(void) const;
	AForm*	Clone(std::string& name, std::string& target) const;
};

#endif
