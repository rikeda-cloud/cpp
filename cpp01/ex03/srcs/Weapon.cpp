#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : type(weapon_type){}

Weapon::Weapon(const Weapon& weapon) : type(weapon.getType()) {}

Weapon::~Weapon(void) {}

Weapon&	Weapon::operator=(const Weapon& weapon) {
	if (this != &weapon)
		this->type = weapon.getType();
	return *this;
}

const std::string&	Weapon::getType(void) const {
	return type;
}

void	Weapon::setType(std::string weapon_type) {
	type = weapon_type;
}
