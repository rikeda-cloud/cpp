#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL){}

HumanB::HumanB(const HumanB& humanb) : name_(humanb.name_), weapon_(humanb.weapon_) {}

HumanB::~HumanB(void) {}

HumanB&	HumanB::operator=(const HumanB& humanb) {
	if (this != &humanb) {
		this->name_ = humanb.name_;
		this->weapon_ = humanb.weapon_;
	}
	return *this;
}

void	HumanB::attack(void) {
	std::cout << name_ << " attacks with their ";
	if (weapon_)
		std::cout << weapon_->getType();
	else
		std::cout << "bare hands";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& new_weapon) {
	weapon_ = &new_weapon;
}
