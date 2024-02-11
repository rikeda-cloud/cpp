#ifndef CPP04_EX00_Animal_H_
# define CPP04_EX00_Animal_H_

#include <string>

class Animal {
protected:
	std::string	type;

public:
	Animal(void);
	Animal(const Animal&);
	virtual	~Animal(void);
	Animal&		operator=(const Animal&);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif
