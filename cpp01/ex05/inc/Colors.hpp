#ifndef CPP01_EX05_Colors_H_
# define CPP01_EX05_Colors_H_

#include <string>

class Colors {
public:
	static const std::string RESET;
	static const std::string RED;
	static const std::string YELLOW;
	static const std::string BLUE;
	static const std::string MAGENTA;
	static const std::string WHITE;

private:
	Colors(void);
	Colors(const Colors&);
	~Colors(void);
	void	operator=(const Colors&);
};

#endif
