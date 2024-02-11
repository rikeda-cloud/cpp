#ifndef CPP04_EX01_WrongAnimal_H_
# define CPP04_EX01_WrongAnimal_H_

#include <string>

class WrongAnimal {
protected:
	std::string	type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal&);
	~WrongAnimal(void);
	WrongAnimal&	operator=(const WrongAnimal&);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
