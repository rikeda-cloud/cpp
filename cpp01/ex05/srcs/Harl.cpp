#include "Harl.hpp"
#include "Colors.hpp"
#include <iostream>
#include <cstddef>

const std::string Colors::RESET = "\033[0m";
const std::string Colors::RED = "\033[31m";
const std::string Colors::YELLOW = "\033[33m";
const std::string Colors::BLUE = "\033[34m";
const std::string Colors::MAGENTA = "\033[35m";
const std::string Colors::WHITE = "\033[37m";

Harl::Harl(void) {
	f_list_[0] = &Harl::debug;
	f_list_[1] = &Harl::info;
	f_list_[2] = &Harl::warning;
	f_list_[3] = &Harl::error;
	level_list_[0] = "DEBUG";
	level_list_[1] = "INFO";
	level_list_[2] = "WARNING";
	level_list_[3] = "ERROR";
}

Harl::Harl(const Harl& harl) {
	f_list_[0] = harl.f_list_[0];
	f_list_[1] = harl.f_list_[1];
	f_list_[2] = harl.f_list_[2];
	f_list_[3] = harl.f_list_[3];
	level_list_[0] = harl.level_list_[0];
	level_list_[1] = harl.level_list_[1];
	level_list_[2] = harl.level_list_[2];
	level_list_[3] = harl.level_list_[3];
}

Harl::~Harl(void) {}

Harl&	Harl::operator=(const Harl& harl) {
	if (this != &harl) {
		f_list_[0] = harl.f_list_[0];
		f_list_[1] = harl.f_list_[1];
		f_list_[2] = harl.f_list_[2];
		f_list_[3] = harl.f_list_[3];
		level_list_[0] = harl.level_list_[0];
		level_list_[1] = harl.level_list_[1];
		level_list_[2] = harl.level_list_[2];
		level_list_[3] = harl.level_list_[3];
	}
	return *this;
}

void	Harl::debug(void) {
	std::cout << Colors::BLUE << "[ DEBUG ]" << Colors::RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void) {
	std::cout << Colors::WHITE << "[ INFO ]" << Colors::RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void) {
	std::cout << Colors::YELLOW << "[ WARNING ]" << Colors::RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void) {
	std::cout << Colors::RED << "[ ERROR ]" << Colors::RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int	Harl::LevelToIndex(std::string& level) {
	for (int i = 0; i < 4; i++) {
		if ((this->level_list_[i]) == level)
			return i;
	}
	return -1;
}

void	Harl::complain(std::string level) {
	int	index = LevelToIndex(level);

	if (index != -1)
		(this->*(f_list_[index]))();
	else
		std::cerr
			<< Colors::MAGENTA
			<< "\""
			<< level
			<< "\""
			<< " is not in harl levels"
			<< Colors::RESET
			<< std::endl
			<< std::endl;
}
