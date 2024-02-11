#ifndef CPP03_EX02_ClapTrap_H_
# define CPP03_EX02_ClapTrap_H_

#include <string>

class ClapTrap {
protected:
	std::string		name_;
	unsigned int	hit_point_;
	unsigned int	energy_point_;
	unsigned int	attack_damage_;

	ClapTrap(void);

public:
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap&);
	ClapTrap&		operator=(const ClapTrap&);

	void			attack(const std::string& target);
	void			takeDamege(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string&	getName(void);
};

#endif
