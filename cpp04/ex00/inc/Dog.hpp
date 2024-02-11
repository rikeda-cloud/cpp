#ifndef CPP04_EX00_Dog_H_
# define CPP04_EX00_Dog_H_

#include <string>
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog&);
	~Dog(void);
	Dog&		operator=(const Dog&);
	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
