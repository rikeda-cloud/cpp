#ifndef CPP00_EX01_PhoneBook_H_
# define CPP00_EX01_PhoneBook_H_

#include "Contact.hpp"
#include <string>

class PhoneBook {
public:
	PhoneBook(void);
	PhoneBook(const PhoneBook&);
	~PhoneBook(void);
	PhoneBook&	operator=(const PhoneBook&);

	enum e_continue {CONTINUE = 0, END = 1};
	e_continue	Execute(std::string&);

private:
	static const size_t	PHONEBOOK_CAPACITY = 8;
	Contact				contacts_[PHONEBOOK_CAPACITY];
	size_t				idx_;
	bool				is_fill_;

	std::string	AdjustedString(std::string) const;
	void		PrintListLine(void) const;
	void		ListContacts(void) const;
	void		PrintContact(const Contact&) const;
	size_t		GetCapacityIdx(void) const;
	e_continue	InputStringWithEOFCheck(
		std::string& input_buffer,
		const char* prompt,
		int (*is_func)(int)
	) const;

	e_continue	Add(void);
	e_continue	Search(void) const;
	e_continue	Exit(void) const;
};

#endif
