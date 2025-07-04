#ifndef CPP03_EX00_Colors_H_
# define CPP03_EX00_Colors_H_

#include <string>

class Colors {
public:
	static const std::string RESET;
	static const std::string RED;
	static const std::string YELLOW;
	static const std::string BLUE;
	static const std::string MAGENTA;
	static const std::string WHITE;
	static const std::string GREEN;
	static const std::string CYAN;

private:
	Colors(void);
	Colors(const Colors&);
	~Colors(void);
	void	operator=(const Colors&);
};

#endif
