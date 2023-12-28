#include "PhoneBook.hpp"
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

PhoneBook::PhoneBook(void) {
	idx_ = 0;
}

void	PhoneBook::Add(void) {
	const static size_t	info_size = 5;
	std::string			str[info_size];
	std::string			tmp;

	std::cout << "姓・名・あだ名・電話番号・秘密を入力してください" << std::endl;
	for (size_t i = 0; i < info_size; i++) {
		while (true) {
			std::cin >> tmp;
			if (tmp != "") {
				str[i] = tmp;
				break ;
			}
		}
	}
	contacts_[idx_++].SetContact(str[0], str[1], str[2], str[3], str[4]);
	return ;
}

void	PhoneBook::Search(void) const {
	size_t	index;

	while (true) {
		std::cin >> index;
		if (0 <= index && index < idx_)
			break ;
	}
	std::cout << contacts_[index].GetFirstName() << std::endl;
	std::cout << contacts_[index].GetLastName() << std::endl;
	std::cout << contacts_[index].GetNickName() << std::endl;
	std::cout << contacts_[index].GetPhoneNumber() << std::endl;
	std::cout << contacts_[index].GetSecret() << std::endl;
}
