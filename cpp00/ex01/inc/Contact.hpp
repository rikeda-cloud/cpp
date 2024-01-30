#ifndef CPP00_EX01_Contact_H_
# define CPP00_EX01_Contact_H_

#include <string>

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

#endif
