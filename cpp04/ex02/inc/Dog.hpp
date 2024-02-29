#ifndef CPP04_EX02_Dog_H_
# define CPP04_EX02_Dog_H_

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog&);
	~Dog(void);
	Dog&	operator=(const Dog&);

	void	makeSound(void) const;
	void	comeUpWithIdea(size_t idx, const std::string& idea);
	void	rememberIdea(size_t idx) const;

private:
	Brain*	brain;
};

#endif
