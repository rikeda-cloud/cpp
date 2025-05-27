#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name_(name), weapon_(weapon) {}

HumanA::HumanA(const HumanA& human) : name_(human.name_), weapon_(human.weapon_) {}

HumanA::~HumanA(void) {}

HumanA&	HumanA::operator=(const HumanA& human) {
	if (this != &human) {
		this->name_ = human.name_;
		this->weapon_ = human.weapon_;
	}
	return *this;
}

void	HumanA::attack(void) {
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
