#include "PhoneBook.hpp"
#include "Input.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook(void) : idx_(0) {}

PhoneBook::PhoneBook(const PhoneBook& phonebook) : idx_(phonebook.idx_) {
	for (size_t i = 0; i < (this->idx_ % PhoneBook::PHONE_BOOK_CAPACITY); i++)
		this->contacts_[i] = phonebook.contacts_[i];
}

PhoneBook::~PhoneBook(void) {}

PhoneBook&	PhoneBook::operator=(const PhoneBook& phonebook) {
	if (this != &phonebook) {
		this->idx_ = phonebook.idx_;
		for (size_t i = 0; i < (this->idx_ % PhoneBook::PHONE_BOOK_CAPACITY); i++)
			this->contacts_[i] = phonebook.contacts_[i];
	}
	return *this;
}

void	PhoneBook::PrintAdjustedString(const std::string& s) const {
	static size_t	adjust_size = 10;

	if (s.size() < adjust_size) {
		std::cout.width(adjust_size);
		std::cout << s;
	}
	else
		std::cout << s.substr(0, adjust_size - 1) << ".";
}

void	PhoneBook::PrintContactList(void) const {
	for (size_t i = 0; i < (idx_ % PhoneBook::PHONE_BOOK_CAPACITY); i++) {
		const Contact&	contact = contacts_[i];
		for (int i = 0; i < 45; i++)
			std::cout << "-";
		std::cout << std::endl;
		std::cout << "|";
		std::stringstream ss;
		ss << i + 1;
		PrintAdjustedString(ss.str());
		std::cout << "|";
		PrintAdjustedString(contact.GetFirstName());
		std::cout << "|";
		PrintAdjustedString(contact.GetLastName());
		std::cout << "|";
		PrintAdjustedString(contact.GetNickName());
		std::cout << "|";
		std::cout << std::endl;
	}
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
}

PhoneBook::e_continue	PhoneBook::Add(void) {
	static size_t	INFO_SIZE = 5;
	std::string		str[INFO_SIZE];
	const char		*info[] = {
		"FIRST NAME   >> ",
		"LAST NAME    >> ",
		"NICK NAME    >> ",
		"PHONE NUMBER >> ",
		"SECRET       >> "
	};

	for (size_t i = 0; i < INFO_SIZE; i++) {
		str[i] = Input::InputString(info[i]);
		if (std::cin.eof())
			return PHONE_BOOK_END;
	}
	contacts_[idx_ % PhoneBook::PHONE_BOOK_CAPACITY].SetContact(str[0], str[1], str[2], str[3], str[4]);
	if (idx_ == (PhoneBook::PHONE_BOOK_CAPACITY * 2))
		idx_ -= PhoneBook::PHONE_BOOK_CAPACITY;
	else
		idx_++;
	return PHONE_BOOK_CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Search(void) const {
	if (this->idx_ == 0) {
		std::cout << "There are no contacts registered yet" << std::endl;
		return PHONE_BOOK_CONTINUE;
	}
	PhoneBook::PrintContactList();
	size_t	capacity = idx_ < PhoneBook::PHONE_BOOK_CAPACITY ? idx_ : PhoneBook::PHONE_BOOK_CAPACITY;
	size_t	selected_index = Input::InputIndex("INDEX >> ", capacity);
	if (std::cin.eof())
		return PHONE_BOOK_END;
	this->contacts_[selected_index - 1].PrintContact();
	return PHONE_BOOK_CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Exit(void) const {
	return PHONE_BOOK_END;
}
