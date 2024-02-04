#ifndef CPP04_EX01_Animal_H_
# define CPP04_EX01_Animal_H_

#include <string>

class Animal {
protected:
	std::string	type;

public:
	Animal(void);
	Animal(const Animal&);
	virtual		~Animal(void) = 0;
	Animal&		operator=(const Animal&);
	virtual void		makeSound(void) const = 0;
	virtual std::string	getType(void) const = 0;
};

#endif
