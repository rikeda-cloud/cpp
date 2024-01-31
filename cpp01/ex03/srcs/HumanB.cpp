#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL){
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
