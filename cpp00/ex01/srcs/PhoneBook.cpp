#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Input.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>

const std::string Colors::RESET = "\033[0m";
const std::string Colors::GREEN = "\033[32m";
const std::string Colors::MAGENTA = "\033[35m";

PhoneBook::PhoneBook(void) : idx_(0), is_fill_(false) {}

PhoneBook::PhoneBook(const PhoneBook& phonebook) : idx_(phonebook.idx_), is_fill_(phonebook.is_fill_) {
	for (size_t i = 0; i < GetCapacityIdx(); i++)
		this->contacts_[i] = phonebook.contacts_[i];
}

PhoneBook::~PhoneBook(void) {}

PhoneBook&	PhoneBook::operator=(const PhoneBook& phonebook) {
	if (this != &phonebook) {
		this->idx_ = phonebook.idx_;
		this->is_fill_ = phonebook.is_fill_;
		for (size_t i = 0; i < GetCapacityIdx(); i++)
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
	for (size_t i = 0; i < GetCapacityIdx(); i++) {
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

PhoneBook::e_continue	PhoneBook::Add(void) {
	static size_t	INFO_SIZE = 5;
	std::string		str[INFO_SIZE];
	Contact&		contact = contacts_[idx_];

	str[0] = Input::InputString("FIRST NAME     >> ", std::isalpha);
	if (std::cin.eof())
		return INPUT_END;
	str[1] = Input::InputString("LAST NAME      >> ", std::isalpha);
	if (std::cin.eof())
		return INPUT_END;
	str[2] = Input::InputString("NICK NAME      >> ", std::isalnum);
	if (std::cin.eof())
		return INPUT_END;
	str[3] = Input::InputString("PHONE NUMBER   >> ", std::isdigit);
	if (std::cin.eof())
		return INPUT_END;
	str[4] = Input::InputString("DARKEST SECRET >> ", std::isprint);
	if (std::cin.eof())
		return INPUT_END;
	contact.SetFirstName(str[0]);
	contact.SetLastName(str[1]);
	contact.SetNickName(str[2]);
	contact.SetPhoneNumber(str[3]);
	contact.SetDarkestSecret(str[4]);
	idx_++;
	if (idx_ == PHONEBOOK_CAPACITY) {
		idx_ = 0;
		is_fill_ = true;
	}
	return INPUT_CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Search(void) const {
	if (GetCapacityIdx() == 0) {
		std::cout << "There are no contacts registered yet" << std::endl;
		return INPUT_CONTINUE;
	}
	PhoneBook::PrintContactList();
	size_t	selected_index = Input::InputIndex("INDEX >> ", GetCapacityIdx());
	if (std::cin.eof())
		return INPUT_END;
	std::cout << std::endl; // intentional!!
	std::cout << Colors::GREEN;
	this->contacts_[selected_index - 1].PrintContact();
	std::cout << Colors::RESET;
	return INPUT_CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Exit(void) const {
	return INPUT_END;
}

size_t	PhoneBook::GetCapacityIdx(void) const {
	return is_fill_ ? PHONEBOOK_CAPACITY : idx_;
}
