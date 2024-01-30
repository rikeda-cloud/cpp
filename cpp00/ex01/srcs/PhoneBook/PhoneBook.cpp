#include "PhoneBook.hpp"
#include <cstddef>
#include <iostream>

PhoneBook::PhoneBook(void) {
	idx_ = 0;
}

bool	PhoneBook::input_str(void) {
	while (true) {
		std::cout << ">";
		std::getline(std::cin, input_);
		if (std::cin.eof())
			return false ;
	}
	return true;
}

size_t	_input_idx(size_t min, size_t max) {
	size_t	idx;

	while (true) {
		std::cout << ">";
		std::cin >> idx;
		if (std::cin.eof() || (min <= idx && idx < max))
			break ;
	}
	return idx;
}

bool	PhoneBook::Add(void) {
	const static size_t	info_size = 5;
	std::string			str[info_size];
	std::string			tmp_str;

	for (size_t i = 0; i < info_size; i++) {
		if (!input_str())
			return false;
		str[i] = input_;
	}
	contacts_[idx_++].SetContact(str[0], str[1], str[2], str[3], str[4]);
	return true;
}

bool	PhoneBook::Search(void) const {
	size_t	index;

	index = _input_idx(0, idx_);
	if (std::cin.eof())
		return false;
	std::cout << contacts_[index].GetFirstName() << std::endl;
	std::cout << contacts_[index].GetLastName() << std::endl;
	std::cout << contacts_[index].GetNickName() << std::endl;
	std::cout << contacts_[index].GetPhoneNumber() << std::endl;
	std::cout << contacts_[index].GetSecret() << std::endl;
	return true;
}

bool	PhoneBook::Exit(void) const {
	return true;
}
