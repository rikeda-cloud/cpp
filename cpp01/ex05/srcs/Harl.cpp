#include "Harl.hpp"
#include "Colors.hpp"
#include <iostream>


const std::string Colors::RESET = "\033[0m";
const std::string Colors::RED = "\033[31m";
const std::string Colors::YELLOW = "\033[33m";
const std::string Colors::BLUE = "\033[34m";
const std::string Colors::WHITE = "\033[37m";

Harl::Harl(void) {
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

void	Harl::complain(std::string level) {
	HarlDict	dict;
	dict.append("DEBUG", Harl::debug);
	dict.append("INFO", Harl::info);
	dict.append("WARNING", Harl::warning);
	dict.append("ERROR", Harl::error);

	for (int i = 0; i < dict.size(); i++) {
		if (dict.getHarlPair(i)->getKey() == level) {
			dict.getHarlPair(i)->getValue()();
			break ;
		}
	}
}
