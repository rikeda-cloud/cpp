#include "PhoneBook.hpp"
#include "Input.hpp"
#include <iostream>

int	main(void) {
	PhoneBook	phone_book;
	std::string	command;

	while (true) {
		command = Input::InputString(">> ", std::isupper);
		if (std::cin.eof() || phone_book.Execute(command) == PhoneBook::END)
			break ;
	}
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q phonebook");
// }
