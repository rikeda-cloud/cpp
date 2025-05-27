#ifndef CPP03_EX03_DiamondTrap_H_
# define CPP03_EX03_DiamondTrap_H_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap&);
	~DiamondTrap(void);
	DiamondTrap&	operator=(const DiamondTrap&);

	void	whoAmI(void);
	void	attack(const std::string& target);

private:
	std::string	name_;
	DiamondTrap(void);
};

#endif
