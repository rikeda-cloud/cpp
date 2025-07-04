#ifndef CPP01_EX03_Weapon_H_
# define CPP01_EX03_Weapon_H_

#include <string>

class Weapon {
public:
	Weapon(std::string weapon_type);
	Weapon(const Weapon&);
	~Weapon(void);
	Weapon&	operator=(const Weapon&);

	const std::string&	getType(void) const;
	void				setType(std::string weapon_type);

private:
	std::string	type;
	Weapon(void);
};

#endif
