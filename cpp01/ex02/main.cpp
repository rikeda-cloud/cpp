#include <iostream>

int	main(void) {
	std::string		string("HI THIS IS BRAIN");
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "string    memory = " << &string << std::endl;
	std::cout << "stringPTR memory = " << stringPTR << std::endl;
	std::cout << "stringREF memory = " << &stringREF << std::endl;

	std::cout << "string           = \"" << string << "\"" << std::endl;
	std::cout << "stringPTR        = " << *stringPTR << "\"" << std::endl;
	std::cout << "stringREF        = " << stringREF << "\"" << std::endl;

	return 0;
}
