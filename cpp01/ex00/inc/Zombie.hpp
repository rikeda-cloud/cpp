#ifndef CPP01_EX00_Zombie_H_
# define CPP01_EX00_Zombie_H_

#include <string>

class	Zombie {
private:
	std::string	name;

public:
	Zombie(void);
	Zombie(std::string);
	Zombie(const Zombie&);
	~Zombie(void);
	Zombie&	operator=(const Zombie&);

	void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
