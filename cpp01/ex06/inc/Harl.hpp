#ifndef CPP01_EX06_Harl_H_
# define CPP01_EX06_Harl_H_

#include <string>

class Harl {
public:
	static const int	LEVEL_SIZE = 4;

	Harl(void);
	Harl(const Harl&);
	~Harl(void);
	Harl&	operator=(const Harl&);
	
	void	complain(std::string level);

private:
	void		(Harl::*method_array_[LEVEL_SIZE])(void);
	std::string	level_string_array_[LEVEL_SIZE];

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	int		levelToIndex(const std::string&) const;
};

#endif
