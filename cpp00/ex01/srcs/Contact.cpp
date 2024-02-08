#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(const Contact& contact)
	:	first_name_(contact.first_name_),
		last_name_(contact.last_name_),
		nick_name_(contact.nick_name_),
		phone_number_(contact.phone_number_),
		darkest_secret_(contact.darkest_secret_) {}

Contact::~Contact(void) {}

Contact&	Contact::operator=(const Contact& contact) {
	if (this != &contact) {
		this->first_name_ = contact.first_name_;
		this->last_name_ = contact.last_name_;
		this->nick_name_ = contact.nick_name_;
		this->phone_number_ = contact.phone_number_;
		this->darkest_secret_ = contact.darkest_secret_;
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

const std::string&	Contact::GetDarkestSecret(void) const {
	return darkest_secret_;
}

void	Contact::SetFirstName(std::string first_name) {
	this->first_name_ = first_name;
}

void	Contact::SetLastName(std::string last_name) {
	this->last_name_ = last_name;
}

void	Contact::SetNickName(std::string nick_name) {
	this->nick_name_ = nick_name;
}

void	Contact::SetPhoneNumber(std::string phone_number) {
	this->phone_number_ = phone_number;
}

void	Contact::SetDarkestSecret(std::string darkest_secret) {
	this->darkest_secret_ = darkest_secret;
}
