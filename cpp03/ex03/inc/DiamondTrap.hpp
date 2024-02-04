#ifndef CPP03_EX03_DiamondTrap_H_
# define CPP03_EX03_DiamondTrap_H_

#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string		name_;
	unsigned int	hit_point_;
	unsigned int	energy_point_;
	unsigned int	attack_damage_;

public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap&);
	~DiamondTrap(void);
	DiamondTrap&	operator=(const DiamondTrap&);
	void			whoAmI(void);
	void			attack(const std::string& target);
};

#endif
