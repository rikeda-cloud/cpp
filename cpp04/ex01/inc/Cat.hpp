#ifndef CPP04_EX01_Cat_H_
# define CPP04_EX01_Cat_H_

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat&);
	~Cat(void);
	Cat&	operator=(const Cat&);

	void	makeSound(void) const;
	void	comeUpWithIdea(size_t idx, const std::string& idea);
	void	rememberIdea(size_t idx) const;

private:
	Brain*	brain;
};

#endif
