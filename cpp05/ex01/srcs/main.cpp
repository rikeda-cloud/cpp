#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Form	form0("form0", 0, 1);
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << "Error grade too high" << std::endl;
	}
	try {
		Form	form151("form151", 1, 151);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << "Error grade too low" << std::endl;
	}

	Form	form1("form1", 1, 1);
	Form	form2("form2", 2, 2);
	Form	form3("form3", 3, 3);
	Bureaucrat	h1("human1", 1);
	Bureaucrat	h2("human2", 2);
	Bureaucrat	h3("human3", 3);

	h3.signForm(form1);
	h2.signForm(form1);
	h1.signForm(form1);
	h1.signForm(form1);

	h3.signForm(form2);
	h2.signForm(form2);
	h1.signForm(form2);
	h1.signForm(form2);

	h3.signForm(form3);
	h2.signForm(form3);
	h1.signForm(form3);
	h1.signForm(form3);
	return 0;
}

//// [TEST] operator=
// int	main(void) {
// 	Form	f1("form1", 1, 1);
// 	Form	f2("form2", 2, 2);

// 	f2 = f1;
// 	std::cout << f2;
// 	return 0;
// }
