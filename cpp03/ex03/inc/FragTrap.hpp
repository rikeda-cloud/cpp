#ifndef CPP03_EX03_FragTrap_H_
# define CPP03_EX03_FragTrap_H_

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap&);
	~FragTrap(void);
	FragTrap&	operator=(const FragTrap&);
	void		highFivesGuys(void);
};

#endif
