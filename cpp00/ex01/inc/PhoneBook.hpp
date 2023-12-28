#ifndef CPP00_EX01_PHONEBOOK_H_
# define CPP00_EX01_PHONEBOOK_H_

# define PHONE_BOOK_CAPACITY 8

#include <iostream>

class Contact {
private:
	std::string	first_name_;
	std::string	last_name_;
	std::string	nick_name_;
	std::string	phone_number_;
	std::string	secret_;

public:
	Contact();
	std::string	GetFirstName(void) const;
	std::string	GetLastName(void) const;
	std::string	GetNickName(void) const;
	std::string	GetPhoneNumber(void) const;
	std::string	GetSecret(void) const;
	void		SetContact(std::string, std::string, std::string, std::string, std::string);
};

class PhoneBook {
private:
	size_t	idx_;
	Contact	contacts_[PHONE_BOOK_CAPACITY];

public:
	PhoneBook();
	void	Add();
	void	Search() const;
};

#endif
