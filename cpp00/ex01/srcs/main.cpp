#include "PhoneBook.hpp"
#include "Input.hpp"
#include <iostream>

int	main(void) {
	const char	prompt[] = ">> ";
	PhoneBook	phone_book;
	std::string	order;

	while (true) {
		order = Input::InputString(prompt, std::isupper);
		if (std::cin.eof())
			break ;
		else if ((order == "ADD" && phone_book.Add() == Input::INPUT_END)
			|| (order == "SEARCH" && phone_book.Search() == Input::INPUT_END)
			|| (order == "EXIT" && phone_book.Exit()) == Input::INPUT_END)
			break ;
	}
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q phonebook");
// }
