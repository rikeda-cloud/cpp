#include "Harl.hpp"

HarlPair::HarlPair(void) : key_(), value_(NULL) {
}

HarlPair::HarlPair(std::string key, void (*value)(void)) : key_(key), value_(value) {
}

void	HarlPair::set(std::string key, Harl::harl_func_ptr value) {
	key_ = key;
	value_ = value;
}

const std::string	HarlPair::getKey(void) {
	return key_;
}

Harl::harl_func_ptr	HarlPair::getValue(void) {
	return value_;
}
