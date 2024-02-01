#ifndef CPP01_EX05_H_
# define CPP01_EX05_H_

#include <string>


class Harl {
public:
	typedef void	(*harl_func_ptr)();
private:
	Harl::harl_func_ptr	_select_level(std::string level);
public:
	Harl(void);
	static void	debug(void);
	static void	info(void);
	static void	warning(void);
	static void	error(void);
	void	complain(std::string level);
};

class HarlPair {
private:
	std::string			key_;
	Harl::harl_func_ptr	value_;
public:
	HarlPair(void);
	HarlPair(std::string, Harl::harl_func_ptr);
	void					set(std::string, Harl::harl_func_ptr);
	const std::string		getKey(void);
	Harl::harl_func_ptr		getValue(void);
};

class HarlDict {
private:
	int			size_;
	HarlPair	*dict_;
public:
	HarlDict(void);
	~HarlDict(void);
	void		append(std::string, Harl::harl_func_ptr);
	int			size(void);
	HarlPair	*getHarlPair(int idx);
};

#endif
