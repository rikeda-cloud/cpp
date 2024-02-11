#ifndef CPP03_EX03_FragTrap_H_
# define CPP03_EX03_FragTrap_H_

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
private:
	FragTrap(void);

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap&);
	~FragTrap(void);
	FragTrap&	operator=(const FragTrap&);

	void		highFivesGuys(void);

	static const unsigned int	HIT_POINT = 100;
	static const unsigned int	ENERGY_POINT = 100;
	static const unsigned int	ATTACK_DAMAGE = 30;
};

#endif
