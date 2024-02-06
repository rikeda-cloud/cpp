#include <iostream>

int	main(void) {
	std::string		string("HI THIS IS BRAIN");
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "string         memory address = " << &string << std::endl;
	std::cout << "stringPTR held memory address = " << stringPTR << std::endl;
	std::cout << "stringREF held memory address = " << &stringREF << std::endl;

	std::cout << "string               value    = \"" << string << "\"" << std::endl;
	std::cout << "stringPTR pointed to value    = \"" << *stringPTR << "\"" << std::endl;
	std::cout << "stringREF pointed to value    = \"" << stringREF << "\"" << std::endl;

	return 0;
}
