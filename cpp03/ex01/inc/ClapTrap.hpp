#ifndef CPP03_EX01_ClapTrap_H_
# define CPP03_EX01_ClapTrap_H_

#include <string>

class ClapTrap {
public:
	ClapTrap(std::string name);
	virtual ~ClapTrap(void);
	ClapTrap(const ClapTrap&);
	ClapTrap&	operator=(const ClapTrap&);

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	static const unsigned int	HIT_POINT = 10;
	static const unsigned int	ENERGY_POINT = 10;
	static const unsigned int	ATTACK_DAMAGE = 0;

protected:
	std::string		name_;
	unsigned int	hit_point_;
	unsigned int	energy_point_;
	unsigned int	attack_damage_;

private:
	ClapTrap(void);
};

#endif
