#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

HumanB::HumanB(const HumanB& human) : name_(human.name_), weapon_(human.weapon_) {}

HumanB::~HumanB(void) {}

HumanB&	HumanB::operator=(const HumanB& human) {
	if (this != &human) {
		this->name_ = human.name_;
		this->weapon_ = human.weapon_;
	}
	return *this;
}

void	HumanB::attack(void) {
	std::cout << name_ << " attacks with their ";
	if (weapon_ != NULL)
		std::cout << weapon_->getType();
	else
		std::cout << "bare hands";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& new_weapon) {
	weapon_ = &new_weapon;
}
