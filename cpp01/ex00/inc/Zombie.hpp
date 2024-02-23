#ifndef CPP01_EX00_Zombie_H_
# define CPP01_EX00_Zombie_H_

#include <string>

class	Zombie {
public:
	Zombie(void);
	Zombie(const Zombie&);
	~Zombie(void);
	Zombie&	operator=(const Zombie&);

	void	announce(void);
	void	setName(std::string);

private:
	std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
