#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	static const std::string	prompt(">> ");
	PhoneBook					phone_book;
	std::string					order;

	std::cout << prompt << std::flush;
	while (true) {
		std::getline(std::cin, order);
		if (std::cin.eof())
			break ;
		else if ((order == "ADD" && phone_book.Add() == PhoneBook::PHONEBOOK_END)
			|| (order == "SEARCH" && phone_book.Search() == PhoneBook::PHONEBOOK_END)
			|| (order == "EXIT" && phone_book.Exit()) == PhoneBook::PHONEBOOK_END)
			break ;
		std::cout << prompt << std::flush;
	}
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q phonebook");
// }
