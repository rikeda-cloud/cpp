#ifndef CPP01_EX01_Zombie_H_
# define CPP01_EX01_Zombie_H_

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
	void	SetName(std::string);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
