#ifndef CPP00_EX01_PHONEBOOK_H_
# define CPP00_EX01_PHONEBOOK_H_

#include "Contact.hpp"
#include "Input.hpp"
#include <string>

class PhoneBook {
private:
	static const size_t	PHONEBOOK_CAPACITY = 8;
	Contact				contacts_[PHONEBOOK_CAPACITY];
	size_t				idx_;

	void				PrintListLine(void) const;
	void				PrintContactList(void) const;
	void				PrintAdjustedString(const std::string&) const;

public:
	PhoneBook(void);
	PhoneBook(const PhoneBook&);
	~PhoneBook(void);
	PhoneBook&	operator=(const PhoneBook&);

	Input::e_continue	Add(void);
	Input::e_continue	Search(void) const;
	Input::e_continue	Exit(void) const;
};

#endif
