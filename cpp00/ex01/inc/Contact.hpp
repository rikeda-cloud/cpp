#ifndef CPP00_EX01_Contact_H_
# define CPP00_EX01_Contact_H_

#include <string>

class Contact {
public:
	Contact(void);
	Contact(const Contact&);
	~Contact(void);
	Contact&	operator=(const Contact&);

	const std::string&	GetFirstName(void) const;
	const std::string&	GetLastName(void) const;
	const std::string&	GetNickName(void) const;
	const std::string&	GetPhoneNumber(void) const;
	const std::string&	GetDarkestSecret(void) const;
	void				SetFirstName(std::string&);
	void				SetLastName(std::string&);
	void				SetNickName(std::string&);
	void				SetPhoneNumber(std::string&);
	void				SetDarkestSecret(std::string&);

private:
	std::string	first_name_;
	std::string	last_name_;
	std::string	nick_name_;
	std::string	phone_number_;
	std::string	darkest_secret_;
};

#endif
