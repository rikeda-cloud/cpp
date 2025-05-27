#ifndef CPP04_EX02_WrongAnimal_H_
# define CPP04_EX02_WrongAnimal_H_

#include <string>

class WrongAnimal {
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal&);
	~WrongAnimal(void);
	WrongAnimal&	operator=(const WrongAnimal&);

	void		makeSound(void) const;
	std::string	getType(void) const;

protected:
	std::string	type;
};

#endif
