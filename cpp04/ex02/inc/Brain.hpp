#ifndef CPP04_EX02_Brain_H_
# define CPP04_EX02_Brain_H_

#include <string>

class Brain {
private:
	std::string	ideas[100];

public:
	Brain(void);
	Brain(const Brain&);
	~Brain(void);
	Brain&	operator=(const Brain&);
};

#endif
