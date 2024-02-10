#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Input.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>

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
	const size_t	adjust_size = 10;

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

void	PhoneBook::ListContacts(void) const {
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

void	PhoneBook::PrintContact(const Contact& contact) const {
	std::cout << "FIRST NAME     -> [" << contact.GetFirstName() << "]" << std::endl;
	std::cout << "LAST NAME      -> [" << contact.GetLastName() << "]" << std::endl;
	std::cout << "NICK NAME      -> [" << contact.GetNickName() << "]" << std::endl;
	std::cout << "PHONE NUMBER   -> [" << contact.GetPhoneNumber() << "]" << std::endl;
	std::cout << "DARKEST SECRET -> [" << contact.GetDarkestSecret() << "]" << std::endl;
}

PhoneBook::e_continue	PhoneBook::Add(void) {
	std::string		str[5];
	Contact&		contact = contacts_[idx_];

	str[0] = Input::InputString("FIRST NAME     >> ", std::isalpha);
	if (std::cin.eof())
		return END;
	str[1] = Input::InputString("LAST NAME      >> ", std::isalpha);
	if (std::cin.eof())
		return END;
	str[2] = Input::InputString("NICK NAME      >> ", std::isalnum);
	if (std::cin.eof())
		return END;
	str[3] = Input::InputString("PHONE NUMBER   >> ", std::isdigit);
	if (std::cin.eof())
		return END;
	str[4] = Input::InputString("DARKEST SECRET >> ", std::isprint);
	if (std::cin.eof())
		return END;
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
	return CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Search(void) const {
	if (GetCapacityIdx() == 0) {
		std::cout << "There are no contacts registered yet" << std::endl;
		return CONTINUE;
	}
	PhoneBook::ListContacts();
	size_t	selected_index = Input::InputIndex("INDEX >> ", GetCapacityIdx());
	if (std::cin.eof())
		return END;
	std::cout << std::endl; // intentional!!
	std::cout << Colors::GREEN;
	PhoneBook::PrintContact(this->contacts_[selected_index - 1]);
	std::cout << Colors::RESET;
	return CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Exit(void) const {
	return END;
}

PhoneBook::e_continue	PhoneBook::Execute(std::string& command) {
	if (command == std::string("ADD"))
		return Add();
	else if (command == std::string("SEARCH"))
		return Search();
	else if (command == std::string("EXIT"))
		return Exit();
	return CONTINUE;
}

size_t	PhoneBook::GetCapacityIdx(void) const {
	return is_fill_ ? PHONEBOOK_CAPACITY : idx_;
}
