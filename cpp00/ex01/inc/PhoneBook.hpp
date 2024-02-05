#ifndef CPP00_EX01_PHONEBOOK_H_
# define CPP00_EX01_PHONEBOOK_H_

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
	static const size_t	PHONE_BOOK_CAPACITY = 8;
	Contact				contacts_[PHONE_BOOK_CAPACITY];
	size_t				idx_;

	void				PrintContactList(void) const;
	void				PrintAdjustedString(const std::string&) const;

public:
	enum e_continue {PHONE_BOOK_CONTINUE = 0, PHONE_BOOK_END = 1};

	PhoneBook(void);
	PhoneBook(const PhoneBook&);
	~PhoneBook(void);
	PhoneBook&	operator=(const PhoneBook&);

	e_continue	Add(void);
	e_continue	Search(void) const;
	e_continue	Exit(void) const;
};

#endif
