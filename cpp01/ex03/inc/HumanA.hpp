#ifndef CPP01_EX03_HumanA_H_
# define CPP01_EX03_HumanA_H_

#include <string>
#include "Weapon.hpp"

class	HumanA {
private:
	std::string	name_;
	Weapon&		weapon_;

public:
	HumanA(std::string name, Weapon& weapon);
	void	attack(void);
};

#endif
