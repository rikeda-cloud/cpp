#include "Input.hpp"
#include <iostream>

Input::Input(void) {}

Input::Input(const Input& input) {(void)input;}

Input::~Input(void) {}

void	Input::operator=(const Input& input) {(void)input;}

bool	Input::IsIntendedString(const std::string& str, int (*f)(int)) {
	if (str.size() == 0)
		return false;
	for (size_t i = 0; i < str.size(); i++) {
		if (f(str[i]) == 0)
			return false;
	}
	return true;
}

std::string	Input::InputString(const char *prompt, int (*f)(int)) {
	std::string	buffer;

	std::cout << prompt << std::flush;
	while (std::getline(std::cin, buffer)) {
		if (IsIntendedString(buffer, f))
			break ;
		std::cout << prompt << std::flush;
	}
	return buffer;
}

size_t	Input::InputIndex(const char *prompt, size_t max_idx) {
	size_t		idx;
	std::string	buffer;

	while (true) {
		buffer = InputString(prompt, std::isdigit);
		if (std::cin.eof())
			return 0;
		else if (buffer.size() == 1) {
			idx = buffer[0] - '0';
			if (1 <= idx && idx <= max_idx)
				break ;
		}
	}
	return idx;
}
