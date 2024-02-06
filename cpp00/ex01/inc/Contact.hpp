#ifndef CPP00_EX01_Contact_H_
# define CPP00_EX01_Contact_H_

#include "Input.hpp"
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
	Contact(const Contact&);
	~Contact();
	Contact&	operator=(const Contact&);

	const std::string&	GetFirstName(void) const;
	const std::string&	GetLastName(void) const;
	const std::string&	GetNickName(void) const;
	const std::string&	GetPhoneNumber(void) const;
	const std::string&	GetSecret(void) const;
	Input::e_continue	SetFirstName(void);
	Input::e_continue	SetLastName(void);
	Input::e_continue	SetNickName(void);
	Input::e_continue	SetPhoneNumber(void);
	Input::e_continue	SetSecret(void);
	void				PrintContact(void) const;
};

#endif
