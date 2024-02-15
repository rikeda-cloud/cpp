#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void) {
	Intern	someRandomIntern;
	AForm*	rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;

	delete rrf;
	return 0;
}

	__attribute__((destructor)) static void destructor()
{
   system("leaks -q Intern");
}
