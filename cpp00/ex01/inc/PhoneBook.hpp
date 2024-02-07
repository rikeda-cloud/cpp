#ifndef CPP00_EX01_PhoneBook_H_
# define CPP00_EX01_PhoneBook_H_

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
	static const size_t	PHONEBOOK_CAPACITY = 8;
	Contact				contacts_[PHONEBOOK_CAPACITY];
	size_t				idx_;
	bool				is_fill_;

	void	PrintAdjustedString(const std::string&) const;
	void	PrintListLine(void) const;
	void	PrintContactList(void) const;
	void	PrintContact(const Contact&) const;

public:
	PhoneBook(void);
	PhoneBook(const PhoneBook&);
	~PhoneBook(void);
	PhoneBook&	operator=(const PhoneBook&);
	size_t		GetCapacityIdx(void) const;

	enum e_continue {INPUT_CONTINUE = 0, INPUT_END = 1};

	e_continue	Add(void);
	e_continue	Search(void) const;
	e_continue	Exit(void) const;
};

#endif
