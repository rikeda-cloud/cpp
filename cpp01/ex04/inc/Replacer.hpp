#ifndef CPP01_EX04_Replacer_H_
# define CPP01_EX04_Replacer_H_

#include "InFileReader.hpp"
#include "OutFileReader.hpp"
#include <string>

class Replacer {
public:
	static void	Replace(
		std::string& string,
		const std::string& from,
		const std::string& to
	);

	static bool	Replace(
		InFileReader*,
		OutFileReader*,
		const std::string& from,
		const std::string& to
	);

private:
	Replacer(void);
	Replacer(const Replacer&);
	~Replacer(void);
	void	operator=(const Replacer&);
};

#endif
