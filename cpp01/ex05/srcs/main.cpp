#include "Harl.hpp"
#include <iostream>

int	main(void) {
	std::cout << "--- Normal ---" << std::endl;
	Harl	harl;
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("NONO");

	std::cout << "--- Copy ---" << std::endl;
	Harl	harl2(harl);
	harl2.complain("DEBUG");
	harl2.complain("WARNING");
	harl2.complain("ERROR");
	harl2.complain("INFO");
	harl2.complain("NONO");

	std::cout << "--- Operator= ---" << std::endl;
	Harl	harl3 = harl;
	harl3.complain("DEBUG");
	harl3.complain("WARNING");
	harl3.complain("ERROR");
	harl3.complain("INFO");
	harl3.complain("NONO");

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q Harl");
// }
