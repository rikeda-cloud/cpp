#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	try {
		Bureaucrat	b("my", 0);
	}
	catch (std::exception& e) {
		std::cout << "Error!!" << std::endl;
	}

	try {
		Bureaucrat	b("my", 151);
	}
	catch (std::exception& e) {
		std::cout << "Error!!" << std::endl;
	}

	try {
		Bureaucrat	b("my", 150);
		while (true) {
			b.GradeUp(3);
			std::cout << b;
		}
	}
	catch (std::exception& e) {
		std::cout << "Error!!" << std::endl;
	}

	try {
		Bureaucrat	b("my", 1);
		while (true) {
			b.GradeDown(3);
			std::cout << b;
		}
	}
	catch (std::exception& e) {
		std::cout << "Error!!" << std::endl;
	}

	return 0;
}

//// [TEST] operator=
// int	main(void) {
// 	Bureaucrat	b1("b1", 1);
// 	Bureaucrat	b2("b2", 2);

// 	b2 = b1;
// 	std::cout << b2 << std::endl;

// 	return 0;
// }
