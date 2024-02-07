#ifndef CPP01_EX05_Harl_H_
# define CPP01_EX05_Harl_H_

#include <string>

class Harl {
private:
	void		(Harl::*f_list_[4])(void);
	std::string	level_list_[4];

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	int		LevelToIndex(std::string&);

public:
	Harl(void);
	Harl(const Harl&);
	~Harl(void);
	Harl&	operator=(const Harl&);
	
	void	complain(std::string level);
};

#endif
