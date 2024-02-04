#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "Colors.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name_(name) {
	std::cout << Colors::CYAN << "The DiamondTrap constructor will be called" << Colors::RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ScavTrap(diamondtrap), FragTrap(diamondtrap) {
	std::cout << Colors::CYAN << "The DiamondTrap copy constructor will be called" << Colors::RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << Colors::CYAN << "The DiamondTrap destructor will be called" << Colors::RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& diamondtrap) {
	ScavTrap::operator=(diamondtrap);
	FragTrap::operator=(diamondtrap);
	this->name_ = diamondtrap.name_;
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << Colors::WHITE << "ClapTrap: I am " << ScavTrap::name_ << Colors::RESET << std::endl;
	std::cout << Colors::WHITE << "DiamondTrap: I am " << name_ << Colors::RESET << std::endl;
}
