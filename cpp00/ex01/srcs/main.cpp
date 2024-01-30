#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	PhoneBook	phone_book;
	std::string	order;

	std::cout << ">>";
	while (true) {
		std::getline(std::cin, order);
		if (std::cin.eof())
			break ;
		else if ((order == "ADD" && phone_book.Add())
			|| (order == "SEARCH" && phone_book.Search())
			|| (order == "EXIT" && phone_book.Exit()))
			break ;
		std::cout << ">>";
	}
	return 0;
}
