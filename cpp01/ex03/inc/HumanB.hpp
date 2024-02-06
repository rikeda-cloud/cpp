#ifndef CPP01_EX03_HumanB_H_
# define CPP01_EX03_HumanB_H_

#include "Weapon.hpp"
#include <string>

class	HumanB {
private:
	std::string	name_;
	Weapon		*weapon_;

public:
	HumanB(std::string name);
	HumanB(const HumanB&);
	~HumanB(void);
	HumanB&	operator=(const HumanB&);

	void	attack(void);
	void	setWeapon(Weapon &new_weapon);
};

#endif
