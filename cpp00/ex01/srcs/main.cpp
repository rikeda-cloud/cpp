#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	static std::string	prompt(">> ");
	PhoneBook			phone_book;
	std::string			order;

	std::cout << prompt << std::flush;
	while (true) {
		std::getline(std::cin, order);
		if (std::cin.eof())
			break ;
		else if ((order == "ADD" && phone_book.Add() == PhoneBook::PHONE_BOOK_END)
			|| (order == "SEARCH" && phone_book.Search() == PhoneBook::PHONE_BOOK_END)
			|| (order == "EXIT" && phone_book.Exit()) == PhoneBook::PHONE_BOOK_END)
			break ;
		std::cout << prompt << std::flush;
	}
	return 0;
}
