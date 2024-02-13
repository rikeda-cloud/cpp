#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int	main(void) {
	PresidentialPardonForm	p_form("pform", "home");
	ShrubberyCreationForm	s_form("sform", "berry");
	RobotomyRequestForm		r_form("rform", "robot");
	Bureaucrat				human("humanA", 1);

	human.signForm(p_form);
	human.signForm(s_form);
	human.signForm(r_form);

	human.executeForm(p_form);
	human.executeForm(s_form);
	human.executeForm(r_form);

	return 0;
}
