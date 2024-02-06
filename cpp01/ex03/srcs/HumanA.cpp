#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name_(name), weapon_(weapon) {}

HumanA::HumanA(const HumanA& humana) : name_(humana.name_), weapon_(humana.weapon_) {}

HumanA::~HumanA(void) {}

HumanA&	HumanA::operator=(const HumanA& humana) {
	if (this != &humana) {
		this->name_ = humana.name_;
		this->weapon_ = humana.weapon_;
	}
	return *this;
}

void	HumanA::attack(void) {
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
