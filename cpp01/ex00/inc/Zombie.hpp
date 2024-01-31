#ifndef CPP01_EX00_Zombie_H_
# define CPP01_EX00_Zombie_H_

#include <string>

class	Zombie {
private:
	std::string	name;

public:
	Zombie(std::string zombie_name);
	~Zombie(void);
	void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
