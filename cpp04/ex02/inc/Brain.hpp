#ifndef CPP04_EX02_Brain_H_
# define CPP04_EX02_Brain_H_

#include <string>

class Brain {
public:
	Brain(void);
	Brain(const Brain&);
	~Brain(void);
	Brain&	operator=(const Brain&);

	const std::string*	getIdea(size_t idx) const;
	void				setIdea(size_t idx, const std::string& new_idea);

private:
	static const size_t	IDEAS_MAX = 100;
	std::string	ideas[IDEAS_MAX];
};

#endif
