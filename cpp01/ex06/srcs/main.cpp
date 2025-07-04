#include "Harl.hpp"
#include <iostream>

int	main(void) {
	Harl	harl;

	std::cout << "--- DEBUG ---" << std::endl;
	harl.complain("DEBUG");
	std::cout << "--- INFO ---" << std::endl;
	harl.complain("INFO");
	std::cout << "--- WARNING ---" << std::endl;
	harl.complain("WARNING");
	std::cout << "--- ERROR ---" << std::endl;
	harl.complain("ERROR");
	std::cout << "--- NO LEVEL ---" << std::endl;
	harl.complain("NONO");
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q harlFilter");
// }
