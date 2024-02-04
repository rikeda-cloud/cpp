#ifndef CPP04_EX01_Dog_H_
# define CPP04_EX01_Dog_H_

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {
private:
	Brain*	brain;

public:
	Dog(void);
	Dog(const Dog&);
	~Dog(void);
	Dog&		operator=(const Dog&);
	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
