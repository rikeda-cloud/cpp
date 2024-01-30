#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	PhoneBook	phone_book;
	std::string	order;

	while (std::cin >> order) {
		if ((order == "ADD" && !phone_book.Add())
			|| (order == "SEARCH" && !phone_book.Search())
			|| (order == "EXIT" && !phone_book.Exit()))
			break ;
	}
	return 0;
}
