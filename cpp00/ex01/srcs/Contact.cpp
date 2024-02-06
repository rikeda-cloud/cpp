#include "Contact.hpp"
#include "Input.hpp"
#include <iostream>

Contact::Contact(void) {}

Contact::Contact(const Contact& contact)
	:	first_name_(contact.first_name_),
		last_name_(contact.last_name_),
		nick_name_(contact.nick_name_),
		phone_number_(contact.phone_number_),
		secret_(contact.secret_) {}

Contact::~Contact(void) {}

Contact&	Contact::operator=(const Contact& contact) {
	if (this != &contact) {
		this->first_name_ = contact.first_name_;
		this->last_name_ = contact.last_name_;
		this->nick_name_ = contact.nick_name_;
		this->phone_number_ = contact.phone_number_;
		this->secret_ = contact.secret_;
	}
	return *this;
}

const std::string&	Contact::GetFirstName(void) const {
	return first_name_;
}

const std::string&	Contact::GetLastName(void) const {
	return last_name_;
}

const std::string&	Contact::GetNickName(void) const {
	return nick_name_;
}

const std::string&	Contact::GetPhoneNumber(void) const {
	return phone_number_;
}

const std::string&	Contact::GetSecret(void) const {
	return secret_;
}

Input::e_continue	Contact::SetFirstName(void) {
	first_name_ = Input::InputString("FIRST NAME   >> ", std::isalpha);
	if (std::cin.eof())
		return Input::INPUT_END;
	return Input::INPUT_CONTINUE;
}

Input::e_continue	Contact::SetLastName(void) {
	last_name_ = Input::InputString("LAST NAME    >> ", std::isalpha);
	if (std::cin.eof())
		return Input::INPUT_END;
	return Input::INPUT_CONTINUE;
}

Input::e_continue	Contact::SetNickName(void) {
	nick_name_ = Input::InputString("NICK NAME    >> ", std::isalnum);
	if (std::cin.eof())
		return Input::INPUT_END;
	return Input::INPUT_CONTINUE;
}

Input::e_continue	Contact::SetPhoneNumber(void) {
	phone_number_ = Input::InputString("PHONE NUMBER >> ", std::isdigit);
	if (std::cin.eof())
		return Input::INPUT_END;
	return Input::INPUT_CONTINUE;
}

Input::e_continue	Contact::SetSecret(void) {
	secret_ = Input::InputString("SECRET       >> ", std::isprint);
	if (std::cin.eof())
		return Input::INPUT_END;
	return Input::INPUT_CONTINUE;
}

void	Contact::PrintContact(void) const {
	std::cout << "FIRST NAME   -> [" << GetFirstName() << "]" << std::endl;
	std::cout << "LAST NAME    -> [" << GetLastName() << "]" << std::endl;
	std::cout << "NICK NAME    -> [" << GetNickName() << "]" << std::endl;
	std::cout << "PHONE NUMBER -> [" << GetPhoneNumber() << "]" << std::endl;
	std::cout << "SECRET       -> [" << GetSecret() << "]" << std::endl;
}
