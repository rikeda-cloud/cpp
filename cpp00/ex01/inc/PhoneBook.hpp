#ifndef CPP00_EX01_PHONEBOOK_H_
# define CPP00_EX01_PHONEBOOK_H_

#include "Contact.hpp"
#include <cstddef>
#include <string>

class PhoneBook {
private:
	static const int	PHONE_BOOK_CAPACITY = 8;
	Contact				contacts_[PHONE_BOOK_CAPACITY];
	size_t				idx_;
	std::string			input_;
	void		_print_contact_list(void) const;

public:
	PhoneBook();
	bool		Add();
	bool		Search() const;
	bool		Exit() const;
};

#endif
