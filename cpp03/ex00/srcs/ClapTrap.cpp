#include "ClapTrap.hpp"
#include "Colors.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name_(name), hit_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << Colors::CYAN << "The ClapTrap constructor will be called" << Colors::RESET << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << Colors::WHITE << "The ClapTrap destructor will be called" << Colors::RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap) {
	*this = claptrap;
	std::cout << Colors::CYAN << "The ClapTrap copy constructor will be called" << Colors::RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& claptrap) {
	this->name_ = claptrap.name_;
	this->hit_point_ = claptrap.hit_point_;
	this->energy_point_ = claptrap.energy_point_;
	this->attack_damage_ = claptrap.attack_damage_;
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << getName() << " is already dead" << Colors::RESET << std::endl;
	else if (energy_point_ == 0)
		std::cout << Colors::MAGENTA << "No energy point" << Colors::RESET << std::endl;
	else {
		energy_point_--;
		std::cout << Colors::BLUE << "ClapTrap " << getName() << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << Colors::RESET << std::endl;
	}
}

void	ClapTrap::takeDamege(unsigned int amount) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << getName() << " is already dead" << Colors::RESET << std::endl;
	else {
		std::cout << Colors::RED << getName() << " take damege " << amount << " points of damage!" << Colors::RESET << std::endl;
		hit_point_ = hit_point_ < amount ? 0 : hit_point_ - amount;
		if (hit_point_ == 0)
			std::cout << Colors::MAGENTA << getName() << " is dead" << Colors::RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << getName() << " is already dead" << Colors::RESET << std::endl;
	else if (energy_point_ == 0)
		std::cout << Colors::MAGENTA << "No energy point" << Colors::RESET << std::endl;
	else {
		energy_point_--;
		std::cout << Colors::GREEN << getName() << " repaired " << amount << " points of damage!" << Colors::RESET << std::endl;
		hit_point_ += amount;
	}
}

std::string&	ClapTrap::getName(void) {
	return name_;
}
