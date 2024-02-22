#include "Replacer.hpp"
#include "InFileReader.hpp"
#include "OutFileReader.hpp"

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

void	Replacer::Replace(
			InFileReader* in_reader,
			OutFileReader* out_reader,
			const std::string& from,
			const std::string& to) {
	std::string	all_chars = in_reader->GetAllChars();
	Replacer::Replace(all_chars, from, to);
	out_reader->Save(all_chars);
}
