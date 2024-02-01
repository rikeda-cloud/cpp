#include "Harl.hpp"

HarlDict::HarlDict(void) : size_(0) {
}

HarlDict::~HarlDict(void) {
	if (size_ != 0)
		delete[] dict_;
}

void	HarlDict::append(std::string key, Harl::harl_func_ptr value) {
	HarlPair	*new_dict = new HarlPair[size_ + 1];

	for (int i = 0; i < size_; i++)
		new_dict[i].set(dict_[i].getKey(), dict_[i].getValue());
	new_dict[size_].set(key, value);
	if (size_ != 0)
		delete[] dict_;
	dict_ = new_dict;
	size_++;
}

int	HarlDict::size(void) {
	return size_;
}

HarlPair	*HarlDict::getHarlPair(int idx) {
	return &dict_[idx];
}
