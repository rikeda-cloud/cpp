#include "Input.hpp"
#include <iostream>

bool	Input::IsSpaceString(std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (std::isspace(str[i]) == 0)
			return false;
	}
	return true;
}

std::string	Input::InputString(const std::string& prompt) {
	std::string buffer;

	std::cout << prompt << std::flush;
	while (std::getline(std::cin, buffer)) {
		if (!IsSpaceString(buffer))
			break ;
		std::cout << prompt << std::flush;
	}
	return buffer;
}

size_t	Input::InputIndex(const std::string& prompt, size_t max_idx) {
	size_t	idx;

	std::cout << prompt << std::flush;
	while (!(std::cin >> idx) || !(1 <= idx && idx <= max_idx)) {
		if (std::cin.eof())
			return 0;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << prompt << std::flush;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return idx;
}
