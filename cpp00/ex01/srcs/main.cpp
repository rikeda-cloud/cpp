#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	PhoneBook	phone_book;
	std::string	order;

	while (std::cin >> order) {
		if (order == "ADD")
			phone_book.Add();
		else if (order == "SEARCH")
			phone_book.Search();
		else if (order == "EXIT")
			break ;
	}
	return 0;
}
