#ifndef CPP04_EX00_WrongCat_H_
# define CPP04_EX00_WrongCat_H_

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat&);
	~WrongCat(void);
	WrongCat&	operator=(const WrongCat&);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
