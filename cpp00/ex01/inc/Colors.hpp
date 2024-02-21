#ifndef CPP00_EX01_Colors_H_
# define CPP00_EX01_Colors_H_

#include <string>

class Colors {
public:
	static const std::string RESET;
	static const std::string MAGENTA;
	static const std::string GREEN;

private:
	Colors(void);
	Colors(const Colors&);
	~Colors(void);
	void	operator=(const Colors&);
};

#endif
