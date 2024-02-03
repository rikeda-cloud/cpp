#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name_(name) {
	ScavTrap::hit_point_ = FragTrap::hit_point_;
	FragTrap::energy_point_ = ScavTrap::energy_point_;
	ScavTrap::attack_damage_ = FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ScavTrap(diamondtrap), FragTrap(diamondtrap) {
}

DiamondTrap::~DiamondTrap(void) {
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
