#include "Replacer.hpp"

void	Replacer::Replace(
		std::string& string,
		const std::string& from,
		const std::string& to) {
	size_t		idx = 0;

	if (from.length() == 0)
		return ;
	while ((idx = string.find(from, idx)) != std::string::npos) {
		string.erase(idx, from.length());
		string.insert(idx, to);
		idx += to.length();
	}
}
