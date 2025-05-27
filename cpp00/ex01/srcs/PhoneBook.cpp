#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "InputUtils.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook(void) : idx_(0), is_fill_(false) {}

PhoneBook::PhoneBook(const PhoneBook& phonebook) : idx_(phonebook.idx_), is_fill_(phonebook.is_fill_) {
	size_t	capacity_idx = phonebook.GetCapacityIdx();

	for (size_t i = 0; i < capacity_idx; ++i)
		this->contacts_[i] = phonebook.contacts_[i];
}

PhoneBook::~PhoneBook(void) {}

PhoneBook&	PhoneBook::operator=(const PhoneBook& phonebook) {
	if (this != &phonebook) {
		this->idx_ = phonebook.idx_;
		this->is_fill_ = phonebook.is_fill_;
		size_t	capacity_idx = phonebook.GetCapacityIdx();
		for (size_t i = 0; i < capacity_idx; ++i)
			this->contacts_[i] = phonebook.contacts_[i];
	}
	return *this;
}

std::string	PhoneBook::AdjustedString(std::string s) const {
	static const size_t	adjust_size = 10;

	if (s.size() <= adjust_size) {
		for (size_t i = s.size(); i < adjust_size; ++i)
			s.insert(0, " ");
	}
	else
		s = s.substr(0, adjust_size - 1) + std::string(".");
	return s;
}

void	PhoneBook::PrintListLine(void) const {
	for (int i = 0; i < 45; ++i)
		std::cout << "-";
	std::cout << std::endl;
}

void	PhoneBook::ListContacts(void) const {
	std::cout << std::endl; // intentional!!
	std::cout << Colors::MAGENTA;
	size_t	capacity_idx = GetCapacityIdx();
	for (size_t i = 0; i < capacity_idx; ++i) {
		const Contact&		contact = contacts_[i];
		PrintListLine();
		std::stringstream	ss;
		ss << i + 1;
		std::cout << "|";
		std::cout << AdjustedString(ss.str()) << "|";
		std::cout << AdjustedString(contact.GetFirstName()) << "|";
		std::cout << AdjustedString(contact.GetLastName()) << "|";
		std::cout << AdjustedString(contact.GetNickName()) << "|";
		std::cout << std::endl;
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

PhoneBook::e_continue	PhoneBook::InputStringWithEOFCheck(
		std::string& input_buffer,
		const char* prompt,
		int (*is_func)(int)) const {
	input_buffer = InputUtils::InputString(prompt, is_func);
	if (std::cin.eof())
		return END;
	return CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Add(void) {
	std::string			input_buffer[5];
	const char			*prompts[5] = {
		"FIRST NAME     >> ",
		"LAST NAME      >> ",
		"NICK NAME      >> ",
		"PHONE NUMBER   >> ",
		"DARKEST SECRET >> "
	};

	if (InputStringWithEOFCheck(input_buffer[0], prompts[0], std::isalpha) == END
		|| InputStringWithEOFCheck(input_buffer[1], prompts[1], std::isalpha) == END
		|| InputStringWithEOFCheck(input_buffer[2], prompts[2], std::isalnum) == END
		|| InputStringWithEOFCheck(input_buffer[3], prompts[3], std::isdigit) == END
		|| InputStringWithEOFCheck(input_buffer[4], prompts[4], std::isprint) == END)
		return END;
	Contact&	contact = contacts_[idx_];
	contact.SetFirstName(input_buffer[0]);
	contact.SetLastName(input_buffer[1]);
	contact.SetNickName(input_buffer[2]);
	contact.SetPhoneNumber(input_buffer[3]);
	contact.SetDarkestSecret(input_buffer[4]);
	++idx_;
	if (idx_ == PHONEBOOK_CAPACITY) {
		idx_ = 0;
		is_fill_ = true;
	}
	return CONTINUE;
}

PhoneBook::e_continue	PhoneBook::Search(void) const {
	size_t	capacity_idx = GetCapacityIdx();

	if (capacity_idx == 0) {
		std::cout << "There are no contacts registered yet" << std::endl;
		return CONTINUE;
	}
	PhoneBook::ListContacts();
	size_t	selected_index = InputUtils::InputIndex("INDEX >> ", capacity_idx);
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
	if (command == std::string("SEARCH"))
		return Search();
	if (command == std::string("EXIT"))
		return Exit();
	return CONTINUE;
}

size_t	PhoneBook::GetCapacityIdx(void) const {
	return is_fill_ ? PHONEBOOK_CAPACITY : idx_;
}
