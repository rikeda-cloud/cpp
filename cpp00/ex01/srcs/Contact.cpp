#include "Contact.hpp"
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

void	Contact::SetContact(
		std::string first_name,
		std::string last_name,
		std::string nick_name,
		std::string phone_number,
		std::string secret) {
	this->first_name_ = first_name;
	this->last_name_ = last_name;
	this->nick_name_ = nick_name;
	this->phone_number_ = phone_number;
	this->secret_ = secret;
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

void	Contact::PrintContact(void) const {
	std::cout << "FIRST NAME   -> [" << GetFirstName() << "]" << std::endl;
	std::cout << "LAST NAME    -> [" << GetLastName() << "]" << std::endl;
	std::cout << "NICK NAME    -> [" << GetNickName() << "]" << std::endl;
	std::cout << "PHONE NUMBER -> [" << GetPhoneNumber() << "]" << std::endl;
	std::cout << "SECRET       -> [" << GetSecret() << "]" << std::endl;
}
