#ifndef CPP04_EX02_Cat_H_
# define CPP04_EX02_Cat_H_

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat&);
	~Cat(void);
	Cat&		operator=(const Cat&);
	void		makeSound(void) const;
	std::string	getType(void) const;

private:
	Brain*	brain;
};

#endif
