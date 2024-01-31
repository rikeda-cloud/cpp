#ifndef CPP01_EX03_HumanB_H_
# define CPP01_EX03_HumanB_H_

#include <string>
#include "Weapon.hpp"

class	HumanB {
private:
	std::string	name_;
	Weapon		*weapon_;

public:
	HumanB(std::string name);
	void	attack(void);
	void	setWeapon(Weapon &new_weapon);
};

#endif
