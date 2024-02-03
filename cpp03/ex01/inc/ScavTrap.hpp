#ifndef CPP03_EX01_ScavTrap_H_
# define CPP03_EX01_ScavTrap_H_

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap&);
	~ScavTrap(void);
	ScavTrap&	operator=(const ScavTrap&);
	void		guardGate(void);
};

#endif
