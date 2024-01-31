#include <string>

class	Zombie {
private:
	std::string	name;

public:
	Zombie(void);
	Zombie(std::string zombie_name);
	~Zombie(void);
	void	announce(void);
	void	SetName(std::string);
};

Zombie*	zombieHorde(int N, std::string name);
