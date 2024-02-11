#ifndef CPP03_EX01_ScavTrap_H_
# define CPP03_EX01_ScavTrap_H_

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
private:
	ScavTrap(void);

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap&);
	~ScavTrap(void);
	ScavTrap&	operator=(const ScavTrap&);

	void		attack(const std::string& target);
	void		guardGate(void);

	static const unsigned int	HIT_POINT = 100;
	static const unsigned int	ENERGY_POINT = 50;
	static const unsigned int	ATTACK_DAMAGE = 20;
};

#endif
