#include "Replacer.hpp"
#include "InFileReader.hpp"
#include "OutFileReader.hpp"

void	Replacer::replace(
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

bool	Replacer::replace(
			InFileReader* in_reader,
			OutFileReader* out_reader,
			const std::string& from,
			const std::string& to) {
	std::string	all_chars = in_reader->getAllChars();
	if (in_reader->isFail())
		return true;
	Replacer::replace(all_chars, from, to);
	out_reader->save(all_chars);
	return out_reader->isFail();
}
