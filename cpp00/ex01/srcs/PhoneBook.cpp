#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Input.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>

const std::string Colors::RESET = "\033[0m";
const std::string Colors::GREEN = "\033[32m";
const std::string Colors::MAGENTA = "\033[35m";

PhoneBook::PhoneBook(void) : idx_(0) {}

PhoneBook::PhoneBook(const PhoneBook& phonebook) : idx_(phonebook.idx_) {
	for (size_t i = 0; i < (this->idx_ % PhoneBook::PHONEBOOK_CAPACITY); i++)
		this->contacts_[i] = phonebook.contacts_[i];
}

PhoneBook::~PhoneBook(void) {}

PhoneBook&	PhoneBook::operator=(const PhoneBook& phonebook) {
	if (this != &phonebook) {
		this->idx_ = phonebook.idx_;
		for (size_t i = 0; i < (this->idx_ % PhoneBook::PHONEBOOK_CAPACITY); i++)
			this->contacts_[i] = phonebook.contacts_[i];
	}
	return *this;
}

void	PhoneBook::PrintAdjustedString(const std::string& s) const {
	static const size_t	adjust_size = 10;

	if (s.size() <= adjust_size) {
		std::cout.width(adjust_size);
		std::cout << s;
	}
	else
		std::cout << s.substr(0, adjust_size - 1) << ".";
}

void	PhoneBook::PrintListLine(void) const {
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	PhoneBook::PrintContactList(void) const {
	std::cout << std::endl; // intentional!!
	std::cout << Colors::MAGENTA;
	for (size_t i = 0; i < (idx_ % PhoneBook::PHONEBOOK_CAPACITY); i++) {
		const Contact&		contact = contacts_[i];
		std::stringstream	ss;
		PrintListLine();
		std::cout << "|";
		ss << i + 1;
		PrintAdjustedString(ss.str());
		std::cout << "|";
		PrintAdjustedString(contact.GetFirstName());
		std::cout << "|";
		PrintAdjustedString(contact.GetLastName());
		std::cout << "|";
		PrintAdjustedString(contact.GetNickName());
		std::cout << "|" << std::endl;
	}
	PrintListLine();
	std::cout << Colors::RESET;
}

Input::e_continue	PhoneBook::Add(void) {
	static size_t	INFO_SIZE = 5;
	std::string		str[INFO_SIZE];
	Contact&		contact = contacts_[idx_ % PhoneBook::PHONEBOOK_CAPACITY];

	if (contact.SetFirstName() == Input::INPUT_END
		|| contact.SetLastName() == Input::INPUT_END
		|| contact.SetNickName() == Input::INPUT_END
		|| contact.SetPhoneNumber() == Input::INPUT_END
		|| contact.SetSecret() == Input::INPUT_END
	)
		return Input::INPUT_END;
	if (idx_ == (PhoneBook::PHONEBOOK_CAPACITY * 2))
		idx_ -= PhoneBook::PHONEBOOK_CAPACITY;
	else
		idx_++;
	return Input::INPUT_CONTINUE;
}

Input::e_continue	PhoneBook::Search(void) const {
	if (this->idx_ == 0) {
		std::cout << "There are no contacts registered yet" << std::endl;
		return Input::INPUT_CONTINUE;
	}
	PhoneBook::PrintContactList();
	size_t	capacity = idx_ < PhoneBook::PHONEBOOK_CAPACITY ? idx_ : PhoneBook::PHONEBOOK_CAPACITY;
	size_t	selected_index = Input::InputIndex("INDEX >> ", capacity);
	if (std::cin.eof())
		return Input::INPUT_END;
	std::cout << std::endl; // intentional!!
	std::cout << Colors::GREEN;
	this->contacts_[selected_index - 1].PrintContact();
	std::cout << Colors::RESET;
	return Input::INPUT_CONTINUE;
}

Input::e_continue	PhoneBook::Exit(void) const {
	return Input::INPUT_END;
}
