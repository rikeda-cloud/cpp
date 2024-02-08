#include "PhoneBook.hpp"
#include "Input.hpp"
#include <iostream>

int	main(void) {
	PhoneBook	phone_book;
	std::string	order;

	while (true) {
		order = Input::InputString(">> ", std::isupper);
		if (std::cin.eof())
			break ;
		else if ((order == std::string("ADD") && phone_book.Add() == PhoneBook::INPUT_END)
			|| (order == std::string("SEARCH") && phone_book.Search() == PhoneBook::INPUT_END)
			|| (order == std::string("EXIT") && phone_book.Exit()) == PhoneBook::INPUT_END)
			break ;
	}
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q phonebook");
// }
