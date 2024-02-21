#include "PhoneBook.hpp"
#include "InputUtils.hpp"
#include <iostream>

int	main(void) {
	PhoneBook	phone_book;
	std::string	command;

	while (true) {
		command = InputUtils::InputString(">> ", std::isupper);
		if (std::cin.eof() || phone_book.Execute(command) == PhoneBook::END)
			break ;
	}
	return 0;
}
