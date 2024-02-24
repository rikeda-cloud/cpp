#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "Colors.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
	:	ClapTrap(name),
		ScavTrap(name),
		FragTrap(name),
		name_(name) {
	ClapTrap::name_ = name + std::string("_clap_name");
	hit_point_ = FragTrap::HIT_POINT;
	energy_point_ = ScavTrap::ENERGY_POINT;
	attack_damage_ = FragTrap::ATTACK_DAMAGE;
	std::cout << Colors::CYAN << "DiamondTrap constructor called" << Colors::RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap)
	:	ClapTrap(diamondtrap),
		ScavTrap(diamondtrap),
		FragTrap(diamondtrap) {
	std::cout << Colors::CYAN << "DiamondTrap copy constructor called" << Colors::RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << Colors::CYAN << "DiamondTrap destructor called" << Colors::RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& diamondtrap) {
	if (this != &diamondtrap) {
		ClapTrap::operator=(diamondtrap);
		ScavTrap::operator=(diamondtrap);
		FragTrap::operator=(diamondtrap);
		this->name_ = diamondtrap.name_;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << Colors::WHITE << "ClapTrap: I am " << ClapTrap::name_ << Colors::RESET << std::endl;
	std::cout << Colors::WHITE << "DiamondTrap: I am " << this->name_ << Colors::RESET << std::endl;
}
