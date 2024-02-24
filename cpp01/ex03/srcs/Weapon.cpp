#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : type(weapon_type) {}

Weapon::Weapon(const Weapon& weapon) : type(weapon.type) {}

Weapon::~Weapon(void) {}

Weapon&	Weapon::operator=(const Weapon& weapon) {
	if (this != &weapon)
		this->type = weapon.type;
	return *this;
}

const std::string&	Weapon::getType(void) const {
	return type;
}

void	Weapon::setType(std::string weapon_type) {
	this->type = weapon_type;
}
