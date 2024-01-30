#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {

}

void	Contact::SetContact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret) {
	this->first_name_ = first_name;
	this->last_name_ = last_name;
	this->nick_name_ = nick_name;
	this->phone_number_ = phone_number;
	this->secret_ = secret;
}

std::string	Contact::GetFirstName(void) const {
	return first_name_;
}

std::string	Contact::GetLastName(void) const {
	return last_name_;
}

std::string	Contact::GetNickName(void) const {
	return nick_name_;
}

std::string	Contact::GetPhoneNumber(void) const {
	return phone_number_;
}

std::string	Contact::GetSecret(void) const {
	return secret_;
}
