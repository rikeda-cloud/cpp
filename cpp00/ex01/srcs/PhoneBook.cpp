#include "PhoneBook.hpp"
#include <cstddef>
#include <iostream>
#include <string>

std::string	_input_str(void) {
	std::string buffer;
	std::cout << ")";
	while (std::getline(std::cin, buffer)) {
		if (!std::all_of(buffer.cbegin(), buffer.cend(), isspace))
			break ;
		std::cout << ")";
	}
	return buffer;
}

size_t	_input_idx(int max_idx)
{
	std::string	buffer;
	while (true) {
		buffer = _input_str();
		if (std::cin.eof())
			return 0;
		else if (std::all_of(buffer.cbegin(), buffer.cend(), isdigit)
			&& buffer.size() == 1
			&& stoi(buffer) < max_idx)
			return stoi(buffer);
	}
}

void	_print_adjusted_string(std::string s) {
	if (s.size() < 10) {
		std::cout.width(10);
		std::cout << s;
	}
	else
		std::cout << s.substr(0, 9) << ".";
}

void	PhoneBook::_print_contact_list(void) const {
	for (size_t i = 0; i < idx_ % PhoneBook::PHONE_BOOK_CAPACITY; i++) {
		const Contact&	contact = contacts_[i];
		for (int i = 0; i < 45; i++)
			std::cout << "-";
		std::cout << std::endl;
		std::cout << "|";
		_print_adjusted_string(contact.GetFirstName());
		std::cout << "|";
		_print_adjusted_string(contact.GetLastName());
		std::cout << "|";
		_print_adjusted_string(contact.GetNickName());
		std::cout << "|";
		_print_adjusted_string(contact.GetPhoneNumber());
		std::cout << "|";
		std::cout << std::endl;
	}
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
}

PhoneBook::PhoneBook(void) : idx_(0) {
}

bool	PhoneBook::Add(void) {
	const static size_t	info_size = 5;
	std::string			str[info_size];
	std::string			tmp_str;

	for (size_t i = 0; i < info_size; i++) {
		str[i] = _input_str();
		if (std::cin.eof())
			return true;
	}
	contacts_[idx_ % PhoneBook::PHONE_BOOK_CAPACITY].SetContact(str[0], str[1], str[2], str[3], str[4]);
	if (idx_ == PhoneBook::PHONE_BOOK_CAPACITY * 2)
		idx_ -= PhoneBook::PHONE_BOOK_CAPACITY;
	else
		idx_++;
	return false;
}

bool	PhoneBook::Search(void) const {
	size_t	index;

	if (idx_ == 0) {
		std::cout << "There are no contacts registered yet" << std::endl;
		return false;
	}
	_print_contact_list();
	index = idx_ < PhoneBook::PHONE_BOOK_CAPACITY ? _input_idx(idx_) : _input_idx(PHONE_BOOK_CAPACITY);
	if (std::cin.eof())
		return true;
	const Contact&	contact = contacts_[index];
	std::cout << contact.GetFirstName() << std::endl;
	std::cout << contact.GetLastName() << std::endl;
	std::cout << contact.GetNickName() << std::endl;
	std::cout << contact.GetPhoneNumber() << std::endl;
	std::cout << contact.GetSecret() << std::endl;
	return false;
}

bool	PhoneBook::Exit(void) const {
	return true;
}
