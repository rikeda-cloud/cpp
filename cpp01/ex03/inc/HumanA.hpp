#ifndef CPP01_EX03_HumanA_H_
# define CPP01_EX03_HumanA_H_

#include "Weapon.hpp"
#include <string>

class	HumanA {
private:
	std::string	name_;
	Weapon&		weapon_;

public:
	HumanA(std::string name, Weapon& weapon);
	HumanA(const HumanA&);
	~HumanA(void);
	HumanA&	operator=(const HumanA&);

	void	attack(void);
};

#endif
