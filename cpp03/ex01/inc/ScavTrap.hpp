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
};

#endif
