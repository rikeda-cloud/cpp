#ifndef CPP04_EX00_Dog_H_
# define CPP04_EX00_Dog_H_

#include "Animal.hpp"
#include <string>

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog&);
	~Dog(void);
	Dog&		operator=(const Dog&);

	void		makeSound(void) const;
};

#endif
